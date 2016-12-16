#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}
int main()
{
	long long int T;
	scanf("%lld",&T);
	while(T--)
	{
		long long int n,i,p,sum,j;
		sum=0;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		qsort(a,n,sizeof(long long int),cmpfunc);
		//		for(i=0;i<n;i++)
		//			printf("%lld ",a[i]);
		p = 1;
		for(i=0;i<n-1;i++)
		{
			if(a[i]==a[i+1])
				p++;
			else
			{
				sum += ( p * (p-1) ) / 2 ;
				p = 1;
			}
		}

		sum += ( p * (p-1) ) / 2 ;
		printf("%lld\n",sum);
	}
	return 0;
}
