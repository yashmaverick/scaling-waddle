#include<stdio.h>
int main()
{
	long long int n,q,p,r,l,t;
	scanf("%lld",&n);
	while(n--)
	{
		l=-1;
		t=-1;
		scanf("%lld",&q);
		p=q;
		while(p!=0)
		{
			r=p;
			p=p-(p&(-p));
		}
//		printf("%lld\n",r);
		while(r!=0)
		{
			l++;
			r=r>>1;
		}
//		printf("%lld\n",l);
		p=(2*q)/3;
		while(p!=0)
		{
			r=p;
			p=p-(p&(-p));
		}
//		printf("%lld\n",r);
		while(r!=0)
		{
			t++;
			r=r>>1;
		}
		if((l+t)==-1)
			printf("0\n");
		else
			printf("%lld\n",l+t);
	}
	return 0;
}
