#include<stdio.h>
long long int a[100100],b[100100],c[100100],pr[100100],pr2[100100];
int main()
{
	long long int m;
	scanf("%lld",&m);
	while(m--)
	{
		long long int p,q,r,i;
		for(i=0;i<100100;i++)
			pr[i]=pr2[i]=0;
		scanf("%lld",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		long long int s=0,t=0;
		long long int ans=0;
		while(t<q&&s<p)
		{
			if(t<s)
				t++;
			if(a[s]<=b[t]&&s<=t)
			{
				pr[t]++;
				s++;
			}
			else
			{
				t++;
			}
		}
		for(i=1;i<q;i++)
			pr[i]=pr[i]+pr[i-1];
		s=0;t=0;
		while(t<r&&s<q)
		{
			if(t<s)
				t++;
			if(b[s]<=c[t]&&s<=t)
			{
				pr2[t]+=pr[s];
				s++;
			}
			else
			{
				t++;
			}
		}
		for(i=1;i<r;i++)
			pr2[i]=pr2[i]+pr2[i-1];
		for(i=0;i<r;i++)
			ans+=pr2[i];
		printf("%lld\n",ans);
	}
	return 0;
}
