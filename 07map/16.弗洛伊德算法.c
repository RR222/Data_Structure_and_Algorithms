#include<stdio.h>
#include<stdlib.h>
#define MAXVEX 30
#define INFINITY 65535
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
	
	printf("�������������Ķ������ͱ���:");
    scanf("%d%d",&adj->vexnum,&adj->acrenum);
	
	int i;
	printf("���������Ϣ:\n");
	for(i = 0;i < adj->vexnum;i++){
		getchar();
		printf("�������%d������:",i+1);
		scanf("%c",&adj->Vex[i]);
	} 

	
	int j,k;
	int t;
	char a[3];
	for(i=0;i<adj->vexnum;i++) // ��ʼ�� 
		for(j=0;j<adj->vexnum;j++){
			if(i==j){
				adj->acre[i][j]=0;		
			}else{
				adj->acre[i][j]=INFINITY;	
			}
		}

	getchar();
	printf("\n���������Ϣ:��ab 2\n");
	for(i=0;i<adj->acrenum;i++){
		printf("�������%d���ߺ�Ȩֵ",i+1);
		scanf("%s %d",a,&t);		
		j=0;
		k=0;	
		while(adj->Vex[j++] != a[0]&&j<adj->acrenum);
		while(adj->Vex[k++] != a[1]&&k<adj->acrenum);
		adj->acre[j-1][k-1]=t;
	}
	
	printf("\n��������ڽӾ�������:\n");
	for(i=0;i<adj->vexnum;i++){
		for(j=0;j<adj->vexnum;j++){
			printf("%-6d",adj->acre[i][j]);
		}
		printf("\n");
	}
	
	return adj;
} 
//G-->ͼ��v0-->Դ�㣬P[v][w]��ʾv���������w���·����D[v][w]��ʾv���������w�Ĵ�Ȩ·�����Ⱥ� 
void ShortestPath_Floyd(AdjMatrix *G,int P[MAXVEX][MAXVEX],int D[MAXVEX][MAXVEX]){
	int v,w,k;
	
	//��ʼ��D��P 
	for(v=0;v<G->vexnum;v++){
		for(w=0;w<G->vexnum;w++){
			D[v][w] = G->acre[v][w];
			P[v][w] = w; 
		}
	}
	
	for(k=0;k<G->vexnum;k++){
		for(v=0;v<G->vexnum;v++){
			for(w=0;w<G->vexnum;w++){
				
				if(D[v][w]>D[v][k]+D[k][w]){ //��������±�Ϊk�Ķ���·����ԭ������·�����̣������ 
					D[v][w] = D[v][k]+ D[k][w];
					P[v][w] = P[v][k]; //·�����þ����±�Ϊk�Ķ��� 
				}
			}
		}
	}

}

int main(void){
	AdjMatrix *adj;
	adj=Create();
	int P[MAXVEX][MAXVEX],D[MAXVEX][MAXVEX];
	ShortestPath_Floyd(adj,P,D); 
	
	int v,w;

	printf("����D:\n");
	for(v=0;v<adj->vexnum;v++){
		for(w=0;w<adj->vexnum;w++){
			printf("%-4d",D[v][w]);
		}
		printf("\n"); 
	} 
	
	printf("\n����P:\n");
	for(v=0;v<adj->vexnum;v++){
		for(w=0;w<adj->vexnum;w++){
			printf("%-4d",P[v][w]);
		}
		printf("\n"); 
	} 
	
}