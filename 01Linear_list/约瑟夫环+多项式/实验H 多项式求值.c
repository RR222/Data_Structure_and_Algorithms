#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int coef;
    int expn;
    struct node *next;
}LNode,*LinkList;
LinkList CreatePoly(int iCound){
    LinkList pHead;
    LNode *pNew,*pEnd;
    int i;
    char a;
     
    pEnd=pHead = (LinkList)malloc(sizeof(LinkList));
    pHead->next=NULL;
 
    fflush(stdin);
    for(i=0;i<iCound+1;i++){
        pNew = (LinkList)malloc(sizeof(LinkList)) ;
        scanf("%c%d%c%d%c)",&a,&pNew->coef,&a,&pNew->expn,&a);
         
        pEnd->next = pNew;
        pEnd = pNew;
    }
    pNew->next =NULL;
    pHead=pHead->next;
    return pHead;
}

int f1(int n ,int x){// Ȼ�����ÿһ���ڵ�ľ���ֵ���۳�
	int sum=1;
	int i;
	for(i=0;i<x;i++)
		sum=sum*n;	
	return sum;
}
int count(int x,LinkList pHead){
	int sum=0;
	LNode *pt=pHead->next;
	while(pt){
		sum+=pt->coef*f1(x,pt->expn);//��X����ÿһ���ڵ���ۼ�
		pt=pt->next;
	}
	return sum;
} 
int main(void){
    LinkList aHead,bHead;
    int aiCound,x;
    scanf("%d",&aiCound);
    aHead=CreatePoly(aiCound);
    scanf("%d",&x);
	printf("%d",count(x,aHead));
    return 0;
}