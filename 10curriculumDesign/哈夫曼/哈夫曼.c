#include <stdio.h>
#include <string.h>
#define N 54
#define M 2*N-1
#define IO "souceFile.txt"
#define Code "CodeFile"
#define Decode "DecodeFile"
typedef struct{
	int weight;
	char data; 
	int parent,Lchild,Rchild;
}HTNode,HuffmanTree[M+1];

int bucket[128];//��¼�ַ�����Ƶ�� 
int count; //��¼�����ַ�������
 
void statistics(){
	FILE *fp;
	char ch;
	fp = fopen(IO,"r"); 
	if(fp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
    while((ch=fgetc(fp))!=EOF){
    	bucket[ch]++;	
    }
    int i; 
    printf("�����ַ������������:\n"); 
    for(i=0;i<128;i++){
    	if(bucket[i]){
    		count++;
    		if(i==10){
		    	printf("%d,�س� -->%d\n",i,bucket[i]);
		    }else if(i==13){
    			printf("%d,���� -->%d\n",i,bucket[i]);
    		}else{
		    	printf("%d,%c -->%d\n",i,i,bucket[i]);
		    }
	    	
	    } 	
    } 
    fclose(fp);
}
void seek(HuffmanTree ht,int n,int *s1,int *s2){//Ѱ��ht��i֮ǰ��С������Ԫ���±꣬s1<s2; 
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
void CrtHuffmanTree(HuffmanTree ht){ //���� 
	int m=2*count-1;
	int i,j;
	int s1,s2;
	for(i=0,j=0;i<128;i++){
		if(bucket[i]){
			ht[j].weight=bucket[i];
			ht[j].data=i;
			ht[j].parent=-1;
			ht[j].Lchild=-1;
			ht[j].Rchild=-1;
			j++;
		}
	} 
	
	for(;j<m;j++){
		ht[j].weight=0;
		ht[j].parent=-1;
		ht[j].Lchild=-1;
		ht[j].Rchild=-1; 
	}	
	for(j=count;j<m;j++)
	{
		seek(ht,j,&s1,&s2);	 //Ѱ��ht��i֮ǰ��С������Ԫ���±꣬s1<s2; 
		ht[s1].parent=j;
		ht[s2].parent=j;
		ht[j].weight = ht[s1].weight+ht[s2].weight;
		ht[j].Lchild = s1;
		ht[j].Rchild = s2;
	}
	
	for(i=0;i<m;i++){
		printf("%c %d %d %d %d\n",ht[i].data,ht[i].weight,ht[i].parent,ht[i].Lchild,ht[i].Rchild);
	}
}
void Codinghuffman(HuffmanTree	ht){ //���� 
	FILE *infp,*outfp;
	infp = fopen(IO,"r"); 
	if(infp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
	outfp = fopen(Code,"wb"); 
	if(outfp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
	 
 
 	int i,j;
	int p,q;
	int str1[200];
	char ch; 
 	while((ch=fgetc(infp))!=EOF){
    	for(p=0;ht[p].data!=ch&&p<count;p++); //�ҵ���Ԫ���ڹ��������е�λ�� 
    	
    	
    	for(j=0;ht[p].parent!=-1;j++){     
			
			q=ht[p].parent;
			if(p==ht[q].Lchild){
				str1[j]='0';
			}else{
				str1[j]='1';
			}
			p=ht[p].parent;
		}
		
		for(j=j-1;j>=0;j--){
			fputc(str1[j],outfp);
		}
    }
	fclose(infp);
	fclose(outfp);			 
}
void DecodeHuffmanTree(HuffmanTree ht){  //���� 

	FILE *infp,*outfp;
	infp = fopen(Code,"rb"); 
	if(infp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
	outfp = fopen(Decode,"w"); 
	if(outfp==NULL)
    {
        printf("�ļ���ʧ��\n");
        exit(0);
    }
	
	int i,j;
	int p=2*count-2; // p��ǰ�ڵ�
	char ch;
	while((ch=fgetc(infp))!=EOF){
		if(ch=='1'){
			p = ht[p].Rchild;
		}else if(ch=='0'){
			p = ht[p].Lchild;
		}
		if(ht[p].Lchild==-1&&ht[p].Rchild==-1){  //��ǰ�ֶν������ 
			printf("%c",ht[p].data);
			fputc(ht[p].data,outfp);
			p =2*count-2; 
		}
	} 
	fclose(infp);
	fclose(outfp);
}
void OutHuffmanTree(){
	
}
int main(void){
	statistics();
	HuffmanTree ht[M+1];
	CrtHuffmanTree(ht);
	Codinghuffman(ht); 
	DecodeHuffmanTree(ht);
	OutHuffmanTree(ht);
}