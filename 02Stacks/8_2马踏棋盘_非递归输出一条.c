#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define H 8
#define W 8 
typedef struct{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE];//ջ,���͸���������� 
	int top;//ָ��ջ�� 
}SeqStack; 

//�½�һ����ջ
SeqStack *InitStack (){ 
	SeqStack *S;
	S=(SeqStack *)malloc(sizeof(SeqStack));
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
SeqStack *SS;

int book[W][H] ={0};//���
int next[8][2]={{-2,1}, //��һ���߷� 
				{-1,2}, 
			    {1,2},
	            {2,1}, 
				{2,-1},
				{1,-2}, 
			    {-1,-2},
	            {-2,-1}};
int step=0;	            
int dfs(Elemtype e){

	 int k,step=1;
	 Elemtype e1=e,e2;//e1������ջԪ�ء�e2��e1��̽�����Ԫ�� 
	 e1.direction=0;
	 
	while(step!=W*H){
			
		for(k=e1.direction;k<8;k++){ //�����һ������ջ����e1.direction=0�������һ���ǳ�ջ��e1.direction++ 
			
			e2.x=e1.x+next[k][0];
			e2.y=e1.y+next[k][1];
			e1.direction = k;//e1��e2���߷� 
			
			if(e2.x<0||e2.x>H||e2.y<0||e2.y>=W)
				continue;
		
			if(book[e2.x][e2.y]==0){
				book[e1.x][e1.y]=step;
				Push(SS,e1);//��ջe1 
				
				e1 = e2; //ԭe2���e1(����ջ) 
				e1.direction=0;//�´���̽��0��ʼ 
				step++;
				break;
			}
		}
		if(k==8){
			Pop(SS,&e1);//��ջջ��Ԫ�أ�ջ��Ԫ�س�Ϊ�µ�e1(����ջ) 
			
		 	book[e1.x][e1.y]=0; 
			step--;
			e1.direction++;//�´���̽������ջ���ķ��� 
		}			
	}
	
	//����յ�Ԫ�� 
	book[e1.x][e1.y]=step;
	
	int i,j;
	if(step==W*H){//��ӡ 
		for(i=0;i<H;i++){ 
			for(j=0;j<W;j++)
				printf("%4d",book[i][j]);
		 	printf("\n");
		} 	
	}
	return ;	
}

int main(void)
{
	Elemtype e;
	
	SS=InitStack();
	printf("������������꣺\n");
	scanf("%d%d",&e.x,&e.y);
	book[e.x][e.y]=step;//�����ʼ��
	
	int a=clock();
	dfs(e);
	int b=clock();
	printf("\n%lf��\n",(b-a)/1000.0);
}
 
	            