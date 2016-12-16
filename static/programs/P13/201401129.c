#include<stdio.h>

struct stack
{
	long long number;
	long long index;
};

typedef struct stack stack;

void popingStacks ( long long a[] , long long n )
{
	long long i , depth , deepest , head , j;
	stack tree[n];
	depth = 0;
	deepest = a[n-1];
	tree[0].number = a[n-1];
	tree[0].index = 0;
	head = 0;

	for ( i = n - 2 ; i >= 0 ; i -- )
	{
		if ( a[i] > tree[head].number )
		{
			head ++;
			tree[head].number = a[i];
			tree[head].index = tree[head-1].index + 1;
			if ( tree[head].index > depth || ( tree[head].index == depth && tree[head].number < deepest ) )
			{
				depth = tree[head].index;
				deepest = tree[head].number;
			}

		}
		else
		{
			while ( a[i] < tree[head].number && head >= 0 ) head --;
			head ++;
			tree[head].index ++;
			tree[head].number = a[i];
			if ( tree[head].index > depth || ( tree[head].index == depth && tree[head].number < deepest ) )
			{
				deepest = tree[head].number;
				depth = tree[head].index;
			}
		}
	}
	printf("%lld %lld\n",deepest,depth);
}


int main ()
{
	long long n , i , j , t;
	scanf("%lld",&t);
	for ( i = 0 ; i < t ; i ++ )
	{
		scanf("%lld",&n);
		long long a[n];
		for ( j = 0 ; j < n ; j ++ )
			scanf("%lld",&a[j]);

		popingStacks ( a , n );
	}
	return 0;
}


		
