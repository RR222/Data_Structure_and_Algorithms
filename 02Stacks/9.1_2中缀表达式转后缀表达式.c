#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 40
#define TRUE 1
#define FALSE 0 
typedef struct
{
	char string[10]; 
} Elemtype;
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
int Priority(Elemtype e1){
	switch(e1.string[0]){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case '(':
			return 0;
		case ')':
			return 0;
	}
}
SeqStack *sign;//���� 
Elemtype result[50];//���
int result_top=0;
int Convert(char str[]) {
	Elemtype e1,e2,e3; //e1,���ʽ��ȡ�����֡�e2,���ʽ��ȡ�ķ���(����ջ)��e3����ջջ������ 
	int i,j,count=0; //count�������ֵĳ��� 
	
	for(i=0;str[i];i++){
		if(str[i]>='0'&&str[i]<='9'){ //���������
			e1.string[count]=str[i];
			count++; 
		}  
		else{
			if(count>0){ 
				e1.string[count]=0;
				result[result_top]=e1;//���ִ����������� 
				result_top++; 
			}
			
			e2.string[0]=str[i];
			e2.string[1]=0;
			
			if(str[i]=='('){      //������ֱ����ջ 
				Push(sign,e2); 
			}else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]==')'){ 				
				
				GetTop(sign,&e3);
				//��ջ��Ԫ�رȽϣ������ջ��Ԫ�����ȼ���/��ȣ���ջջ��
				//ֱ��ջ�գ����ŵ�ǰ���ű�ջ��Ԫ�����ȼ��ߣ���������'(' 
				while(StackEmpty(sign)==0&&Priority(e2)<=Priority(e3)&&e3.string[0]!='('){  
					Pop(sign,&e3);//��ջ 
					result[result_top]=e3;//������������ 
					result_top++; 
					GetTop(sign,&e3);//ȡ����һ��ջ��Ԫ�� 
				}
				if(e2.string[0]!=')'){//�����ǰ���Ų���')',��������ջ 
					Push(sign,e2);	
				}else{            //�����')',��ջջ����'('���� 
					Pop(sign,&e3);
				}	
			}else {
				printf("����!");
				return;
			} 
		 	count=0;//���ֵļ��������� 
		}
	}
	//����ʱ
	e1.string[count]=0;
	result[result_top]=e1;//������������ 
	result_top++;  
	while(!StackEmpty(sign)){
		Pop(sign,&e3);
		result[result_top]=e3;//������������ 
		result_top++;  
	}
	
	for(i=0;i<result_top;i++){
		printf("%s ",result[i].string);
	}
	printf("\n");
}
int main(void){
	sign=InitStack(); 
	char str[100]="9+(3-1)*3+10/2";
	//scanf("%s",str); 
	Convert(str);
}