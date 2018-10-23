#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 30
typedef char bitElemtype;
typedef struct Node{
	bitElemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;
typedef BiTree Elemtype;

typedef struct{
	Elemtype date[MAXSIZE];
	int front,rear; 
}CSeQeue;
//��ʼ��
CSeQeue *InitSeQueue(){
	CSeQeue *qS;
	qS=(CSeQeue *)malloc(sizeof(CSeQeue));
	qS->rear=qS->front=MAXSIZE-1;
	return qS;
}
//���
int InSeQueue(CSeQeue *qS ,Elemtype x){
	
	if((qS->rear+1)%MAXSIZE==qS->front){
		printf("����\n");
		return FALSE;
	}
	qS->rear=(qS->rear+1)%MAXSIZE;
	qS->date[qS->rear]=x;
	return TRUE;
} 
//�п�
int EmptySeQueue(CSeQeue *qS){
	
	if(qS->front == qS->rear)
		return TRUE;
	return FALSE;
} 
//���� 
int QutSeQueue(CSeQeue *qS ,Elemtype *x){
	if(!EmptySeQueue(qS)){
		qS->front=(qS->front+1)%MAXSIZE;
		*x = qS->date[qS->front];
		return TRUE;
	}
	printf("�ӿ�\n");
	return FALSE; 
} 
char str[50];
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
void levelOrder(BiTree root){
	BiTree p=root;
	CSeQeue *S;
	S=InitSeQueue();
	InSeQueue(S,p);
	while(!EmptySeQueue(S)){
		QutSeQueue(S,&p);
		printf("%c",p->data);
		if(p->lChild!=NULL)
			InSeQueue(S,p->lChild);
		if(p->rChild!=NULL)
			InSeQueue(S,p->rChild);
	}
}

int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);
	levelOrder(root);
	printf("\n"); 
}