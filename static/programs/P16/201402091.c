#include<stdio.h>
int main()
{
	long long int a[64],i,q,t,n,s,order;
	a[0]=1,a[1]=2;
	for(i=2;i<63;i++)
		a[i]=2*a[i-1]+1;
		scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&q);
		if(q==0)
			order=0;
		else if(q==1)
			order=0;
		else if(q==2)
			order=1;
		else if(q==3)
			order=2;
		else
		{
		n=0,s=q;
		while(s)
		{	if(s==1)
			break;
			n++;
			s/=2;
		}
		if(a[n]>=q)
			order=(2*(n)-1);
		else
			order=2*(n);
		}
	printf("%lld\n",order);
	}
	return 0;
}

