#include <stdio.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[]="ABC^D^^E^^FCK^^^H^M^^";
BiTree CreatBiTree(BiTree root){  //�������Ľ���(����չ���������н����Ķ�����) 
	static int count;
	char ch=str[count];
	count++;
	if(ch=='^')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ� 
	root->rChild = CreatBiTree(root->rChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ�	
	return root;
}
int CountTwoOrder(BiTree root){  //Ѱ�Ҷ�Ϊ2�Ľڵ� 
	int static count;
	if(root==NULL)
		return;
	if(root->lChild!=NULL&&root->rChild!=NULL)
		count++;	
	printf("%c",root->data);
	CountTwoOrder(root->lChild);
	CountTwoOrder(root->rChild);
	return count;
}
void exchange(BiTree root){     //�������ڵ���������� 
	BiTree t;
	if(root==NULL)
		return;
	t=root->lChild;
	root->lChild=root->rChild;
	root->rChild=t;
	exchange(root->lChild);
	exchange(root->rChild);
}
void PreOrder(BiTree root){    //�����������Ӳ�� 
	int static count;
	if(root==NULL)
		return;
	count++;	
	printf("(%c,%d)",root->data,count);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
	count--;
}
int main(void){
	BiTree root;
	root=CreatBiTree(root);
	printf("\n��Ϊ2�Ľڵ��У�%d\n",CountTwoOrder(root));
	exchange(root);
	PreOrder(root);
	printf("\n"); 
}