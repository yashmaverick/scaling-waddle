#include<stdio.h>
int main()
{
	int t,h;
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		long long int n,min=10000000,i,d,ans=0;
		scanf("%lld",&n);
		long long int a[n],b[1000001];
		for(i=0;i<1000001;i++)
			b[i]=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			if(a[i]<min)
				min=a[i];
//			printf("%d\n",min);
		}
		for(i=0;i<n;i++)
		{
			a[i]=a[i]-min;
//			c=a[i];
			b[a[i]]++;
		}
		for(i=0;i<1000001;i++)
		{
			if(b[i]>1)
			{
				d=b[i];
				ans=ans+(d*(d-1))/2;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
