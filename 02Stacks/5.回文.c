#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 30 //ջ�����洢�ռ�
#define TRUE 1
#define FALSE 0 
typedef char Elemtype;
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
int f1(char string[]){
	SeqStack *seq; 
	seq=InitStack();
	int i;
	char c;
	for(i=0;i<strlen(string)/2;i++){
		Push(seq,string[i]);
	}
	
	for(i=i+strlen(string)%2;string[i];i++){
		Pop(seq,&c);
		if(c!=string[i]){
			printf("���ǻ���\n");
				break;
		}		
	}
	
	if(i==strlen(string))
		printf("�ǻ���\n");
} 
int main(void){
	char string[30];
	printf("�������ַ�����");
	gets(string);	
	
	f1(string);
} 