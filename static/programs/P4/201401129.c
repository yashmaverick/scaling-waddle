#include<stdio.h>
#include<string.h>

void show ( long long a[] , long long n )
{
	long long i;
	for ( i = 0 ; i < n ; i ++ ) printf("%lld ",a[i]);
	printf("\n");
}



void mergesort ( long long a[] , long long low , long long mid , long long high )
{
	long long i , j , k , x , y , b[100001];

	i = low;
	j = mid + 1;
	k = 0;

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
long pairUp ( long long n )
{
	return n*(n-1)/2;
}

long long counter ( char word , long long count )
{
	if ( word == 'J' ) count += 100000;
	else if ( word == 'M' ) count += 100001;
	else if ( word == 'R' ) count -= 200001;
	return count;
}

long long main ()
{
	long long t , i , j , k , x , count , string , n , pairs , a[100001];
	char MRJ[100001];
	scanf("%lld",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%s",MRJ);
		count = 0;
		n = strlen(MRJ);
		//printf("%lld\n",n);
		for ( j = 0 ; j < n ; j ++ )
		{
			count = counter ( MRJ[j], count );
			a[j] = count;
			//printf("%lld ",count);
		}
		//printf("\n");

		//show ( a , n );

		divideAndConquer ( a , 0 , n-1 );

		//show ( a , n );

		x = a[0];
		count = 0;
		pairs = 0;

		for ( j = 0 ; j < n ; j ++ )
		{
			if ( a[j] == 0 ) 
				pairs ++;
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

