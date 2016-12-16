#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define si(a)               scanf("%d",&a)
#define sii(a,b)            scanf("%d %d",&a,&b)
#define sl(a)               scanf("%lld",&a)
#define slu(a)              scanf("%llu",&a)
#define sf(a)               scanf("%f",&a)
#define sd(a)               scanf("%lf",&a)
#define ss(a)               scanf("%s",a)
#define pi(a)               printf("%d",a)
#define pii(a,b)            printf("%d %d",a,b)
#define pl(a)               printf("%lld",a)
#define pnl					printf("\n")

#define LL                  long long 
#define UI                  unsigned int
#define ULL                 unsigned long long
#define MOD                 1000000007
#define MAX                 1000000007000
#define forall(i,a,b)       for(i=a; i<b; i++)

#define max(a,b)    ((a) > (b) ? (a) : (b))
#define min(a,b)    ((a) < (b) ? (a) : (b))

int Min(int data[],int start,int end)
{
	int i;
	int min = start;
	for(i = start; i <= end; i++)
	{
		if(data[min] >= data[i])
			min = i;
	}
	return min;
}

int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n,k;
		int min_index=0;
		sii(n,k);

		int a[10001],i,j;

		for(i = 0; i < n; i++)
			si(a[i]);

		for(j = 0; j < n - k + 1; j++)
		{
			if(j == 0 || min_index < j)
				min_index = Min(a, j, j + k - 1);
			else if(a[min_index] >= a[j + k - 1])
				min_index = Min(a, j, j + k - 1);
			
			if(j < n - k)
				printf("%d ",a[min_index]);
			else
				printf("%d\n",a[min_index]);
		}
	}
	return 0;
}