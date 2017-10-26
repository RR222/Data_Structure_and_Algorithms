#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0 
typedef int Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE]; 
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
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1) 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ������ 
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 

	    
//ȡ��ջ��Ԫ�� 
int GetTop (SeqStack *S,Elemtype *e){
	if(S->top == -1) 
		return FALSE;
	else{
		*e=S->data[S->top];	
		return TRUE;
	}
} 


//���ػ�ջS��Ԫ�ظ�����
int StackLength (SeqStack *S){
	return S->top +1;
} 

int main(void){
	SeqStack *S;
	int x,y,z;
	S=InitStack();//����ջ
	printf("%d ",S->top);
	printf("%d %d\n",StackEmpty(S),S->top);//�ж��Ƿ�Ϊ��
	printf("%d %d %d\n",Push(S,1),Push(S,2),S->top);//��ջ���ж��Ƿ�ɹ�
	printf("%d %d %d\n",Pop(S,&x),Pop(S,&y),Pop(S,&z));//��ջ���ж��Ƿ�ɹ�,z=1,y=2,x=����� 
	printf("%d %d %d\n",x,y,z); 
	Push(S,3);
	GetTop(S,&z);
	printf("%d %d\n",z,StackLength(S));
	 
}