#include <stdio.h>
#define N 5
int main (void)
{
	int a[N],i,j,t;
	printf("������%d����\n",N);	
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	
	// ��֪A[0..i-1]�����򣬽�A[i]����ʹ��A[0..i]��Ϊ�µ�����������   	
	for(i=1;i<N;i++)
	{
		t=a[i];//X�Ǵ�����������ȡ��һ��Ԫ��
		for(j=i-1;t>a[j];j--)//j������������һ��Ԫ��
			a[j+1]=a[j];
		a[j+1]=t;
	}	
	for(i=0;i<N;i++)
		printf("%-5d",a[i]);
	return 0;	
}