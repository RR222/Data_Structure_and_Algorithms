#include <stdio.h>
#define MAXVEX 30
typedef char Vertype;
typedef struct ArcNode{
	int begin;
	int end;
	int weight;//Ȩֵ 
}ArcNode;

typedef struct VertexNode{
	Vertype vexdata; //�� 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXVEX];
	ArcNode arc[MAXVEX]; 
	int vexnum; // ������
	int arcnum; //���� 
}AdjList;
AdjList *Create(){
	AdjList *adj;
	adj = (AdjList *)malloc(sizeof(AdjList));
	printf("�������������Ķ���������ͱߵ�����:");
	scanf("%d%d",&adj->vexnum,&adj->arcnum);
	
	int i=0;
	printf("\n���������Ϣ:\n");
	for(i=0;i<adj->vexnum;i++){
		getchar();
		printf("�������%d������:",i+1);
		scanf("%c",&adj->vertex[i].vexdata);
	}
	
	getchar();
	printf("\n���������Ϣ(���,�յ�,Ȩֵ)��:0 4 6\n");
	for(i=0;i<adj->arcnum;i++){
		printf("�������%d����:",i+1);
		scanf("%d%d%d",&adj->arc[i].begin,&adj->arc[i].end,&adj->arc[i].weight);			 
	}
	
	printf("������ı߼���������:\n");
	printf("������Ϣ:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("%c ",adj->vertex[i]);
	} 
	printf("\n");
	printf("����Ϣ:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("%d %d %d\n",adj->arc[i].begin,adj->arc[i].end,adj->arc[i].weight);
	}	
	return adj;
} 
void sort(AdjList *G,ArcNode *edges){
	int i,j;
	ArcNode p;
	for(i=0;i<G->arcnum;i++){
		edges[i]=G->arc[i];
	} 
	for(i=0;i<G->arcnum-1;i++){
		for(j=0;j<G->arcnum-i-1;j++){
			if(edges[j].weight>edges[j+1].weight){
				p=edges[j];
				edges[j]=edges[j+1];
				edges[j+1]=p;
			}
		}
	}
}
int Find(int *parent,int f){
	while(parent[f]>0){
		f = parent[f];
	}
	return f;
} 
void MiniSpanTree_Kruskal(AdjList *G){
	int i,n,m;
	ArcNode edges[MAXVEX]; //����߼�����
	int parent[MAXVEX]={0};//����һ�������жϱ�����Ƿ��γɻ�·
	sort(G,edges);//��G�еı߸���edges������Ȩֵ��С�������� 
	for(i=0;i<G->arcnum;i++){
		n=Find(parent,edges[i].begin);
		m=Find(parent,edges[i].end);
		
		if(n!=m){  //���n��m����ȣ�˵���˱�û���������������γɻ�·
			parent[n]=m; //���˱ߵĽ�β��������±�Ϊn��parent����ʾ�Ѿ����뵽������������ 
			printf("(%c,%c)",G->vertex[edges[i].begin],G->vertex[edges[i].end]); 
		}
	}
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	MiniSpanTree_Kruskal(adj);	
}  