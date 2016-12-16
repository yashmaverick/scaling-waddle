#include<stdio.h>
int main()
{
	long long int t,x,n,i,j,k;
	scanf("%lld",&t);
	for(x=0;x<t;x++)
	{
		scanf("%lld",&n);
		scanf("%lld",&k);
		long long int a[n],min;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		min=0;
		for(i=1;i<k;i++)
		{
			if(a[min]>a[i])
			{
				min=i;
			}
		}
		if(k!=n)
			printf("%lld ",a[min]);
		else
			printf("%lld",a[min]);
		long long int flag=0;
		for(i=k;i<n;i++)
		{
			if(i==n-1)
			{
				flag=1;
			}
			if(min!=i-k)
			{
				if(a[min]<a[i])
				{
					if(flag==0)
						printf("%lld ",a[min]);
					else
						printf("%lld",a[min]);
				}
				else
				{
					if(flag==0)
					{
						printf("%lld ",a[i]);
					}
					else
					{
						printf("%lld",a[i]);
					}
					min=i;
				}
				continue;
			}
			min=i-k+1;
			for(j=i-k+2;j<=i;j++)
			{
				if(a[min]>a[j])
					min=j;
			}
			if(flag==0)
				printf("%lld ",a[min]);
			else
				printf("%lld",a[min]);
		}
		printf("\n");
	}
	return 0;
}
