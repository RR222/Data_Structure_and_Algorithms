#include <stdio.h>
#define N1 5
#define N2 100
int main (void)
{
	int a[N1],i,b[N2]={0};
	printf("������%d���ڵ�%d������\n",N2,N1);
	for(i=0;i<N1;i++)
		scanf("%d",&a[i]);
	for(i=0;i<N1;i++)
		b[a[i]]++;//��ӦͰ+1 
	
	for(i=0;i<N2;i++)//��� 
		while(b[i])
		{
			printf("%-5d",i);
			b[i]--;		
		}
}
