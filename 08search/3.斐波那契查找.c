#include <stdio.h>
int F[10]={0,1,1,2,3,5,8,13,21,34};
int Fibonacci_SEarch(int *a,int n,int key){
	int low,high,mid,i,k;
	low = 1;  // ��������±�ļ�¼��λ 
	high = n;  //��������±�Ϊ��¼ĩβ 
	k=0;  
	while( n>F[k]-1){ //����nλ��쳲��������е�λ�� 
		k++;	
	}
	for(i=n;i<F[k]-1;i++){ //����������ֵ��ȫ 
		a[i] = a[n];
	}
	
	while(low <= high){
		
		mid = low + F[k-1] -1;//���㵱ǰ�ָ���±� 
		
		if( key <a [mid]){ //�����Ҽ�¼С�ڵ�ǰ�ָ��¼ 
			high = mid -1; //����±�������ָ��±�mid-1�� 
			k=k-1; //쳲����������±��һλ 
		}else if(key > a[mid]){//�����Ҽ�¼���ڵ�ǰ�ָ��¼ 
			low = mid +1;//���λ�±����   ���ָ����±�mid+1�� 
			k=k-2;//쳲��������м���λ 
		}else{
			if(mid<=n){
				return mid; //�������˵��mid��Ϊ���ҵ���λ�� 
			}else{
				return n; // ��mid>n˵���ǲ�ȫ���飬����n 
			}
		} 
	}
	return 0;
}
int main (void){
	int a[11]={0,1,16,24,35,47,59,62,73,88,99};
	printf("%d\n",Fibonacci_SEarch(a,10,62));
}





