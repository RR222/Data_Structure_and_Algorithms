#include <stdio.h>
//˳�����, aΪ���ҵ�����(�����1��ʼ�洢)��nΪ���鳤��,keyΪҪ���ҵĹؼ���
int Sequential_Search(int *a,int n,int key){
	int i;
	for(i=1;i<n;i++){
		if(a[i] == key){
			return i;
		} 
	}
	return 0;
} 

//˳�����, aΪ���ҵ�����(�����1��ʼ�洢)��nΪ���鳤��,keyΪҪ���ҵĹؼ���
int Sequential2_Search(int *a,int n,int key){
	int i;
	a[0]=key;
	for(i=n;a[i]!=key;i--);
	
	return i;
} 
int main (void){
	int a[11]={0,1,16,24,35,47,59,62,73,88,99};
	printf("%d\n",Sequential_Search(a,10,62));
	printf("%d\n",Sequential2_Search(a,10,62));
}
