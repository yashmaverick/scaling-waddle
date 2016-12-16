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

#define MAX 1000010

int main()
{
	int t;
	din(t);
	while(t--)
	{
		int n;
		din(n);
		int A[MAX];
		int i;
		for(i=0;i<n;i++)
			din(A[i]);
		qsort(A,n,sizeof(int),cmpfunc);
		
		int c = A[0];
		lli count =1;
		lli ans=0;
		for(i=1;i<n;i++)
			if(c == A[i])
			{
				count++;
				if(i==n-1)
					ans+=(count * (count-1))/2;
			}
			else
			{
				c = A[i];
				ans+=(count * (count-1))/2;
				//printf("%d %lld %d\n",count,ans,A[i]);
				count=1;
			}
		lldout(ans);
	}

				





	return 0;
}
