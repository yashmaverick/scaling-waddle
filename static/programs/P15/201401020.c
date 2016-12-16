#include<stdio.h>
int main()
{
	long long int t,n,l,k,j,i;
	long long int a[10005];
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		long long int min=a[1],pos=0;
		for(i=1;i<=n-k+1;i++)
		{
			if(pos<i)
			{
				min=a[i];
				for(j=i;j<=i+k-1;j++)
				{
					if(a[j]<=min)
					{
						min=a[j];
						pos=j;
					}
				}
				printf("%lld",min);
			}
			else
			{
				if(a[i+k-1]>min)
					printf("%lld",min);
				else
				{
					min=a[i+k-1];
					pos=i+k-1;
					printf("%lld",min);
				}
			}
			if(i<n-k+1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

