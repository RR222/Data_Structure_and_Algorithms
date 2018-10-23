#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50
#define TRUE 1
#define FALSE 0 
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

typedef BiTree SeqElemtype;
typedef struct
{
	SeqElemtype data[MAXSIZE]; 
	int top; 
}SeqStack; 
//�½�һ����ջ
SeqStack *InitStack (){
	 
	SeqStack *S;
	S=malloc(sizeof(SeqStack));
	 
	S->top =-1; 
	return S;
}


//�ж��Ƿ�Ϊ��ջ 
int StackEmpty (SeqStack *S){
	if(S->top==-1)
		return TRUE;
	else 
		return FALSE; 
} 

//��ջ
int Push (SeqStack *S,SeqElemtype e){
	if(S->top==MAXSIZE-1) 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ������ 
int Pop (SeqStack *S,SeqElemtype *e){
	if(S->top == -1) 
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,SeqElemtype *e){
	if(S->top == -1) 
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
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

void PostOrder(BiTree root){
	BiTree p,q;
	SeqStack *S;
	S = InitStack();
	q = NULL;
	p = root;
	while(p!=NULL||StackEmpty(S)==0){
		while(p!=NULL){ //��ѭ��ʱp������Ϊ�� 
			Push(S,p); //��ջ  
			p=p->lChild; //���������� 
		}
		if(StackEmpty(S)==0){
			GetTop(S,&p);
			if(p->rChild==NULL||p->rChild==q){ //���ջ��Ԫ��p������Ϊ�գ�������һ������������������� 
				Pop(S,&p);
				printf("%c",p->data);
				q=p;
				p=NULL; 
			}else{ //�����һ��������ջ��Ԫ�ص������� 
				p=p->rChild;
			}
		}
	
	}
	
} 
int main(void){
	BiTree root;
	gets(str);
	root=CreatBiTree(root);	
	PostOrder(root); 
	printf("\n");
}