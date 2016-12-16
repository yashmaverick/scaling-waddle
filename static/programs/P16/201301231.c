#include <stdio.h>
#include <math.h>

int main()
{
	long long int tq,i,t,n,q,v,dq,ct,dis;

	scanf("%lld",&n);

	for(t=1;t<=n;t++)
	{
		scanf("%lld",&q);

		dq=q;
		ct=0;

		while(dq!=1)
		{
			dq=dq/2;
			ct++;
		}

		dis=ct;

		tq=pow(2,ct);
		dq=((3*tq)/2)-1;

		if(q <= dq)
		{
			dis+=dis-1;
		}
		else
			dis+=dis;

		printf("%lld\n",dis);
	}

	return 0;
}
