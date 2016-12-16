#include<stdio.h>

struct mountain
{
	long long h;
	long long like;
};

typedef struct mountain mountain;

int main ()
{
	long long n , i;
	scanf("%lld",&n);
	while ( n > 0 )
	{
		mountain stack[n] ;
		long long i , head = 0 , count = 0 , value , pop , pop2 , j , total , ANS;
		for ( i = 0 ; i < n ; i ++ )
		{	
			scanf("%lld",&value);
			if ( i == 0 )
			{	
				stack[head].h = value;
				stack[head].like = 0;
			}
			else
			{
				pop = 0;
				if ( value != stack[head].h )
				{
					while ( value > stack[head].h &&  head >= 0)
					{
						pop += stack[head].like ;
						head --;
					}
					count += pop;
				}
				head ++;
				if ( head == 0 ) stack[head].like = 0;
				else stack[head].like = 1;
				stack[head].h = value;
				if ( value == stack[head-1].h && head >=1 )
				{
					count += stack[head-1].like ;
					stack[head-1].like ++;
					head --;
				}
				count ++;
			}
		}
		printf("%lld\n",(n*(n-1)/2)-count);
		scanf("%lld",&n);
	}
	return 0;
}
