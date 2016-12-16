#include<stdio.h>
#include<stdlib.h>

struct planks
{
	long long h;
	long long combo;
};

typedef struct planks planks;

void paintTheWall ( long long a[] , long long n )
{
	planks stack[100000] ;
	long range[100000][2] , i , head , count;

	stack[0].h = a[0];
	stack[0].combo = 1;
	head = 0;
	range[0][0] = 1;
	range[n-1][1] = 1;

	for ( i = 1 ; i < n ; i ++ )
	{
		count = 1;
		while ( a[i] <= stack[head].h && head >= 0) 
		{
			count += stack[head].combo;
			head --;
		}
		head ++;
		stack[head].h = a[i];
		stack[head].combo = count;
		range[i][0] = count;

	}

	stack[0].h = a[n-1];
	stack[0].combo = 1;
	head = 0;

	for ( i = n-2 ; i >= 0 ; i -- )
	{
		count = 1;
		while ( a[i] <= stack[head].h && head >= 0)
		{
			count += stack[head].combo;
			head --;
		}
		head ++;
		stack[head].h = a[i];
		stack[head].combo = count;
		range[i][1] = count;

	}

	long long temp;
	long long max = (range[0][0]+range[0][1]-1)*a[0];

	for ( i = 0 ; i < n ; i ++ ) 
	{
		temp = (range[i][0]+range[i][1]-1)*a[i];
		if ( temp > max )
			max = temp;
	}	

	printf("%lld\n",max);
}


int main ()
{
	long long n = 0 , i;
	long long a[100000];
	scanf("%lld",&n);
	while ( n > 0 )
	{
		for ( i = 0 ; i < n ; i ++ )
			scanf("%lld",&a[i]);

		paintTheWall ( a , n );
		scanf("%lld",&n);
	}
	return 0;
}




