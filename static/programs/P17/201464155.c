#include<stdio.h>
#include<stdlib.h>
#define sc(x) scanf("%lld",&x)
#define ll long long int
int main()
{
	ll n,i;
	sc(n);
	ll a[n],b[n],d[1000001]={0};
	for(i=0;i<n;i++)
		sc(a[i]);
	for(i=0;i<n;i++)
		sc(b[i]);
	ll t;
	sc(t);
	while(t--)
	{
		for(i=0;i<=1000000;i++)
			d[i]=0;
		ll p,q,flag=2;
		sc(p);
		sc(q);
		for(i=0;i<n;i++)
		{
			//printf("Checking for %lld\n",b[i]);
			if(b[i]==p)
			{flag=q;
				break;
			}
			else if(b[i]==q)
			{flag=p;
				break;
			}
		}
		//printf("Broken\n");
		while(b[i]!=flag)
		{
			d[b[i]]=1;
			i++;
		}
		d[flag]=1;
		for(i=0;i<n;i++)
		{
			if(d[a[i]]==1)
				break;
		}
		printf("%lld\n",a[i]);
	}
	return 0;
}
