#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define TRUE 1
#define FALSE 0 
#define M 10
#define IO "input.txt"
#define OUT "output.txt"
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
int book[M][M];//������� 
int map[M][M];//��ͼ 
char out[M][M][3];//�������
int width,high;//�Թ��Ŀ�� 
int count ;//��¼�߷� 

Elemtype input(){   //���ļ��ж��� 
	FILE *fp;
	Elemtype e;	
	fp = fopen(IO,"r+"); 
	if(fp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
	
	fscanf(fp,"%d %d",&width,&high);//¼���Թ��Ŀ�͸� 
	fscanf(fp,"%d %d",&e.x,&e.y);//¼���Թ������ 
	e.direction=0;
	int i,j;
	for(i=0;i<high;i++){
		for(j=0;j<width;j++){
			fscanf(fp,"%d",&map[i][j]);	
		}
	}
	printf("�Թ�����:\n");
	for(i=0;i<high;i++){
		for(j=0;j<width;j++){
			printf("%d ",map[i][j]);	
		}
		printf("\n");
	}
	
	fclose(fp); 
	return e;
} 

void output(){   //�����д�뵽�ļ�&�������Ļ�� 
	char str[3];
	int i,j;
	for(i=0;i<high;i++){     //��ʼ��������� 
		for(j=0;j<width;j++){
			str[0]=map[i][j]+'0';
			str[1]=' ';
			str[2]=0;
			strcpy(out[i][j],str);	
		}
	}
	
	for(i=0;i<SS->top+1;i++){  //���·�� 
		if(SS->data[i].direction==0){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}else if(SS->data[i].direction==1){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}else if(SS->data[i].direction==2){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}else if(SS->data[i].direction==3){
			strcpy(out[SS->data[i].x][SS->data[i].y],"��");
		}
	}	
	
	//�������ļ���&���뵽��Ļ��
	FILE *fp;
	if(count==1){
		fp = fopen(OUT,"w+");
	}else{
		fp = fopen(OUT,"a+");
	}	
	 
	if(fp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    
    fprintf(fp,"��%d���߷�\n",count); 
    printf("\n��%d���߷�\n",count);
    for(i=0;i<high;i++){
    	for(j=0;j<width;j++){
	    	fprintf(fp,"%s",out[i][j]); 
	    	printf("%s",out[i][j]);
	    }
	    fprintf(fp,"%c",'\n'); 
	    printf("\n");
    }
	fprintf(fp,"��%d��\n",SS->top+1); 
    printf("��%d��\n",SS->top+1);
    fprintf(fp,"%c",'\n'); 
		
	fclose(fp); 	
}
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
			
			if(e2.x<0||e2.y<0||e2.y>=width||e2.x>=high)//�ж��Ƿ�Խ�� 
				continue;
				
			if(map[e2.x][e2.y]!=1&&book[e2.x][e2.y]==0)//�ж���һ���Ƿ��߹����Ƿ����ϰ���
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
		if(map[e1.x][e1.y]==2){
			count++; 
			output();//������ 
		}
		
		if(k==4||map[e1.x][e1.y]==2){
			//��ջ 
			Pop(SS,&e1);
			book[e1.x][e1.y]=0;
			//printf("��(%d,%d)%d\n",e1.x,e1.y,e1.direction); 
			e1.direction++;
		}
	}while(!StackEmpty(SS));	
}



int main(void)
{	
	Elemtype e;
	SS=InitStack();
	e=input();
	dfs(e);//��һ����������ʼ���x���꣬�ڶ�����������ʼ���y���꣬�����������ǲ��� 
	
	
	
	FILE *fp;
	if(count==0){
		printf("�޷��ߵ��յ�\n");
	
		fp = fopen(OUT,"w+");
		if(fp==NULL)
    	{
        	printf("�ļ���ʧ��\n");
        	exit(0);
    	}
    
    	fprintf(fp,"�޷��ߵ��յ�\n"); 
     	
		fclose(fp);
	}
}


