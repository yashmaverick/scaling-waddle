#include<stdio.h>
int main()
{
	long long int min,i,j,k,l,n,m,t,a[1000001],b[1000001];
	long long int ans,sum;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		min=10000000;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
		}
		for(i=0;i<1000001;i++)
			b[i]=0;
		for(i=0;i<n;i++)
			b[a[i]-min]++;
		ans=0;
		for(i=0;i<1000001;i++)
			ans=ans+(b[i]*((b[i])-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}
