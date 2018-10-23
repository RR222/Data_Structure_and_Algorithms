#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
typedef char Vertype;
typedef struct{
	int acre[MAXVEX][MAXVEX];//�ڽӱ�
	Vertype Vex[MAXVEX];//������Ϣ
	int vexnum;//��������
	int acrenum;//�ߵ����� 
}AdjMatrix;

AdjMatrix *Create(){
	AdjMatrix *adj;
	adj = (AdjMatrix*)malloc(sizeof(AdjMatrix));
	
	printf("����������ͼ�Ķ������ͱ���:");
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
		adj->acre[k-1][j-1]=1;
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
int visited[MAXVEX]; 
void DFS(AdjMatrix *G,int i){ //iΪ������ 
	int j;
	visited[i]=1;
	printf("%c",G->Vex[i]);
	for(j=0;j<G->vexnum	;j++){
		if(G->acre[i][j]==1&&!visited[j]){
			DFS(G,j);
		}
	}	 
}
void DFSTraveres(AdjMatrix *G){
	int i;
	for(i=0;i<G->vexnum;i++){
		if(!visited[i]){ //��δ���ʵĵ㣬����DFS���������ͨͼ��ֻ��ִ��һ�� 
			DFS(G,i);
		}		
	}	
}
int main(void){
	AdjMatrix *adj;
	adj = Create();
	printf("��ͼ����DFS�������:");
	DFSTraveres(adj);
	printf("\n");
}


