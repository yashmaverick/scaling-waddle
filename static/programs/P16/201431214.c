#include<stdio.h>
long long int exponential(long long int a,long long int b)
{
	long long int x;
	if(b==0)
	{return 1;}
	else
	{
		x=exponential(a,b/2);
		if(b%2==0)
		{
			return (x*x);
		}
		else
		{
			return (((a*x))*(x));
		}
	}
}
int depth(int n,int cnt)
{
	if(n==1)
	{
		return cnt;
	}
	else
	{
		depth(n/2,cnt+1);
	}
}
int main()
{
	int nq,i;
	scanf("%d",&nq);
	for(i=0;i<nq;i++)
	{
		int cnt,ans;
		long long int expo1,expo2,cmp,q;
		scanf("%lld",&q);
		cnt=depth(q,0);
		expo1=exponential(2,cnt);
		expo2=expo1/2;
		cmp=expo1+expo2-1;
		if(q>cmp)
		{
			ans=2*cnt;
		}
		else
		{
			ans=2*cnt-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
