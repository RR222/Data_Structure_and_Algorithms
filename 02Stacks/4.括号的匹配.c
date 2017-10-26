#include <stdio.h>
#include <stdlib.h>
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
void f1(char string[]){
	
	SeqStack *seq; 
	char c;
	int i;
	seq=InitStack();
	for(i=0;string[i];i++)
	{
		
		if(string[i]=='('||string[i]=='{'||string[i]=='['){
			Push(seq,string[i]);	//��ջ	
		}else{
			
			if(seq->top==-1){//�ж��Ƿ�ջ��
				printf("�����!\n");
				return; //����ƥ�� 
			}else{
				Pop(seq,&c);//��ջ 
				switch(string[i]){
					case ')' : 
						if(c!='('){
							printf("��ƥ��\n");
							return;
						}
						break;
					case ']' :
						if(c!='['){
							printf("��ƥ��\n");
							return;
						}
						break;
					case '}' :
						if(c!='{'){
							printf("��ƥ��\n");
							return;
						}
						break;
					default :
						printf("��ƥ��\n");
						return;
				}	
			}
		}		
	}
	
	
	if(seq->top!=-1){
		printf("�����!\n");
		return;
	}
	
	printf("��Գɹ�\n");

 }
int main(){
	char string[20];
	int i; 
	printf("���������Ŵ���");
	gets(string);	
	f1(string);
}