#include<stdio.h>
int main()
{
	int test,jaa;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{

		int a[100000]={0},n,i,max,min,diff;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		min=a[0];
		max=a[0];
		diff=max-min;
		int d=0,e=0;
		for(i=0;i<n;i++)
		{
			if(min>a[i])
			{
				min=a[i];
				e=i;
			}
			if(a[i]-min>diff)
			{
				diff=a[i]-min;
			}
		}
		printf("%d\n",diff);
	}
	return 0;
}

