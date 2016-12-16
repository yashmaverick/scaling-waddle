#include<stdio.h>
#include<math.h>
int main()
{
	long long int a,q,i,n,l,t,res;
	scanf("%lld",&q);
	for(i=0;i<q;i++)
	{
		res=1;
		a=2;
		scanf("%lld",&n);
		l=log(n)/log(2);
		t=l;
		while(l)
		{
			if(l&1==1)
				res=res*a;
			a*=a;
			l>>=1;
		}
		if(n==1)
			printf("0\n");
		else if(res+res/2>n)
			printf("%lld\n",2*t-1);
		else
			printf("%lld\n",2*t);
	}
	return 0;
}
