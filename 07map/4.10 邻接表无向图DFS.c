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
int visited[MAXVEX];
void DFS(AdjList *GL,int i){
	ArcNode *p;
	visited[i]=1;
	printf("%c",GL->vertex[i].vexdata);
	p=GL->vertex[i].head;
	while(p){
		if(!visited[p->adhVex]){
			DFS(GL,p->adhVex);
		}
		p=p->next;
	}	
}
void DFSTraverse(AdjList *GL){
	int i;
	for(i=0;i<GL->vexnum;i++){
		if(!visited[i]){
			DFS(GL,i);	
		}
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	printf("��ͼ����DFS�������:");
	DFSTraverse(adj);
	printf("\n");
} 