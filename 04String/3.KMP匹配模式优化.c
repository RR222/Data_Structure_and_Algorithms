#include <stdio.h>
//�����Ӵ�str2��next����
void get_next(char *str2,int *nextval){
	int i,k;
	i=0;
	k=-1;
	nextval[0]=-1;
	while(str2[i]){
		
		if(k==-1||str2[i]==str2[k]){ //str2[i]-->��׺�ĵ����ַ� 
			i++;                     //str2[j]-->ǰ׺�ĵ����ַ�  
			k++;
			if(str2[i]!=str2[k])
				nextval[i]=k;
			else
				nextval[i] = nextval[k];//��ǰ�ַ���ǰ׺�ַ���ͬ����ǰ׺
									    //nextvalֵ����nextval��i��λ�� 
		}else{
			k=nextval[k];
		}
	}
} 
int Index_KMP(char *str1,char *str2,int pos){
	
	int i=pos;  
	int j=0; 
	int nextval[100]; 
	get_next(str2,nextval);//�����Ӵ���next���� 
	
	printf("\n�Ӵ�nextval����:\n");
	int k; 
	for(k=0;str2[k];k++)
		printf("%d ",nextval[k]); 
	
	while((str1[i]&&str2[j])||j==-1){
		
		if(j==-1||str1[i]==str2[j]){ //�����ʱ�������Ӵ���ȣ��������±Ƚ� 
			i++;
			j++; 
		}else{
			//i=i-j+2;   //i����Ҫ���� 
			//j=0;        
			j=nextval[j]; //j���˵���Ӧ��next�е�ֵ   
		}
	}
	
	if(str2[j]==0) //����˳�ѭ��ʱ��jָ���Ӵ�ĩβ����˵��ƥ��ɹ� 
		return i-j;
	else
		return -1; 
}
int main(void){
	char str1[100];
	char str2[30];
	printf("����������:\n");
	gets(str1);
	printf("\n�������Ӵ�\n"); 
	gets(str2);
	printf("\n\n�Ӵ���������%d��\n",Index_KMP(str1,str2,0));
}