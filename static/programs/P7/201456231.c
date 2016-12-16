#include <stdio.h>
#include <stdlib.h>

long long int cmpfunc (const void * a, const void * b)
{
   return ( *(long long int*)a - *(long long int*)b );
}

long long int A[1000000];
long long int temp[1000000];
long long int copy( long long int s, long long int e);
long long int comb(long long int n,long long int k)
{
	if (k==0)
		return 1;
	else
		return comb(n-1,k-1) * n / k;
}

long long int copy( long long int s, long long int e)
{
	long long int i;
	for(i=s;i<=e;i++)
	{
		A[i]=temp[i];
	}
	return 0;
}
int main()
{
	long long int a,b;
	scanf("%lld", &a);
	for(b=0;b<a;b++)
	{
		long long int i,n;
		long long int count=1,flag=0;
		long long int first,final=0;
		long long int ans=0;
		scanf("%lld", &n);
		for(i=0;i<n;i++)
		{
			scanf("%lld", &A[i]);
		}

        qsort(A,n,sizeof(long long int), cmpfunc);

		first=A[0];
		for(i=1;i<n;i++)
		{			
			if(first==A[i])
				count++;
			if(first!=A[i])
			{				
				long long int k=2;
				ans=comb(count,k);
				final=final+ans;
				first=A[i];
				count=1;
				
			}
		
			
		}

		final=final+(count*(count-1))/2;
		printf("%lld\n",final);

	}
	return 0;
}	
