#include<stdio.h>
#define ll long long int
int powr(int a,int b)
{
	int f=1;
	while(b)
	{
		if(b&1)
			f=f*a;
		b>>=1;
		a*=a;
	}
	return f;
}
int level(int n)
{
	int c=0;
	while(n)
	{
		n=n>>1;
		c++;
	}
	return c-1;
}
int main()
{
	int t,l,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=level(n);
	//	printf("l=%lld\n",l);
		k=powr(2,l);
	//	printf("k=%lld\n",k);
		if(n-k<k/2)
			printf("%d\n",2*l-1);
		if(n-k>=k/2)
			printf("%d\n",2*l);
	}
	return 0;
}

