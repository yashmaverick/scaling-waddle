#include<stdio.h>

int main()
{

	long long int T;
	scanf("%lld",&T);
	
	while(T--)
	{
		long long int n, k, i, j, min;
		scanf("%lld%lld",&n,&k);
		long long int a[n], stkq[n], front, top;

		for(i = 0;i < n; i++)
		{
			scanf("%lld",&a[i]);
			stkq[i] = -1;
		}
		
		// Stkq builder till k.
		front = top = 0;
		for(i = 0; i < k; i++ )
		{
			while( front < top && a[i] <= a[stkq[top-1]] )
			{
				stkq[top-1] = -1;
				top--;
			}
			
			stkq[top] = i ;
			top++;

		}
		printf("%lld",a[stkq[front]]);
		
		// For the rest of program
		j = 1 ;
		for( i = k; i < n; i++, j++)
		{
			if( stkq[front] < j )
			{
			 	stkq[front] = -1;
				front++;
			}
			
			while( front != top && a[i] <= a[stkq[top-1]] )
			{
				stkq[top-1] = -1;
				top--;
			}
			stkq[top] = i ;
			top++;
			
			printf(" %lld",a[stkq[front]]);
		}
		printf("\n");
	}
	
	return 0;
}
