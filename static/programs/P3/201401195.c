#include<stdio.h>
int main()
{
	int t,d;
	scanf("%d",&t);
	for(d=0;d<t;d++)
	{
		int n;
		scanf("%d",&n);
		int a[n],i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int x,min=a[0],profit=0;
		for(x=0;x<n;x++)
		{
			if(min>a[x])
				min=a[x];
			else
			{
				if(profit<a[x]-min)
					profit=a[x]-min;
			}
		}
		printf("%d\n",profit);
	}
	return 0;
}
