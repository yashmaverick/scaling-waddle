#include<stdio.h>
#include<math.h>
typedef long long int L;
int ipow(int base, int exp)
{
	int result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}
L logb2(L n)
{
	return log(n)/log(2);
}
int main()
{
	L t;
	scanf("%Ld",&t);
	while(t--)
	{
		L n,dep;
		scanf("%Ld",&n);
		if(n!=1)
		{ 
			dep = logb2(n);
			L p = ipow(2,dep);
			L mid = p + (p/2);
			if( n >= p && n < mid)
				printf("%Ld\n",2*dep-1);
			else 
				printf("%Ld\n",2*dep);
		}
		if(n==1)
		{
			printf("0\n");			
		}
	}
	return 0;
}
