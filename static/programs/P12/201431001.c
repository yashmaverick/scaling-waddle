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

int main()
{
	while (1)
	{
		LL n, count = 0;
		sl(n);
		if (n == 0)
			break;
		else
		{
			LL t, data[500001], i;
			for (i = 0; i < n; i++)
				sl(data[i]);
			
			LL j, max;
			for (i = 0; i < n; i++)
			{
				max = 0;
				for (j = i + 1; j < n; j++)
				{
					if (data[j] > max)
						max = data[j];
					if (data[j] > data[i])
					{
						count = count + (n - 1) - j;
						break;
					}
					if (data[j] < max)
						count++;
				}
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}