/*Rohan Karnawat*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define s(n) scanf("%lld",&n)
#define d(n) tp n;n=(tp)malloc(1*sizeof(t))
#define f(i,n) for(i=0;i<n;i++)
#define endl printf("\n")
typedef long long ll;
int main()
{
	ll n;s(n);
	ll pre[n+1],in[n+1];
	ll i;
	f(i,n)
		s(pre[i]);
	f(i,n)
		s(in[i]);
	ll t;s(t);
	ll u,v,j,k;
	ll ps,pe,is,ie;
	f(i,t)
	{
		s(u);s(v);
		ll x[n],y[n];
		for(j=0;j<n;j++)
			if(pre[j]==u)
				break;
		ps=j;
		for(j=0;j<n;j++)
			if(pre[j]==v)
				break;
		pe=j;
		for(j=0;j<n;j++)
			if(in[j]==u)
				break;
		is=j;
		for(j=0;j<n;j++)
			if(in[j]==v)
				break;
		ie=j;
/*		printf("ps= %lld pe= %lld is= %lld ie= %lld\n",ps,pe,is,ie);*/
		ll l1,l2;
		if(pe>ps)
		{
			l1=ps;
			ll k=0;
			for(j=0;j<=l1;j++)
			{
				x[k++]=pre[j];
			}
		}
		else
		{
			l1=pe;
			ll k=0;
			for(j=0;j<=l1;j++)
			{
				x[k++]=pre[j];
			}
		}
		//	for(j=0;j<=l1;j++)
		//		printf("%lld ",x[j]);
		//	putchar('\n');
		if(ie>is)
		{
			l2=ie-is+1;
			ll w=0;
			for(j=is;j<=ie;j++)
			{
				y[w++]=in[j];	
			}
		}
		else
		{
			l2=is-ie+1;
			ll w=0;
			for(j=ie;j<=is;j++)
			{
				y[w++]=in[j];	
				//	printf("%lld ",y[w-1]);
			}
		}
		//	for(j=0;j<l2;j++)
		//		printf("%lld ",y[j]);
		//	putchar('\n');
		ll b,h;
		int flag;
		ll answer=0;
	//	printf("l1=%lld l2=%lld\n",l1,l2);
		for(b=l2-1;b>=0;b--)
		{
			flag=0;
			for(h=0;h<=l1;h++)
			{
				if(y[b]==x[h])
				{
					flag=1;
					answer=y[b];
					break;
				}
			}
			if(flag==1)
				break;
		}
		printf("%lld\n",answer);
	}
	return 0;
}
