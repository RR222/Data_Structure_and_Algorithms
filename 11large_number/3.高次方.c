#include <stdio.h>
#include <string.h>

#define Max 100
void postpone(char a[],int n){ //�ú� 
	int i;
	int al = strlen(a);
	
	for(i=0;a[i];i++){
		a[n-al+i] = a[i];
		a[i] = 0;
	}
}

void prin(char a[],int n){  //����ú��ַ��� 
	int i;
	for(i=0;i<n;i++){
		if(a[i]!=0){
			printf("%c",a[i]);
		}
	} 
	
	printf("\n");
}

void add(char a[],char b[],char c[]){  //�ӷ����������a������ 
	
	int i,num,fi=0;
	for(i=Max-1;a[i]!=0||b[i]!=0||fi!=0;i--){
		a[i]==0?a[i]='0':0;
		
		b[i]==0?b[i]='0':0;
		
		num = a[i]-'0'+b[i]-'0'+fi;
		c[i]= num%10 +'0';
		fi = num/10;
	}
}

void multiplication (char a[],int n,char c[]){  //��λ�� X һλ��(0~10) ,�������c�� 

	int i,num,fi=0;
	for(i=Max-1;a[i]!=0||fi!=0;i--){
		a[i]==0?a[i]='0':0;
	
		num = (a[i]-'0')*n+fi;
		c[i]= num%10 +'0';
		fi = num/10;
		
	}
} 

void power(char background[],int index,char a[]){  //�˷�(������ָ�������) 
	int i,j,fi,num;
	
	char b[Max] = {0};//�ݴ�ÿ�εĽ�� 
	a[Max-1]='1';
	
	for(i=0;i<index;i++){
		fi=0;
	
		
		for(j = 0;j<strlen(background);j++){
		 	
	        char c[Max] = {0};//�ݴ�ÿ�εĽ�� 
			multiplication(a,background[j]-'0',c); //c = a * background[j]	
			
			multiplication(b,10,b);//b = b*10
			add(b,c,b); //b = b+c;
			
		}	
		
		for(j=0;j<100;j++){  //a=b
			a[j] = b[j];
			b[j] = 0;
		}
	} 
	
}

int main(void){
	char a[Max]={'2'},b[Max]={0};

	printf("%s^5=",a) ;
	power(a,32,b);
	prin(b,Max);
	return 0;
} 