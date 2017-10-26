#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0 
#define MAXSIZE 10
typedef int Elemtype;

typedef struct{
	Elemtype date[MAXSIZE];
	int quelen,rear; 
}CSeQeue;

//��ʼ��
CSeQeue *InitSeQueue(){
	CSeQeue *qS;
	qS=(CSeQeue *)malloc(sizeof(CSeQeue));
	qS->rear=qS->quelen=0;//��ʼ��ͷ��1 
	return qS;
}
//���
int InSeQueue(CSeQeue *qS ,Elemtype x){
	
	if(qS->quelen==MAXSIZE){
		printf("����\n");
		return FALSE;
	}
	qS->rear=(qS->rear+1)%MAXSIZE;
	qS->date[qS->rear]=x;
	qS->quelen++;
	return TRUE;
} 
//�п�
int EmptySeQueue(CSeQeue *qS){
	
	if(qS->quelen == 0)
		return TRUE;
	return FALSE;
} 
//���� 
int QutSeQueue(CSeQeue *qS ,Elemtype *x){
	int i;
	if(!EmptySeQueue(qS)){
		qS->quelen--;
		i=(qS->rear - qS->quelen + MAXSIZE)%MAXSIZE;
	
		*x = qS->date[i];
		return TRUE;
	}
	printf("�ӿ�\n");
	return FALSE; 
} 

int main(void){
	CSeQeue *qS;
	qS=InitSeQueue();
	int i,x;
	int j;
	for(i=0;i<15;i++){
		printf("%d %d %d\n",i,qS->quelen,qS->rear);
		InSeQueue(qS,i);
	}
	for(i=0;i<15;i++){
		QutSeQueue(qS,&x);
		QutSeQueue(qS,&x);
		InSeQueue(qS,16);
		printf("\n%d %d %d\n",x,qS->quelen,qS->rear);
		for(j=0;j<10;j++)
			printf("%d ",qS->date[j]);
	}
}