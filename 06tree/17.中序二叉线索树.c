#include <stdio.h>
#include <stdlib.h>
typedef enum {Link,Thread} PointerTag;//Link== 0 ��ʾָ�����Һ��ӵĽڵ㡣
                                      //Therad == 1��ʾָ��ǰ�����ߺ��
typedef char Elemtype;				
typedef struct BithrNode{ //���������ڵ�ṹ 
	Elemtype data;
	struct BithrNode *lchild,*rchild;//���Һ���ָ��
	PointerTag LTag; 
	PointerTag RTag; 
}BiThrNode,*BiThrTree;

char str[]="ABD^G^^^CE^^F^^";

BiThrTree CreatBiThrTree(BiThrTree	root){ //���������� 
	static int count;
	char ch = str[count];
	count++; 
	if(ch == '^')
		return NULL;
	
	root = (BiThrNode *)malloc(sizeof(BiThrNode));
	root->data = ch;
	root->LTag= Link;
	root->lchild = CreatBiThrTree(root->lchild);
 	root->RTag =Link;
 	root->rchild = CreatBiThrTree(root->rchild);
 	
 	return root; 
	
} 
BiThrNode *p; // ��¼ǰ���ڵ� 
void InThreading (BiThrTree root){
	if(root==NULL)
		return;

	InThreading(root->lchild);//�ݹ��������������� 
	if(root->lchild==NULL){
		root->LTag =Thread;
		root->lchild = p; // ����ָ��ǰ�� 
	} 
	if(p!=NULL&&p->rchild == NULL){
		p->RTag = Thread;
		p->rchild = root;//ǰ��ָ����ڵ� 
	} 
	p = root; // ����ǰ�� 
	InThreading(root->rchild);//�ݹ��������������� 
}
void InOrderTraverse_Thr(BiThrTree root){
	
	BiThrNode *p;
	p=root->lchild;// pΪ��������
	while(p!=NULL) // �������߱������� p == T
	{
		while(p->LTag == Link) //�ҵ��������еĵ�һ���ڵ� 
			p = p ->lchild;
		printf("%c",p->data);
		while(p->RTag==Thread && p->rchild !=NULL){
			p = p->rchild;
			printf("%c",p->data);
		} 
		p= p->rchild; 	
		
	} 
}
int main(void){
	BiThrTree root;
	root=CreatBiThrTree(root);//���������� 
	InThreading(root);
	InOrderTraverse_Thr(root);//ʹ����������������������� 
 
}