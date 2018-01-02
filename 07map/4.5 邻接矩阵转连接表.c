#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
//�ڽӾ��� 
typedef char Vertype;
typedef struct{
	int acre[MAXVEX][MAXVEX];//�ڽӱ�
	Vertype Vex[MAXVEX];//������Ϣ
	int vexnum;//��������
	int acrenum;//�ߵ����� 
}AdjMatrix;

//�ڽӱ� 
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

AdjMatrix *Create(){
	AdjMatrix *adj;
	adj = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	
	printf("������ͼ�Ķ������ͱ���:");
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



AdjList *ConvertList(AdjMatrix *adjMatrix){
	AdjList *adjList;
	adjList = (AdjList*)malloc(sizeof(AdjList));
	
	adjList->vexnum = adjMatrix->vexnum;
	adjList->arcnum = adjMatrix->acrenum;
	
	int i,j,flag=0;
	ArcNode *arc,*p;
	for(i=0;i<adjMatrix->vexnum;i++){
		flag=0;
		adjList->vertex[i].vexdata=adjMatrix->Vex[i];
		adjList->vertex[i].head=NULL;
		
		
		for(j=0;j<adjMatrix->vexnum;j++){
			if(adjMatrix->acre[i][j]==1){
				if(flag==0){
					adjList->vertex[i].head=(ArcNode *)malloc(sizeof(ArcNode));
					adjList->vertex[i].head->adhVex=j;
					adjList->vertex[i].head->next=NULL;
					p=adjList->vertex[i].head;
					flag=1;
				}else{
					arc = (ArcNode *)malloc(sizeof(ArcNode));
					arc->adhVex = j;
					arc->next =NULL;
					p->next = arc;
					p=arc;
				}		
			}	
		}
	}


	printf("ת������ڽӱ�����:\n");
	for(i=0;i<adjList->vexnum;i++){
		printf("����:%c ",adjList->vertex[i].vexdata);
		p = adjList->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("\n");
	} 
	return adjList;
} 
int main(void){
	AdjMatrix *adj;
	adj = Create();
	ConvertList(adj);
}


