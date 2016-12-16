#include<stdio.h>
int main()
{
	int n,a[1000000],i,m,t;
	int b[1000001];
	long long int ans,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&a[0]);
		m=a[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<m)
				m=a[i];
		}
		for(i=0;i<1000001;i++)
			b[i]=0;
		for(i=0;i<n;i++)
			b[a[i]-m]++;
		ans=0;
		for(i=0;i<1000001;i++)
		{		x=b[i];
				ans+=(x*(x-1))/2;
		}
				printf("%lld\n",ans);
		
	}
	return 0;
}
