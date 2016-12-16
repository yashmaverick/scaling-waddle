#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define gu getchar_unlocked 
#define pu putchar_unlocked
#define lli long long int
#define ulli unsigned long long int
#define din(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define lldin(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)<(b)?(b):(a))
#define ROUNDOFFINT(d) d = (int)((double)d + 0.5)
#define PLUSWRAP(index,n) index = (index+1)%n
#define MINUSWRAP(index,n) index = (index + n -1)%n

#define INF 1000000000	//1 billion (10^9)

#define FLUSHN while(gu()!='\n')
#define FLUSHS while(gu()!=' ')

int cmpfunc(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}


int main()
{
	int n;
	din(n);
	while(n--)
	{
		int q;
		din(q);
		if(q==1)
		{
			dout(0);
			continue;
		}
		else if(q==2)
		{
			dout(1);
			continue;
		}
		else if(q==3)
		{
			dout(2);
			continue;
		}
		int h=0;
		int flag=0;
		while(q!=1)
		{
			q = q/2;
			if(q==2)
				flag=1;
			h++;
		}
		if(flag)
			dout(h+h-1);
		else
			dout(h+h);
	}
	return 0;
}
