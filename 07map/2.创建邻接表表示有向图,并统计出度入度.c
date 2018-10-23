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
	ArcNode *arc;
	ArcNode *p;
	printf("\n���������Ϣ��ab:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("�������%d����:",i+1);
		gets(a);                                                                                                                                                                                                                                  
		for(j=0;adj->vertex[j].vexdata != a[0] &&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata != a[1] &&k<adj->vexnum;k++);
		
		arc = (ArcNode *)malloc(sizeof(ArcNode));
	 	
		arc->adhVex = k;
		arc->next = adj->vertex[j].head;
		adj->vertex[j].head = arc; 
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

void Statistics(AdjList *adj){
	int i,j;
	int countA,countB;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		countA=0;
		countB=0;
		printf("����%c��",adj->vertex[i].vexdata);
		p=adj->vertex[i].head;	
		while(p!=NULL){
			countA++;
			p=p->next;
		}
		printf("����:%d,",countA);
		
		for(j=0;j<adj->vexnum;j++){
			p=adj->vertex[j].head;
			while(p!=NULL){
				if(p->adhVex==i){
					countB++;
				}
				p=p->next;
			}
		}
		printf("���:%d\n",countB);	
		
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
} 