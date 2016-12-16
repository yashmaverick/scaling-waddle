#include<stdio.h>
int a[1000005],b[1000005]={0};
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int min=a[0];
		int max=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		for(i=0;i<n;i++)
		{
			b[a[i]-min]++;
		}
		long long ans=0;
		for(i=min;i<=max;i++)
		{
			long long cnt=b[i-min];
			b[i-min]=0;
			cnt=cnt*(cnt-1);
			cnt/=2;
			ans+=cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}



