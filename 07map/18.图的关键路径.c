#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
typedef struct ArcNode{
	int adhVex;//��β 
	int weight; //Ȩֵ 
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
		arc = (ArcNode *)malloc(sizeof(ArcNode));
		printf("�������%d����:",i+1);
		scanf("%s %d",a,&arc->weight);                                                                                                                                                                                                                                 
		for(j=0;adj->vertex[j].vexdata != a[0] &&j<adj->vexnum;j++);
		for(k=0;adj->vertex[k].vexdata != a[1] &&k<adj->vexnum;k++);
		
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
int ve[MAXVEX],vl[MAXVEX];//�¼������緢��ʱ�����ٷ���ʱ��
int stack2[MAXVEX]; //���ڴ洢���������ջ
int top2; //stack��ջ��ָ�� 
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
		count++; //ͳ������Ľڵ���� 
		
		stack2[++top2]=gettop;//�������Ķ�������ѹ�����������ջ�� 
		
		for(arc=GL->vertex[gettop].head;arc;arc=arc->next){ //�Դ˶��㻡����� 
			k=arc->adhVex;
			if(!(--GL->vertex[k].in)){  //��k������ڽӵ��-1 
				stack[++top]=k; //����ȼ�Ϊ0������ջ 
			}
			
			if((ve[gettop]+arc->weight >ve[k])){ //�����������緢��ʱ�� 
				ve[k] = ve[gettop]+arc->weight;
			} 
		}
	}
	
	if(count < GL->vexnum) //��ʾ�л�· 
		return 1; 
	else 
		return 0; 
}

void CriticalPath(AdjList *GL){
	ArcNode *arc;
	int i,gettop,k,j;
	int e,l; // ��������������ʱ��
	TopologicalSort(GL); //���������򣬼�������ve��stack2��ֵ
	for(i=0;i<GL->vexnum;i++){
		vl[i]=ve[GL->vexnum-1];
	}	 
	
	while(top2!=0){
		gettop = stack2[top2--];
		for(arc = GL->vertex[gettop].head;arc;arc=arc->next){
			//����������ٷ���ʱ��vlֵ
			k=arc->adhVex;
			if(vl[k]-arc->weight <vl[gettop]){
				vl[gettop]=vl[k]-arc->weight;
			} 
		}
	}
	
	for(j=0;j<GL->vexnum;j++){  //����e,l�͹ؼ�� 
		for(arc = GL->vertex[j].head;arc;arc=arc->next){
			
			k=arc->adhVex;
			e=ve[j];
			l=vl[k]-arc->weight;
			if(e==l){ //������ȼ�Ϊ�ؼ�� 
				printf("<%c,%c> lenghth:%d\n",GL->vertex[j].vexdata,GL->vertex[k].vexdata,arc->weight); 
			}
		}			
	}
	 
}
int main(void){
	AdjList *adj;
	adj = Create();
	printf("\n");
	CriticalPath(adj); 
} 