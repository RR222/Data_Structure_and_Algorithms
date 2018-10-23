#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 30
typedef int Elemtype;
typedef char Vertype;

typedef struct ArcNode{
	int adhVex;//��β 
	struct ArcNode *next; 
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //�� 
	ArcNode *head; 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXSIZE];
	int vexnum; // ������
	int arcnum; //���� 
}AdjList;
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


AdjList *Create(){
	AdjList *adj;
	
	adj = (AdjList *)malloc(sizeof(AdjList)); 
	printf("����������ͼ�Ķ���������ͱߵ�����:");
	scanf("%d%d",&adj->vexnum,&adj->arcnum);
	int i;
	printf("���������Ϣ:\n");
	for(i=0;i < adj->vexnum;i++){
		getchar();
		printf("�������%d������:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
		adj->vertex[i].head = NULL;
	} 
	
	
	getchar();
	int j,k;
	char a[3];
	ArcNode *arci,*arcj;
	ArcNode *p;
	printf("\n���������Ϣ��ab:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("�������%d����:",i+1);
		gets(a);                                                                                                                                                                                                                                  
		for(j=0;adj->vertex[j].vexdata != a[0] &&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata != a[1] &&k<adj->vexnum;k++);
		
		arci = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arci->adhVex = k;
		arci->next = adj->vertex[j].head;
		adj->vertex[j].head = arci; 
		
		arcj = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arcj->adhVex = j;
		arcj->next = adj->vertex[k].head;
		adj->vertex[k].head = arcj;
	}
	
	printf("��������ڽӱ�����:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("����:%c ",adj->vertex[i].vexdata);
		p = adj->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("\n");
	} 
 	return adj;
}
int visited[MAXSIZE];
void BFSTraverse(AdjList *GL){
	int i;
	CSeQeue *Q;//��
	Q=InitSeQueue();
	ArcNode *p; 
	for(i=0;i<GL->vexnum;i++){
		if(!visited[i]){
			visited[i]=1;
			printf("%c",GL->vertex[i].vexdata);
			InitSeQueue(Q,i);//��� 
			while(!EmptySeQueue(Q)){
				QutSeQueue(Q,&i);//����
				p=GL->vertex[i].head;
				while(p){
					if(!visited[p->adhVex]){//�ڵ�δ������ 
						visited[p->adhVex]=1;
						printf("%c",GL->vertex[p->adhVex].vexdata);
						InitSeQueue(Q,p->adhVex);//��� 
					}
					p=p->next; 
				} 
				 
			}	
		}
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	printf("��ͼ����DFS�������:");
	BFSTraverse(adj);
	printf("\n");
} 