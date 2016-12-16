#include<stdio.h>
int main()
{
	long long int n;
	scanf("%d",&n);
	while(n!=0)
	{
		long long int i;
		long long int a[n],lmin=-1,rmin=n;
		long long int MIN;
		long long int max=0,ans;
		long long int j,k;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		MIN=a[0];
		for(i=0;i<n;i++)
		{
			if(a[i]<MIN)
				MIN=a[i];
		}
		for(i=1;i<n;i++)
		{

			if(a[i]<a[0])
				break;
		}
		rmin=i;
		ans=rmin*a[0];
		max=ans;
		for(i=1;i<=n-2;i++)
		{
			if(a[i]==MIN)
			{
				ans=MIN*n;
				if(ans>max)
					max=ans;
			}
			else if(a[i-1]==a[i])
			{
				ans=(rmin-lmin-1)*a[i];

			}
			else if(a[i-1]<a[i])
			{
				lmin=i-1;
				for(j=i+1;j<n;j++)
				{
					if(a[j]<a[i])
						break;
				}
				rmin=j;
				ans=(rmin-lmin-1)*a[i];
				if(ans>max)
					max=ans;
			}
			else if(a[i-1]>a[i])
			{
				for(j=lmin;j>=0;j--)
				{
					if(a[j]<a[i])
						break;
				}
				lmin=j;
				for(j=i+1;j<n;j++)
				{
					if(a[j]<a[i])
						break;
				}
				rmin=j;
				ans=(rmin-lmin-1)*a[i];
				if(ans>max)
					max=ans;
			}
		}
		for(j=n-1;j>=0;j--)
		{
			if(a[j]<a[n-1])
				break;
		}
		lmin=j;
		ans=(n-1-lmin)*a[n-1];
		if(ans>max)
			max=ans;
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
    
