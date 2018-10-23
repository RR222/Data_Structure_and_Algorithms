#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 30
typedef int Elemtype;
typedef char Vertype;

typedef struct{
	int acre[MAXSIZE][MAXSIZE];//�ڽӱ�
	Vertype Vex[MAXSIZE];//������Ϣ
	int vexnum;//��������
	int acrenum;//�ߵ����� 
}AdjMatrix;//�ڽӾ��� 

typedef struct{
	Elemtype date[MAXSIZE];
	int front,rear; 
}CSeQeue;//���� 

//��ʼ��
CSeQeue *InitSeQueue(){
	CSeQeue *qS;
	qS=(CSeQeue *)malloc(sizeof(CSeQeue));
	qS->rear=qS->front=MAXSIZE-1;
	return qS;
}
//���
int InSeQueue(CSeQeue *qS ,Elemtype x){
	
	if((qS->rear+1)%MAXSIZE==qS->front){
		printf("����\n");
		return FALSE;
	}
	qS->rear=(qS->rear+1)%MAXSIZE;
	qS->date[qS->rear]=x;
	return TRUE;
} 
//�п�
int EmptySeQueue(CSeQeue *qS){
	
	if(qS->front == qS->rear)
		return TRUE;
	return FALSE;
} 
//���� 
int QutSeQueue(CSeQeue *qS ,Elemtype *x){
	if(!EmptySeQueue(qS)){
		qS->front=(qS->front+1)%MAXSIZE;
		*x = qS->date[qS->front];
		return TRUE;
	}
	printf("�ӿ�\n");
	return FALSE; 
} 


AdjMatrix *Create(){
	AdjMatrix *adj;
	adj = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	
	printf("����������ͼ�Ķ������ͱ���:");
	scanf("%d%d",&adj->vexnum,&adj->acrenum);
	
	int i;
	printf("���������Ϣ:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("�������%d������:",i+1);
		scanf("%c",&adj->Vex[i]);
	} 

	
	int j,k;
	char a[3];
	for(i=0;i<adj->vexnum;i++) // ��ʼ�� 
		for(j=0;j<adj->vexnum;j++)
			adj->acre[i][j]=0;

	getchar();
	printf("\n���������Ϣ:��ab\n");
	for(i=0;i<adj->acrenum;i++){
		printf("�������%d����:",i+1);
		gets(a);
		
		j=0;
		k=0;	
		while(adj->Vex[j++] != a[0]&&j<adj->acrenum);
		while(adj->Vex[k++] != a[1]&&k<adj->acrenum);
		adj->acre[j-1][k-1]=1;
		adj->acre[k-1][j-1]=1;
	}
	
	printf("\n��������ڽӾ�������:\n");
	for(i=0;i<adj->vexnum;i++){
		for(j=0;j<adj->vexnum;j++){
			printf("%4d",adj->acre[i][j]);
		}
		printf("\n");
	}
	
	return adj;
}
int visited[MAXSIZE]; 

void BFSTraveres(AdjMatrix *G){
	int i,j;
	CSeQeue *Q;//��
	Q=InitSeQueue();
	 
	for(i=0;i<G->vexnum;i++){
		if(!visited[i]){ //��δ���ʵĵ㣬����DFS���������ͨͼ��ֻ��ִ��һ�� 
			visited[i]=1;
			printf("%c",G->Vex[i]);
	 		InSeQueue(Q,i);//���
			  
	 		while(!EmptySeQueue(Q)){  //�����ǰ�Ӳ�Ϊ�� 
	 		
		 		QutSeQueue(Q,&i);//����
				for(j=0;j<G->vexnum;j++){
					
					if(G->acre[i][j]==1&&visited[j]==0){//����ڽӵ���ڲ�δ���ʹ�
						visited[j]=1;
						printf("%c",G->Vex[j]);
						InSeQueue(Q,j);//���  
					} 
				}  
		 	}
	 		
		}		
	}	
}
int main(void){
	AdjMatrix *adj;
	adj = Create();
	printf("��ͼ����BFS�������:");
	BFSTraveres(adj);
	printf("\n");
}



