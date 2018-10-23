#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
typedef struct ArcNode{
	int ivex;//�ߵ�i���� 
	int jvex;//�ߵ�j���� 
	struct ArcNode *ilink;//ָ��ͬ������i����ı� 
	struct ArcNode *jlink;//ָ��ͬ������j����ı�
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //�� 
	ArcNode *firstdge;//��������Ϊ��β�ı� 
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
		adj->vertex[i].firstdge=NULL;
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
		arc->ivex=j;
		arc->jvex=k;
		
		arc->ilink=adj->vertex[j].firstdge;
		adj->vertex[j].firstdge=arc;
		
		arc->jlink=adj->vertex[k].firstdge;
		adj->vertex[k].firstdge=arc;				 
	}
	
	printf("��������ڽӶ��ر�����:\n");
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		printf("����:%c",adj->vertex[i].vexdata);
		p = adj->vertex[i].firstdge;	
		while(p!=NULL){
			if(p->ivex==i){
				printf("-->%d",p->jvex);
				p=p->ilink;
			}else{
				printf("-->%d",p->ivex);
				p=p->jlink;
			}
				
		}
		printf("\n");	
	} 	
	return adj;	
} 
void Statistics(AdjList *adj){
	int i; 
	int count;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		
		for(p=adj->vertex[i].firstdge,count=0;p!=NULL;count++){
			if(p->ivex==i){
				p=p->ilink;
			}else{
				p=p->jlink;
			}
		}
		printf("��%c�Ķ�Ϊ:%d\n",adj->vertex[i].vexdata,count);
	}
} 
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
}  