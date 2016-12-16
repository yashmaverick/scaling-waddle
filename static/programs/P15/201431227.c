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
int arr[10001];

int main()
{
	int t;
	din(t);
	int i,j;
	while(t--)
	{
		int n,k;
		din(n);din(k);
		for(i=0;i<n;i++)
			din(arr[i]);
		for(i=0;i<=n-k;i++)
		{
			int mn=INT_MAX;
			for(j=i;j<i+k;j++)
				mn=min(mn,arr[j]);
			printf("%d%s",mn,(i==n-k?"":" "));
		}
		printf("\n");

	}

	return 0;
}
