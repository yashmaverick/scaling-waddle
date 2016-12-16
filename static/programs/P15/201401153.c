#include<stdio.h>
typedef long long ll;
int main()
{
	ll t,n,k,i,j,min;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&n,&k);
		ll a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		min=a[0];
		for(i=0;i<k;i++)
		{		
			if(min>a[i])
				min=a[i];
		}
		if(n-k+1==1)
			printf("%lld",min);
		else
			printf("%lld ",min);
		for(i=1;i<=n-k;i++)
		{
			if(a[i-1]!=min)
			{
				if(a[i+k-1]<min)
					min=a[i+k-1];
			}
			else
			{
				min=a[i];
				for(j=i;j<=i+k-1;j++)
				{
					if(a[j]<min)
						min=a[j];
				}
			}
			if(i!=n-k)
				printf("%lld ",min);
			else
				printf("%lld",min);
		}	
		printf("\n");
	}
	return 0;
}
