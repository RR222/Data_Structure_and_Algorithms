#include <stdio.h>
//str1-->������str2-->�Ӵ���
//�����Ӵ���������pos���ַ�֮���λ�á� ��������ڣ�����-1 
int Index(char *str1,char *str2,int pos){
	
	int i=pos;  
	int j=0; 
	
	while(str1[i]&&str2[j]){
		
		if(str1[i]==str2[j]){ //�����ʱ�������Ӵ���ȣ��������±Ƚ� 
			i++;
			j++; 
		}else{
			i=i-j+2;   //�������� i���˵��ϴ�ƥ�����λ��
			j=0;       //j���˵��Ӵ�����λ�� 
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
	printf("�������Ӵ�\n"); 
	gets(str2);
	printf("%d\n",Index(str1,str2,0));
}