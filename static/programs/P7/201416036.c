#include<stdio.h>
typedef long long int ll;
//typedef scanf sc;
int main()
{
	ll i,n,test,j;
	scanf("%lld",&test);
	for(i=0;i<test;i++)
	{
		scanf("%Ld",&n);
		ll a[n];
		scanf("%Ld",&a[0]);
		ll min=a[0];
		ll max=a[0];
		for(j=1;j<n;j++)
		{
			scanf("%Ld",&a[j]);
			if(min > a[j])
				min=a[j];
			if(max < a[j])
				max=a[j];
		}
		ll b[max-min+1];
		ll r=max-min+1;
		ll k;
		for(k=0;k<r;k++)
		{
			b[k]=0;
		}
		for(j=0;j<n;j++)
		{
			b[max-a[j]]=b[max-a[j]]+1;
		}
		ll p=1;
		ll sum=0;
		for(k=0;k<r;k++)
		{
			p=(((b[k])*(b[k]-1))/2);
			sum=sum+p;
		}
		printf("%Ld\n",sum);


	}
	return 0;
}
