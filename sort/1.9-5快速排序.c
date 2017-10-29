#include <stdio.h>
int a[20],n;
void quichsort(int left,int right)
{
	int i,j,t,temp;
	if(left>right)
		return;	
	
	temp=a[left];//tempΪ��׼��
	i=left;
	j=right;
	while(i!=j)
	{
		while(a[j]>=temp&&i<j)
			j--;
		while(a[i]<=temp&&i<j)
			i++;
		if(i<j)//����ڱ�û������,���� 
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t; 
		} 
	} 
	a[left]=a[i];//��׼����λ 
	a[i]=temp;
	
	quichsort(left,i-1);
	quichsort(i+1,right); 
}
int main(void)
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	quichsort(0,n-1);
	
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
} 
/* ˼·����������Ϻ�һ�������ұ�ȫ���Ǳ���С���������ȫ�Ǳ�����������������ԭ����п���
���裺1�����������������׼����һ�ߴ�����һ������С������һ�ߴ�����һ�������������
      2�����������ڱ�û������������
	  3�����еݹ飬�����Ի�׼����ߺ��ұߵ��������������̣�ֱ������ȥ������ֻ��һ���� 

˼����Ϊ��ֻ�ܽ��д���߿�ʼ����
		���� 3 1 2 5 4����
		�������߿�ʼ�ң�i�ҵ���Ϊ5��j�޷���ȥ��i������5�ĵط���5��3��������������5 1 2 3 4
		��������û�дﵽĿ�ģ���׼��3�ұߴ��ڱ�������� 
*/ 
