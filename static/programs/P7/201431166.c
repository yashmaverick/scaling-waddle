#include<stdio.h>
long long int cmp(const void *c,const void *b)
{
	return (*(long long int*)c-*(long long int*)b);
}

long long int comb(long long int n)
{
	if(n<=1)
		return (n*0);
	else return (n*(n-1))/2;
}

int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		long long int a[n],i,count=1,sum=0,ans;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		qsort(a,n,sizeof(long long int),cmp);
		for(i=0;i<n;i++)
		{
			if(a[i]==a[i+1])
				count++;
			else
			{
				ans=comb(count);
				sum=sum+ans;
				count=1;
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
