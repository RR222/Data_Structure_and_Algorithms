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
char  array[20];
void PreOrder(BiTree root){    //�����������Ӳ�� 
	int static count;
	
	int i;
	if(root==NULL)
		return;
	count++;	
	if(root->lChild==NULL&&root->rChild==NULL){
		printf("%c:",root->data);
		
		for(i=1;i<count;i++){
			printf("%c",array[i]);
		}
			
		printf("\n");
	}else{
		array[count]=root->data;
	}
	PreOrder(root->lChild);
	PreOrder(root->rChild);
	count--;
}
int main(void){
	BiTree root;
	int k;
	gets(str);
	root=CreatBiTree(root);
	PreOrder(root);
	printf("\n"); 
}