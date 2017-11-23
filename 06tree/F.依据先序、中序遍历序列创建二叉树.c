#include <stdio.h>
#include <string.h>
#define N 20
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;


 
BiTree CreatBiTree(char *frontArray,char *centreArray,int n){
	BiTree root;
	char lfArray[N],rfArray[N];
	char lcArray[N],rcArray[N];
	int ln,rn,i,j;
	char ch;
	if(n==0)
		return NULL;
		
	ch = frontArray[0];
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;

	for(i=0;centreArray[i]!=ch;i++){        //�������ĺ��� 
		lcArray[i] = centreArray[i];
		
	}
	ln=i;
	i++;
	for(rn=0;i<n;rn++,i++){               //�������ĺ���				          
		rcArray[rn] = centreArray[i];
	}
	
	for(i=0;i<ln;i++){                   //������������ 
		lfArray[i] = frontArray[i+1];
	}
	
	for(j=0;j<rn;j++,i++){              //������������ 
		rfArray[j]=frontArray[i+1];
	}  
	
	                           
	root->lChild = CreatBiTree(lfArray,lcArray,ln);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ� 
	root->rChild = CreatBiTree(rfArray,rcArray,rn);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ�	
	return root;
}

void PostOrder(BiTree root){
	if(root==NULL)
		return;
		
	PostOrder(root->lChild);
	PostOrder(root->rChild);
	printf("%c",root->data);
}


int main(void){
	BiTree root;
	char frontArray[N],centreArray[N];
	gets(frontArray);
	gets(centreArray);
	root=CreatBiTree(frontArray,centreArray,strlen(frontArray));
	PostOrder(root); 
	
}
