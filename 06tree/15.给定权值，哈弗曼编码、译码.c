#include <stdio.h>
#define N 30
#define M 2*N-1
typedef struct{
	int weight;
	char data; 
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];
void seek(HuffmanTree ht,int n,int *s1,int *s2){  //Ѱ��ht��i֮ǰ��С������Ԫ���±꣬s1<s2; 
	int i,j;
	for(i=0;i<n&&ht[i].parent!=-1;i++); //s1,s2�ĳ�ʼ�� 
	j=i;
	i++;
	for(;i<n&&ht[i].parent!=-1;i++);
	*s1 = ht[i].weight<ht[j].weight?i:j;
	*s2 = ht[i].weight<ht[j].weight?j:i;
	i++;
	while(i<n){
		if(ht[i].parent!=-1){
			
		}else if(ht[i].weight<ht[*s1].weight){
			*s2 = *s1;
			*s1 = i;
		}else if(ht[i].weight<ht[*s2].weight){
			*s2 = i;
			
		}
		i++; 
	}
}
void CrtHuffmanTree(HuffmanTree	ht,int n){ //������������ 
	int m=2*n-1;
	int i;
	int s1,s2;
	for(i=0;i<n;i++){       //��ʼ�� 
		scanf("%d",&ht[i].weight);
		ht[i].data = 'A'+i; 
		ht[i].parent=-1;
		ht[i].Lchild=-1;
		ht[i].Rchild=-1; 
	}	
	for(i=n;i<m;i++){
		ht[i].weight=0;
		ht[i].parent=-1;
		ht[i].Lchild=-1;
		ht[i].Rchild=-1; 
	}
	
	for(i=n;i<m;i++)
	{
		seek(ht,i,&s1,&s2);	 //Ѱ��ht��i֮ǰ��С������Ԫ���±꣬s1<s2; 
		ht[s1].parent=i;  //����s1��s2��˫�� 
		ht[s2].parent=i;  
		ht[i].weight = ht[s1].weight+ht[s2].weight;
		ht[i].Lchild = s1;
		ht[i].Rchild = s2;
	}

}
void codinghuffman(HuffmanTree	ht,int n){ //�������е�Ҷ�ӽڵ� 
	int i,j;
	char str[N];
	int p,q; //p��ǰ�ڵ㣬q��p��˫�׽ڵ� 
	for(i=0;i<n;i++){
		p=i;
		for(j=0;ht[p].parent!=-1;j++){     
			
			q=ht[p].parent;
			if(p==ht[q].Lchild){ //�������ڵ�,��Ϊ0 
				str[j]='0';
			}else{           //������ҽڵ�,��Ϊ1 
				str[j]='1';
			}
			p=ht[p].parent;
		}
		
		printf("%c:",ht[i].data); //��ӡ��� 
		for(j=j-1;j>=0;j--){
			printf("%c",str[j],j);
		}
		printf("\n");
	}
} 

void aCodinghuffman(HuffmanTree	ht){ //�����ַ��� 
	int i,j;
	char in[N];
	char str[N];
	int p,q;
	getchar();
	gets(in);	
	for(i=0;in[i];i++){ //����ÿ����ĸ 
		p=in[i]-'A'; //ȷ����Ҷ�ӽڵ�洢��λ��,�����ݾ���������� 
		for(j=0;ht[p].parent!=-1;j++){    //����ÿ����ĸ 
			
			q=ht[p].parent;
			if(p==ht[q].Lchild){ //��������� 
				str[j]='0';
			}else{            //������Һ��� 
				str[j]='1';
			}
			p=ht[p].parent;
		} 
		for(j=j-1;j>=0;j--){  //��ӡ��� 
			printf("%c",str[j],j);
		}
	}
	printf("\n");
} 

void decodeHuffmanTree(HuffmanTree ht,int n){ //���� 
	int i,j;
	char str[N];
	int p=2*n-2; // p��ǰ�ڵ㣬p��ǰ�ڵ����
	 
	gets(str);
	for(i=0;str[i];i++){
		if(str[i]=='1'){
			p = ht[p].Rchild;
		}else if(str[i]=='0'){
			p = ht[p].Lchild;
		}
		if(ht[p].Lchild==-1&&ht[p].Rchild==-1){  //��ǰ�ֶν������ 
			printf("%c",ht[p].data);
			p =2*n-2; 
		}
	} 
} 
int main(){
	HuffmanTree ht[M+1];
	CrtHuffmanTree(ht,6);//���� 
	codinghuffman(ht,6);
	aCodinghuffman(ht);
	decodeHuffmanTree(ht,6);
}