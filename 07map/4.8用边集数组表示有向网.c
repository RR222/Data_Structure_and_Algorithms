#include <stdio.h>
#define MAXVEX 30
typedef char Vertype;
//��β-->��ͷ  <β��ͷ> 
typedef struct ArcNode{
	int tailvex;//��β
	int headvex;//��ͷ 
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
		scanf("%d%d%d",&adj->arc[i].tailvex,&adj->arc[i].headvex,&adj->arc[i].weight);			 
	}
	
	printf("������ı߼���������:\n");
	printf("������Ϣ:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("%c\n",adj->vertex[i]);
	} 
	printf("����Ϣ:\n");
	for(i=0;i<adj->arcnum;i++){
		printf("%d %d %d\n",adj->arc[i].tailvex,adj->arc[i].headvex,adj->arc[i].weight);
	}	
	return adj;
} 

Statistics(AdjList *adj){
	int i,j; 
	int countA,countB;
	ArcNode *p;
	for(i=0;i<adj->vexnum;i++){
		countA=0;
		countB=0;
		for(j=0;j<adj->arcnum;j++){
			if(adj->arc[j].tailvex==i){
				countA++;
			}
			if(adj->arc[j].headvex==i){
				countB++;
			}	
		}
		
		printf("����%c�ĳ���Ϊ:%d,���Ϊ:%d\n",adj->vertex[i],countA,countB);
	}	
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	Statistics(adj);
}  