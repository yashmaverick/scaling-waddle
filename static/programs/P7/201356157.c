#include <stdio.h>
#include <stdlib.h>

int func (const void * a, const void * b)
{
   return ( * (long long int*)a - *(long long int*)b );
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t>0)
	{
		t--;
		long long int n;
		scanf("%lld",&n);
		long long int i,j,a[n],ans=0,k=1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		qsort(a, n, sizeof(long long int), func);

		for(i=0;i<=n-1;i++)
		{
			if(a[i]==a[i+1])
			{
				k++;
			}
			else
			{
				ans = ans + (k*(k-1)/2) ;
				k=1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}