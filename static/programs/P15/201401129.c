#include<stdio.h>

long long findSmallest ( long long a[] , int j , int k )
{
	int i;
	long long min;
	min = a[j];
	for ( i = j + 1 ; i < k + j ; i ++ )
		if ( a[i] < min )
			min = a[i];
	return min;
}

int main ()
{
	int i , n , k , t  , j;
	long long min , a[10002];
	scanf("%d",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%d %d",&n,&k);
		for ( j = 1 ; j <= n ; j ++ )
			scanf("%lld",&a[j]);

		min = findSmallest ( a , 1 , k );
		printf("%lld",min);
		for ( j = 2 ; j <= n - k + 1 ; j ++ )
		{
			if ( a[j+k-1] <= min ) min = a[j+k-1];
			else if ( a[j-1] == min ) min = findSmallest ( a , j , k );
			printf(" %lld",min);
		}
		printf("\n");
	}
	return 0;
}
