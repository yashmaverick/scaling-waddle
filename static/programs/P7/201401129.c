#include<stdio.h>
#include<stdlib.h>

void mergesort ( long long a[] , long long low , long long mid , long long high )
{
	long long i , j , k , x , y ;

	i = low;
	j = mid + 1;
	k = 0;

	long long b[high];

	while ( i <= mid && j <= high )
	{
		if ( a[i] < a[j] )  b[k++] = a[i++];
		else b[k++] = a[j++];
	}
	while ( i ==  mid + 1 && j <= high ) b[k++] = a[j++];
	while ( i <= mid ) b[k++] = a[i++];

	for ( x = low , y = 0 ; x <= high ; x ++ , y ++ )
		a[x] = b[y];
}

void divideAndConquer ( long long a[] , long long low , long long high )
{
	long long mid = ( low + high ) / 2;

	if ( low < high )
	{
		divideAndConquer ( a , low , mid );
		divideAndConquer ( a , mid+1 , high );
		mergesort ( a , low , mid , high );
	}
}


long long pairUp ( long long n )
{
	return n*(n-1)/2;
}

int main ()
{
	long long n  , i , t , j , flag , x , count , pairs;

	scanf("%lld",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%lld",&n);
		long long a[n];
		for ( j = 0 ; j < n ; j ++ )
			scanf("%lld",&a[j]);

		divideAndConquer ( a , 0 , n-1 );

		flag = 0;
		x = a[0];
		count = 0;
		pairs = 0;

		for ( j = 0 ; j < n ; j ++ )
		{
			if ( a[j] == x )
				count ++;
			else
			{
				if ( count != 1 )
					pairs += pairUp(count);
				x = a[j];
				count = 1;
			}
			if ( j == n - 1 && count > 1 )
				pairs += pairUp(count);
		}
		printf("%lld\n",pairs);
	}
	return 0;
}

