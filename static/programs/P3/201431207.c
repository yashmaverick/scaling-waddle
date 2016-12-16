#include<stdio.h>
int main()
{
	int test,i;
	scanf("%d",&test);
	for(i=0;i<test;i++)
	{
		int a,b,c,d=0,arr[100000],z,i,max,profit=0;
		scanf("%d",&a);
		for(i=0;i<a;i++)
		{
			scanf("%d",&arr[i]);
		}
		b=a-2;
		max=arr[a-1];
		while(b>=0)
		{
			if(max<arr[b])
				max=arr[b];
			if(max-arr[b]>profit)
			{
				profit=max-arr[b];
			}
			b--;
		}
		printf("%d\n",profit);
	}
	return 0;
}
