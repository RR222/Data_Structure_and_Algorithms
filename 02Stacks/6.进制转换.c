#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30 //ջ�����洢�ռ�
#define TRUE 1
#define FALSE 0 
#define RADIX 2
typedef int Elemtype;
typedef struct
{
    Elemtype data[MAXSIZE];//ջ,���͸���������� 
    int top;//ָ��ջ�� 
}SeqStack; 

//ջ�ĳ�ʼ�� 
SeqStack *InitStack (){
    //����ռ� 
    SeqStack *S;
    S=malloc(sizeof(SeqStack));
    //ջ����ʼ�� 
    S->top =-1; 
    return S;
}


//��ջ
int Push (SeqStack *S,Elemtype e){
	if(S->top==MAXSIZE-1)//ջ���������ʧ�� 
		return FALSE;
		
	S->top++;
	S->data[S->top]= e;
	return TRUE;
} 

//��ջ
int Pop (SeqStack *S,Elemtype *e){
	if(S->top == -1)//��ջ����ջʧ��
		return FALSE;
		
	*e=S->data[S->top];
	S->top--;	
	return TRUE;
} 
SeqStack *SS;
void Convert(int num){
	int i;
	while(num){
		i=num%RADIX;
		num=num/RADIX;
		Push(SS,i); 	
	}
} 
int main(void){
	
	int i,num;
	SS=InitStack();
	//printf("������Ҫת������\n");
	//scanf("%d",&num);
	for(num=0;num<16;num++){
		Convert(num);
		while(SS->top!=-1){
			printf("%d",i,Pop(SS,&i));
		}
		printf("\n");
	}
}