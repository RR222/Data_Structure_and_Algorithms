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
	
	printf("������ͼ�Ķ������ͱ���:");
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

void Statistics(AdjMatrix *adj){
	int i,j;
	int countA,countB;
	for(i=0;i<adj->vexnum;i++){
		countA=0;
		countB=0;
		for(j=0;j<adj->acrenum;j++){  
			if(adj->acre[i][j]==1){//����
				countA++;
			} 
			if(adj->acre[j][i]==1){//��� 
				countB++; 
			}
		} 
		printf("����%c,����Ϊ%d,���Ϊ%d\n",adj->Vex[i],countA,countB);
	} 
}
int main(void){
	AdjMatrix *adj;
	adj = Create();
	Statistics(adj);
}


