#include<stdio.h>
typedef long long L;

L maxarea(int st[], int n)
{
	L i , S[100001] , a = 0 , last = 1;
	st[0] = 0;
	S[0] = 0;
	st[ ++n ] = 0;
	for( i = 1 ; i <= n ; i++ )
	{
		while( last > 1 && st[ S[ last - 1 ] ] >= st[i] )
		{
				if( a < (L)st[ S[ last-1] ] * (L)( i - S[ last - 2 ] - 1 ) )
				{
					a = (L)st[ S[ last - 1 ] ] * (L)( i - S[ last - 2 ] - 1 );
				}
				last--;

		}
		S[ last++ ] = i;
	}
	return a;
}

int main()
{
	int n, st[100001];
	scanf("%d", &n );
	while( n != 0 )
	{
		int i;
		for( i = 1 ; i <= n ; i++ )
			scanf("%d", &st[i] );
		int A = maxarea( st , n );
		printf("%Ld\n", A );
		scanf("%d", &n );
	}
	return 0;
}
