#include <stdio.h>
#include <string.h>
#define N 20
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;


 
BiTree CreatBiTree(char *queenArray,char *centreArray,int n){
	BiTree root;
	char lqArray[N],rqArray[N];
	char lcArray[N],rcArray[N];
	int ln,rn,i,j;
	char ch;
	if(n==0)
		return NULL;
		
	ch = queenArray[n-1];
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;

	for(i=0;centreArray[i]!=ch;i++){        //������������ 
		lcArray[i] = centreArray[i];
		
	}
	ln=i;
	i++;
	for(rn=0;i<n;rn++,i++){               //������������				          
		rcArray[rn] = centreArray[i];
	}
	
	for(i=0;i<ln;i++){                   //�������ĺ��� 
		lqArray[i] = queenArray[i];
	}
	for(j=0;j<rn;j++,i++){              //�������ĺ��� 
		rqArray[j]=queenArray[i];
	}  
	
	                           
	root->lChild = CreatBiTree(lqArray,lcArray,ln);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ� 
	root->rChild = CreatBiTree(rqArray,rcArray,rn);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ�	
	return root;
}

void PreOrder(BiTree root){
	int static count;
	if(root==NULL)
		return;
		
	printf("%c",root->data);
	PreOrder(root->lChild);
	PreOrder(root->rChild);
}


int main(void){
	BiTree root;
	char queenArray[N],centreArray[N];
	gets(centreArray);
	gets(queenArray);	
	root=CreatBiTree(queenArray,centreArray,strlen(queenArray));
	PreOrder(root); 
	
}
