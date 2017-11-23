#include <stdio.h>
typedef char Elemtype;
typedef struct Node{
	Elemtype data;
	struct Node *lChild;
	struct Node *rChild;
}BiTNode,*BiTree;

char str[];
BiTree CreatBiTree(BiTree root){  //�������Ľ���(����չ���������н����Ķ�����) 
	static int count;
	char ch=str[count];
	count++;
	if(ch=='#')
		return NULL;
		
	root = (BiTNode *)malloc(sizeof(BiTNode));
	root->data = ch;
	root->lChild = CreatBiTree(root->lChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ� 
	root->rChild = CreatBiTree(root->rChild);//�Ե�ǰ�ڵ����ָ��Ϊ��һ���������ĸ�	
	return root;
}

int  count;	
int  flag; //����Ƿ��ҵ� 
	
void PreOrder(BiTree root,char ch,char *array){    //�����������Ӳ�� 
	
	if(root==NULL)
		return ;
		
	count++;	
	if(root->data==ch){
		flag = 1;
		array[count]=0;
		return ;
	}else if(flag ==0&&root!=NULL){
		array[count]=root->data;	
	}
	
	
	
	if(flag==0){
		PreOrder(root->lChild,ch,array);
		PreOrder(root->rChild,ch,array);
	}
	
	count--;
	return;
}

int main(void){
	BiTree root;
	int k;
	char a,b;
	char arrayA[10],arrayB[10];
	int i=1,j=1;
	
	gets(str);
	scanf("%c %c",&a,&b);
	root=CreatBiTree(root);

	
	PreOrder(root,a,arrayA);
	count=0;	
  	flag=0;
	PreOrder(root,b,arrayB);

	for(i=1,j=1;arrayA[i]==arrayB[j];i++,j++);
	printf("%c",arrayA[i-1]);
}