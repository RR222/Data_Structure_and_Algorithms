#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
//��β-->��ͷ  <β��ͷ> 
typedef struct ArcNode{
	int tailvex;//��β
	int headvex;//��ͷ 
	struct ArcNode *tailLink;//����������ͬ��β�ı� 
	struct ArcNode *headLink;//����������ͬ��ͷ�ı�
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //�� 
	ArcNode *firstout;//��������Ϊ��β�ı� 
	ArcNode *firstin;//��������Ϊ��ͷ�ı� 
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
	
	int i=0;
	printf("���������Ϣ:\n");
	for(i=0;i<adj->vexnum;i++){
		getchar();
		printf("�������%d������:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
		adj->vertex[i].firstout=NULL;
		adj->vertex[i].firstin=NULL; 
	}
	
	getchar();
	int j,k;
	ArcNode *arc;
	char a[3];
	printf("\n���������Ϣ��ab:\n");
	for(i=0;i<adj->arcnum;i++){
		
		printf("�������%d����:",i+1);
		gets(a); 
		for(j=0;adj->vertex[j].vexdata!=a[0]&&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata!=a[1]&&k<adj->vexnum;k++);
		arc=(ArcNode *)malloc(sizeof(ArcNode));
		arc->tailvex=j;
		arc->headvex=k;
		
		arc->tailLink=adj->vertex[j].firstout;
		adj->vertex[j].firstout=arc;
		
		arc->headLink=adj->vertex[k].firstin;
		adj->vertex[k].firstin=arc;				 
	}
	
	printf("�������ʮ����������:\n");
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		printf("����:%c",adj->vertex[i].vexdata);
		p = adj->vertex[i].firstout;	
		while(p!=NULL){
			printf("-->%d",p->headvex);
			p=p->tailLink;	
		}
		printf("\n");	
		printf("����:%c",adj->vertex[i].vexdata);
		p = adj->vertex[i].firstin;
		while(p!=NULL){
			printf("<==%d",p->tailvex);
			p=p->headLink;	
		}
		printf("\n\n");
	} 	
	return adj;	
} 

Statistics(AdjList *adj){
	int i; 
	int countA,countB;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		
		for(p=adj->vertex[i].firstout,countA=0;p!=NULL;p=p->tailLink,countA++);
		for(p=adj->vertex[i].firstin,countB=0;p!=NULL;p=p->headLink,countB++);
		printf("��%c�ĳ���Ϊ:%d,���Ϊ:%d\n",adj->vertex[i].vexdata,countA,countB);
	}	
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
}  