#include <stdio.h>
typedef int Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[];
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

int f1(BiTree root,int k){   
	int static countlevel;
	int static countleaf;
	if(root==NULL)
		return;
	countlevel++;	
	if(countlevel == k&&root->lChild==NULL&&root->rChild==NULL)
		countleaf++;
	f1(root->lChild,k);
	f1(root->rChild,k);
	countlevel--;
	return countleaf;
}
int main(void){
	BiTree root;
	int k;
	gets(str);
	scanf("%d",&k); 
	root=CreatBiTree(root);
	printf("%d",f1(root,k));
	printf("\n"); 
}