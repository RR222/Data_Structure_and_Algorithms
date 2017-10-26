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
void PrintPolyn(LinkList pHead){
	LNode *pt;
	int i;
	
	while(pHead->next->next&&pHead->next->coef==0){
		pHead=pHead->next;	
	}
	if(pHead->next->next==NULL&&pHead->next->coef==0){
		printf("0");
		return;
	}
	pt=pHead->next;
	while(pt){
		if(pt==pHead->next){
			if(pt->expn==0){
				printf("%d",pt->coef);
			}else if(pt->expn==1){
				printf("%dX",pt->coef);
			}else{
				printf("%dX^%d",pt->coef,pt->expn);
			}
		}
		else{
			if(pt->coef==0){
				
			}else if(pt->expn==0){
				printf("+%d",pt->coef);
			}else if(pt->expn==1){
				if(pt->coef<0){
					printf("%dX",pt->coef);
				}else{
					printf("+%dX",pt->coef);
				}
			}else if(pt->coef<0){
				printf("%dX^%d",pt->coef,pt->expn);
			}else{
				printf("+%dX^%d",pt->coef,pt->expn);
			}				
		}
		pt=pt->next;
	}	
	printf("\n");
}
int add(LinkList aHead, LinkList bHead){
	LinkList cHead=aHead;
	LNode *La=aHead->next;
	LNode *Lb=bHead->next;
	LNode *Lc=cHead;
	while(La&&Lb){ //3. �ظ�1,2֪��La����Lb�ƶ�������β��
		if((La->expn)<(Lb->expn)){ //1. �Ƚ�La��Lb������ĸ�С�����ĸ�������Lc���棬Lc�����ָ�����
			Lc->next=La;
			Lc=La; 
			La=La->next;
		}else if((La->expn)==(Lb->expn)){//2.���������С��ͬ����ϵ����Ӻ�������Lc���棬La��Lb������
			La->coef = La->coef + Lb->coef;
			Lc->next =La;
			Lc=La;
			La=La->next; 
			Lb=Lb->next;	
		}
		else{
			Lc->next=Lb;
			Lc=Lb;
			Lb=Lb->next;
		} 
	} 
	if(La) //4.��δ�����������������Lc��
		Lc->next=La;
	else
		Lc->next=Lb;
}
int main(void){
	LinkList aHead,bHead;
	int aiCound,biCound;
	scanf("%d",&aiCound);
	aHead=CreatePoly(aiCound);
	
	scanf("%d",&biCound);
	bHead=CreatePoly(biCound);
	PrintPolyn(aHead);
	PrintPolyn(bHead);
	add(aHead,bHead);
	PrintPolyn(aHead);
	return 0;
}