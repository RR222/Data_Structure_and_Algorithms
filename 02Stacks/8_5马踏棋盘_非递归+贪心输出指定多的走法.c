#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0 
#define W 8
#define H 8
#define Q 3 //ÿ������ֻ����Ȩֵ��ǰ���ķ��� 
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

typedef struct{ 
	int value;
	int direction;
}Value;
//�½�һ����ջ
SeqStack *InitStack (){
	//����ռ� 
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
int step=1;   
int count, t=0;      
void Sortint(Elemtype e , Value b[8]){ //����e��8�������Ȩֵ�������� 
	Elemtype e1,e2;
	int k1,k2;
	for(k1=0;k1<8;k1++){
		e1.x = e.x+next[k1][0];
		e1.y = e.y+next[k1][1];
		
		b[k1].direction=k1;
		b[k1].value=0;
		if(book[e1.x][e1.y]!=0||e1.x<0||e1.y<0||e1.x>=H||e1.y>=W)//�������㲻���ߣ������������
			continue;
		
		for(k2=0;k2<8;k2++){//����������Ȩֵ 
			e2.x= e1.x+next[k2][0];
			e2.y= e1.y+next[k2][1];
			if(book[e2.x][e2.y]!=0|| e2.x<0 ||e2.y<0 ||e2.x>=H ||e2.y>=W )
				continue;
			
			 b[k1].value++;//Ȩֵ��һ 
		} 
	}
	//��Ȩֵ��С����(��������0��ĩβ) 
	int i,j;
	Value t;
	for(i=1;i<8;i++){
		t=b[i];
		for(j=i-1;j!=-1&&(t.value<b[j].value||b[j].value==0)&&t.value!=0;j--)
			b[j+1]=b[j];
		b[j+1]=t;
	
	}
	return ;
}
  
int dfs(Elemtype e){

	int k;
	Value b[8];//���8������Ȩֵ 
	Elemtype e1=e,e2;//e1��ǰ����ջ�㣬e2��e1��̽�����Ԫ�� 
	int i,j;
	
	Sortint(e1,b);//����Ȩֵ 
	e1.direction=0;
	do{
	
		Sortint(e1,b);//����Ȩֵ 
		k=e1.direction;
				
		if(b[k].value!=0&&k<Q){   //ֻ����Ȩֵ����ǰQ�ķ��� 
			e1.direction = k;//kΪ��ǰȨֵ���±� 
			
			//��ջ 
			Push(SS,e1); 
			book[e1.x][e1.y]=step;
			step++;
			 //printf("��(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top);
			//����e1 
			e1.x = e1.x+next[b[k].direction][0];
			e1.y = e1.y+next[b[k].direction][1];
			e1.direction=0; 
		}
		
		if(step==W*H){  
			t++; 
			book[e1.x][e1.y]=step;	
	     	 //��ӡ 
			for(i=0;i<H;i++){ 
				for(j=0;j<W;j++)
					printf("%4d",book[i][j]);
		 		printf("\n");
			} 
			printf("��%d���߷�\n\n",t); 
			book[e1.x][e1.y]=0;	 
		}
		if(b[k].value==0||step==W*H||k>=Q){
			//��ջ ������e1 
			Pop(SS,&e1);
			//printf("��(%d,%d)%d %d\n",e1.x,e1.y,e1.direction,SS->top); 
			book[e1.x][e1.y]=0; 
			step--;
			e1.direction++;//�´���̽������ջ���ķ��� 
		}
	}while(count!= t);  
}

int main(void)
{
	Elemtype e;
	SS=InitStack();
	printf("������������꣺\n");
	scanf("%d%d",&e.x,&e.y);
	book[e.x][e.y]=step;//�����ʼ��
	printf("Ҫ����������߷�:\n");
	scanf("%d",&count);
	int a=clock();
	dfs(e);
	int b=clock();
	printf("\n%lf��\n",(b-a)/1000.0);
	getchar();
}
 
	            