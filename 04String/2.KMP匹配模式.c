#include <stdio.h>
//计算子串str2的next数组
void get_next(char *str2,int *next){
	int i,k;
	i=0;
	k=-1;
	next[0]=-1;
	while(str2[i]){
		
		if(k==-1||str2[i]==str2[k]){ //str2[i]-->后缀的单个字符 
			i++;                     //str2[j]-->前缀的单个字符  
			k++;
			next[i]=k;
		}else{
			k=next[k];
		}
	}
} 
int Index_KMP(char *str1,char *str2,int pos){
	
	int i=pos;  
	int j=0; 
	int next[100]; 
	get_next(str2,next);//计算子串的next数组 
	
	printf("\n子串next数组:\n");
	int k; 
	for(k=0;str2[k];k++)
		printf("%d ",next[k]); 
	
	int p =0;
	while((str1[i]&&str2[j])||j==-1){
		
		p++;
		if(j==-1||str1[i]==str2[j]){ //如果此时主串和子串相等，继续向下比较 
			i++;
			j++; 
		}else{
			//i=i-j+2;   //i不需要回溯 
			//j=0;        
			j=next[j]; //j回退到对应的next中的值   
		}
		printf("%d\n",p);
	}
	
	if(str2[j]==0) //如果退出循环时，j指向子串末尾。则说明匹配成功 
		return i-j;
	else
		return -1; 
}
int main(void){
	char str1[100];
	char str2[30];
	printf("请输入主串:\n");
	gets(str1);
	printf("\n请输入子串\n"); 
	gets(str2);
	printf("\n\n子串在主串的%d处\n",Index_KMP(str1,str2,0));
}