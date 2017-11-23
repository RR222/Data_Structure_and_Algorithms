#include <stdio.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[50];
int countA,countB,countC;
BiTree CreatBiTree(BiTree root){  //�������Ľ���(����չ���������н����Ķ�����) 
	static int count;
	char ch=str[count];
	count++;
	if(ch=='#')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ� 
	root->rChild = CreatBiTree(root->rChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ�	
	return root;
}
void CountTwoOrder(BiTree root){  //Ѱ�Ҷ�Ϊ2�Ľڵ� 
	if(root==NULL)
		return;
	if(root->lChild==NULL&&root->rChild==NULL)
		countA++;	
	if(root->lChild!=NULL&&root->rChild==NULL||root->lChild==NULL&&root->rChild!=NULL)
		countB++;
	if(root->lChild!=NULL&&root->rChild!=NULL)
		countC++; 
	CountTwoOrder(root->lChild);
	CountTwoOrder(root->rChild);
	return;
}

void PreOrder(BiTree root){
	int static count;
	if(root==NULL)
		return;
	if(root->lChild==NULL&&root->rChild==NULL)	
		printf("%c",root->data);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
}
int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);
	CountTwoOrder(root);
	printf("%d %d %d\n",countA,countB,countC);
	PreOrder(root);
	
	printf("\n"); 
}