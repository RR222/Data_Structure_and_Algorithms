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
//G-->ͼ��v0-->Դ�㣬P[v]��ʾvǰ�������±�,D[v]��ʾV0��v�����·�����Ⱥ� 
void ShortestPath_Dijkstra(AdjMatrix *G,int v0,int *P,int *D){
	int v,w,k,min;
	int book[MAXVEX]; //��Ƕ���v�Ƿ����ҵ����·��
	
	for(v=0;v<G->vexnum;v++){  //��ʼ������ 
 		book[v]=0;
		P[v]=0;
		D[v]=G->acre[0][v]; 
	} 
	
	D[v0]=0; //v0��v0����Ϊ0 
	book[v0]=1;
	
	//��ʼ��ѭ����ÿ�����v0��ĳ���������̾���
	for(v=1;v<G->vexnum;v++){
		min=INFINITY;
		
		for(w=0;w<G->vexnum;w++){  //Ѱ�ҵ���v0������̵ĵ� 
			if(!book[w]&&D[w]<min){
				k=w;
				min=D[w];
			}
		}
		
		book[k]=1; //����ʱ�ҵ��ĵ��� 
		for(w=0;w<G->vexnum;w++){ //���ݱ����Ҵ�v0��̵ĵ㣬���������㵽v0�ľ��� 
			
			//�����������k��·��������·�����̵Ļ�
			if(!book[w]&&(min+G->acre[k][w]<D[w])){
				D[w]=min+G->acre[k][w];
				P[w]=k;
			} 
		} 
	} 
}

int main(void){
	AdjMatrix *adj;
	adj=Create();
	int P[MAXVEX],D[MAXVEX];
	ShortestPath_Dijkstra(adj,0,P,D); 
	
	int v,w;

	for(v=1;v<adj->vexnum;v++){
		printf("v%d",v+1);
		w=P[v]; 
		while(w>0){
			printf("<--v%d",w+1);
			w=P[w]; 
		}
		printf("<--v1  ",w+1);	
		printf("�ܳ���:%d\n",D[v]);
	} 
}