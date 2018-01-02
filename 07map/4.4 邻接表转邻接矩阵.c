#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
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
	VertexNode vertex[MAXVEX];
	int vexnum; // ������
	int arcnum; //���� 
}AdjList;

typedef struct{
	int acre[MAXVEX][MAXVEX];//�ڽӱ�
	Vertype Vex[MAXVEX];//������Ϣ
	int vexnum;//��������
	int acrenum;//�ߵ����� 
}AdjMatrix;
AdjList *Create(){
	AdjList *adj;
	
	adj = (AdjList *)malloc(sizeof(AdjList)); 
	printf("������ͼ�Ķ���������ͱߵ�����:");
	scanf("%d%d",&adj->vexnum,&adj->arcnum);
	int i;
	printf("���������Ϣ:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("�������%d������:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
		adj->vertex[i].head = NULL;
	} 
	
	
	getchar();
	int j,k;
	char a[3];
	ArcNode *arc;
	ArcNode *p;
	printf("\n���������Ϣ��ab:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("�������%d����:",i+1);
		gets(a);                                                                                                                                                                                                                                  
		j=0;
		k=0;	
		while(adj->vertex[j].vexdata != a[0] &&j++<adj->vexnum);
		
		while(adj->vertex[k].vexdata != a[1] &&k++<adj->vexnum);
		
		arc = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arc->adhVex = k;
		arc->next = adj->vertex[j].head;
		adj->vertex[j].head = arc; 
	}
	
	printf("\n��������ڽӱ�����:\n");
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
AdjMatrix *ConvertMatrix(AdjList *adjList){
	
	AdjMatrix *adjMatrix;
	adjMatrix = (AdjMatrix *)malloc(sizeof(AdjMatrix));
	
	adjMatrix->vexnum = adjList->vexnum;
	adjMatrix->acrenum = adjList->arcnum;
	 
	int  i,j;
	ArcNode *q;
	for(i=0;i<adjMatrix->vexnum;i++) // ��ʼ�� 
		for(j=0;j<adjMatrix->vexnum;j++)
			adjMatrix->acre[i][j]=0;
			
	for(i=0;i<adjList->vexnum;i++){
		
		adjMatrix->Vex[i]= adjList->vertex[i].vexdata;	
		q=adjList->vertex[i].head;
		while(q!=NULL){
			adjMatrix->acre[i][q->adhVex]=1;
			q=q->next;
		}
	} 
	
	printf("\nת������ڽӾ�������:\n");
	for(i=0;i<adjMatrix->vexnum;i++){
		for(j=0;j<adjMatrix->vexnum;j++){
			printf("%4d",adjMatrix->acre[i][j]);
		}
		printf("\n");
	}
} 
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	ConvertMatrix(adj);
} 