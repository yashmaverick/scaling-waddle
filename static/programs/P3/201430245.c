#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		int n,i;
		long long  int a[100000],max,min,profit=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
		scanf("%lld",&a[i]);
		}
		min=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]>min)
			{
				max=a[i]-min;
				if(max>profit)
				{
					profit=max;
				}
			}
			else if(a[i]<min)
			{
				min=a[i];
			}
		}
		printf("%lld\n",profit);
		t--;
	}
return 0;
}
