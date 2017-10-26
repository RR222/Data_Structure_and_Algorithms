#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0 
#define W 4
#define H 5
typedef struct{
	int x;
	int y;
	int direction;
} Elemtype;
typedef struct
{
	Elemtype data[MAXSIZE]; 
	int top;
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
int book[H][W];
int a[H][W]={{0,0,1,0},
             {0,0,0,0},
             {0,0,1,1},
			 {0,1,0,0},
			 {0,0,0,1}};
int n=3,m=3;//�յ����� 
int dfs(Elemtype e){
	int k;
	int next[4][2]={{0,1},//�� 
	                {1,0},//�� 
			        {0,-1},//�� 
	                {-1,0}};//��
	Elemtype e1,e2;
	e1 = e;
	e1.direction=0;
	do{	
			
		for(k=e1.direction;k<4;k++){
			
			e2.x=e1.x+next[k][0];//��һ�� 
			e2.y=e1.y+next[k][1];
			e1.direction=k;
			
			if(e2.x<0||e2.y<0||e2.y>=W||e2.x>=H)//�ж��Ƿ�Խ�� 
				continue;
				
			if(a[e2.x][e2.y]!=1&&book[e2.x][e2.y]==0)//�ж���һ���Ƿ��߹����Ƿ����ϰ���
			{
				//��ջ 
				Push(SS,e1);
				book[e1.x][e1.y]=1;//���
				e1=e2; 
				e1.direction=0;
				//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction);
				break;				
			} 
			
		}
		
		int i;
		//�����յ� 
		if(e1.x==n&&e1.y==m){
			Push(SS,e1);
			book[e1.x][e1.y]=1;
			
			for(i=0;i<SS->top+1;i++){
				printf("����(%d,%d)����:%d\n",SS->data[i].x,SS->data[i].y,SS->data[i].direction); 
			}
			printf("\n\n");
			Pop(SS,&e1);
			book[e1.x][e1.y]=0;
		}
		
		if(k==4||e1.x==n&&e1.y==m){
			//��ջ 
			Pop(SS,&e1);
			book[e1.x][e1.y]=0;
			//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction); 
			e1.direction++;
		}
	}while(!StackEmpty(SS)||e1.direction!=4);
	
}
int main(void)
{
	Elemtype e;
	SS=InitStack();
	e.x=0;//��� 
	e.y=0;
	e.direction=0;
	book[0][0]=1;//�����ʼ��
	dfs(e);//��һ����������ʼ���x���꣬�ڶ�����������ʼ���y���꣬�����������ǲ��� 
}


