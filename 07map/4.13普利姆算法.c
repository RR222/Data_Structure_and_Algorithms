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
	
	printf("���������Ķ������ͱ���:");
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
		adj->acre[k-1][j-1]=t;
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

//Prim�㷨����С������ 
void MiniSpanTree_Prim(AdjMatrix *G){
	int min,i,j,k;
	int adjvex[MAXVEX];//������ض����±�
	int lowcost[MAXVEX];//������ض����Ȩֵ
	
	lowcost[0]=0; //��ʼ����һ��ȨֵΪ0����v0������������
	adjvex[0]=0; //��ʼ����һ�������±�Ϊ0
	
	for(i=1;i<G->vexnum;i++){
		lowcost[i]=G->acre[0][i]; //����v0������ص��Ȩֵ����lowcost������
		adjvex[i]=0;  //����ʼ��Ϊvo���±� 
	} 
	
	for(i=1;i<G->vexnum;i++){
		min = INFINITY; //��ʼ��ȨֵΪ����
		j=1;k=0;
		
		//Ѱ�ҵ�ǰȨֵ��С�ı� 
		while(j<G->vexnum){
			if(lowcost[j]!=0&&lowcost[j]<min){//���Ȩֵ��Ϊ0��С��min
				min = lowcost[j];
				k=j; 
			}	
			j++;
		} 
		
		printf("(%c,%c)",G->Vex[adjvex[k]],G->Vex[k]);//��ӡ��ǰ������Ȩֵ��С�ı�
		lowcost[k]=0;//����ǰ�����Ȩֵ��Ϊ0����ʾ�������
		
		
		//����lowcost��adjvex���� 
		for(j=1;j<G->vexnum;j++){
			if(lowcost[j]!=0&&G->acre[k][j]<lowcost[j]){
				lowcost[j]=G->acre[k][j];
				adjvex[j]=k;
			}
		} 
	} 
} 
int main(void){
	AdjMatrix *adj;
	adj = Create();
	MiniSpanTree_Prim(adj);
	printf("\n"); 
}


	