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
	int in;  //������� 
	ArcNode *head; 
}VertexNode;

typedef struct{
	VertexNode vertex[MAXVEX]; //�������� 
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
		adj->vertex[i].in=0;
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
		adj->vertex[k].in++;
		
	}
	
	printf("��������ڽӱ�����:\n");
	for(i=0;i<adj->vexnum;i++){
		printf("����:%c ",adj->vertex[i].vexdata);
		p = adj->vertex[i].head;
		
		while(p!=NULL){
			printf("-->%d",p->adhVex);
			p=p->next;	
		}
		printf("  ���Ϊ:%d\n",adj->vertex[i].in);
	} 
 	return adj;
}

void TopologicalSort(AdjList *GL){
	ArcNode *arc;
	int i,k,gettop;
	int top=0; //ջ��
	int count=0; //����ͳ�ƶ���ĸ���
	int stack[MAXVEX];	
	
	for(i=0;i<GL->vexnum;i++){
		if(GL->vertex[i].in==0){
			stack[++top]=i;
		}
	}
	
	while(top!=0){
		gettop = stack[top--]; //��ջ 
		printf("%c->",GL->vertex[gettop].vexdata);
		count++; //ͳ������Ľڵ���� 
		for(arc=GL->vertex[gettop].head;arc;arc=arc->next){ //�Դ˶��㻡����� 
			k=arc->adhVex;
			if(!(--GL->vertex[k].in)){  //��k������ڽӵ��-1 
				stack[++top]=k; //����ȼ�Ϊ0������ջ 
			} 
		}
	}
	
	if(count < GL->vexnum) //��ʾ�л�· 
		return 1; 
	else 
		return 0; 
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	TopologicalSort(adj);
} 