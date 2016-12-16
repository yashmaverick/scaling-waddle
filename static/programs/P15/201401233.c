#include<stdio.h>
#include<math.h>
int main()
{
	long long int t,x;
	scanf("%lld",&t);
	for(x=0;x<t;x++)
	{
		long long int n,k;
		scanf("%lld %lld",&n,&k);
		long long int a[n+1],i=0,b[n];
		for(i=1;i<(n+1);i++)
		{
			scanf("%lld",&a[i]);
		}
		long long int j,min=a[1];
		for(j=1;j<1+k;j++)
		{
			if(min>a[j])
				min=a[j];
		}
		printf("%lld",min);
		long long int flag=0;
		if(n!=k)
			printf(" ");
		for(i=2;i<=n-k+1;i++)
		{
			if(a[i-1]==min)
			{
				min=a[i];
				for(j=i;j<i+k;j++)
				{
					if(min>a[j])
						min=a[j];
				}
			}
			else
			{
				if(a[i+k-1]<min)
					min=a[i+k-1];
			}
			printf("%lld",min);
			if(i==n-k+1)
				flag=1;//printf("%d",min);
			if(flag!=1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}

