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

#define MAX 100010

int main()
{
	int t;
	din(t);
	while(t--)
	{
		int P[MAX],Q[MAX],R[MAX];
		int p,q,r,i,j;
		
		din(p);
		for(i=0;i<p;i++)
			din(P[i]);
		
		din(q);
		for(i=0;i<q;i++)
			din(Q[i]);

		din(r);
		for(i=0;i<r;i++)
			din(R[i]);

		lli Qsum[MAX],Rsum[MAX];
	
		j=0;
		Qsum[0]=0;
		for(i=0;i<q;i++)
		{
			int count = 0;
			while(P[j]<=Q[i] && j<p && j<=i)
			{
				count++;
				j++;
			}
			Qsum[i+1]=Qsum[i]+count;
		}

		Rsum[0]=0;
		j=0;
		lli ans=0;
		for(i=0;i<r;i++)
		{
			int count=0;
			while(Q[j]<=R[i] && j<q && j<=i)
			{
				count+=Qsum[j+1];
				j++;
			}
			Rsum[i+1]=Rsum[i]+count;
			ans+=Rsum[i+1];
		}


		
		lldout(ans);

	}

	return 0;
}
