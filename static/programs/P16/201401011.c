#include<stdio.h>

int main()
{
	long long int t,q;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&q);

		if( q < 2 )
		{
			printf("0\n");
			continue;
		}

		long long int flag_bits, n_bits;
		int bits[100];
		
		n_bits = 0;
		while(q != 0)
		{
			n_bits++ ;
			bits[n_bits - 1] = q & 1 ;
			q >>= 1 ;
		}
		
		
		if(bits[n_bits -1] == bits[n_bits -2] )
			printf("%lld\n", 2*(n_bits-1) ); 
		else
			printf("%lld\n", (2*n_bits - 3) );

	}

	return 0;
}
