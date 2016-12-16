#include<stdio.h>
typedef long long int L;
int main()
{
	L t;
	scanf("%lld",&t);
	while(t--)
	{
		L n,i,ans;
		scanf("%lld",&n);
		L a[1000000];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		L min=a[0],max=-99999;
		for(i=0;i<n;i++)
		{
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		int m=max-min;
		L bucket[m+1];
		for(i=0;i<=m;i++)
			bucket[i]=0;
		for(i=0;i<n;i++)
		{
			bucket[a[i]-min]++;
		}
		ans=0;
		for(i=0;i<=m;i++)
		{
			if(bucket[i]>1)
			{
				ans+=bucket[i]*(bucket[i]-1)/2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
