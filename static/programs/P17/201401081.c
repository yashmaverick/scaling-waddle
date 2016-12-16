#include<stdio.h>
#define lli long long int
#define s(n) scanf("%lld",&n);

lli pre_order[10005];
lli in_order[10005];
lli n;

lli search_inord(lli data)
{
	int i;
	for(i=0;i<n;i++)
		if(in_order[i]==data)
			return i;
	return -1;
}

lli search_preord(lli data)
{
	int i;
	for(i=0;i<n;i++)
		if(pre_order[i]==data)
			return i;
	return -1;
}

lli lca(lli q1,lli q2)
{
	lli l1,l2,lmin,i,temp;
	temp=search_inord(q1);
	l2=search_inord(q2);
	if(temp<l2)
		l1=temp;
	else
	{
		l1=l2;
		l2=temp;
	}
	lmin=n-1;
	for(i=l1;i<=l2;i++)
	{
		temp=search_preord(in_order[i]);
		if(temp<lmin)
			lmin=temp;
	}
	return lmin;
}

int main()
{
	lli i;
	s(n);
	for(i=0;i<n;i++)
		s(pre_order[i]);
	for(i=0;i<n;i++)
		s(in_order[i]);
	lli t,q1,q2,l1,l2;
	s(t);
	while(t--)
	{
		s(q1);
		s(q2);
		printf("%lld\n",pre_order[lca(q1,q2)]);
	}
	return 0;
}
