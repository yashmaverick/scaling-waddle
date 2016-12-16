#include<stdio.h>
long long int p=1;
long long int power(long long int v)
{
	long long int i=0;
	p=1;
	if(v==1)
		return 0;
	while(v>p)
	{
		p=p*2;
		i++;
		if(p==v)
			i++;
	}
	if(p==v)
		p=p*2;
	return i-1;
}
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		long long int q,c;
		scanf("%lld",&q);
		c=power(q);
		c--;
//		po=2*po;
		p=p/2;
//		printf("c=%lld\n",c);
//		printf("p=%lld\n",p);
		if(q<(p+(p/2)))
			c=(2*c)+1;
		else
			c=2*c+2;
		printf("%lld\n",c);
	}
	return 0;
}
