#include <stdio.h>
#define N 5
int main (void)
{
	int a[N],i,j,t,f;
	printf("������%d����\n",N);	
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N-1;i++)
	{
		t=i;				
		for(j=i+1;j<N;j++)
			if(a[j]>a[t])
				t=j;     //Ѱ�����ֵ�±� 
		if(t!=i)//���� 
		{
			a[i]=a[i]+a[t];
			a[t]=a[i]-a[t];
			a[i]=a[i]-a[t];
		}
	}
	for(i=0;i<N;i++)
		printf("%-5d",a[i]);
	return 0;
}