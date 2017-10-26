#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0 
typedef int Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];//ջ,���͸���������� 
	int lefttop;//ָ����ջջ��λ�� 
	int righttop;//ָ����ջվ��λ��	 
}DupsqStack; 

//��ʼ��
DupsqStack *InitDupStack(){
	DupsqStack	*S;
	S=(DupsqStack*)malloc(sizeof(DupsqStack*));
	S->lefttop=-1;
	S->righttop=MAXSIZE;
	return S;
}

//��ջ
int PushDupStack(DupsqStack *S ,char status ,Elemtype x){
	if(S->lefttop+1 == S->righttop) 
		return FALSE;//ջ��
		
	if(status == 'L') 
		S->data[++S->lefttop] =x;
	else if(status == 'R') 
		S->data[--S->righttop] =x;
	else 
		return FALSE;
	return TRUE;	
} 

//��ջ
int PopDupStack(DupsqStack *s ,char status,Elemtype *x){
	if(status =='L')
	{
		if(s->lefttop==-1)//��ջ 
			return FALSE;
			
		*x=s->data[s->lefttop--];	
		return TRUE;
	}
	else if(status == 'R')
	{
		if(s->righttop==MAXSIZE)//��ջ 
			return FALSE;
			
		*x=(s->data[s->righttop++]);
		return TRUE;
	}
	else
		return FALSE;//��־���д� 
}  
int main(void){
	DupsqStack *S;
	S=InitDupStack();
	printf("%d %d\n",S->lefttop,S->righttop);
	PushDupStack(S,'L',4); 
	PushDupStack(S,'R',5); 
	int X;
	printf("%d %d\n",PopDupStack(S,'L',&X),PopDupStack(S,'R',&X));
} 