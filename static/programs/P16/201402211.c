#include<stdio.h>
typedef long long ll;

ll N, Q;

int main()
{
	int i, j, k;
	scanf("%lld",&N);
	//printf("%lld\n",N);
	while ( N-- )
	{
		scanf("%lld",&Q);
		for ( i = 0; (1 << i) <= Q; i++ );
		i--;
		//printf("i is %lld\n",i);
		ll mid = (1<<i)/2 + (1<<i);
		if ( Q < mid )
		{
			printf("%lld\n",2*i-1);
		}
		else
		{
			printf("%lld\n",2*i);
		}
		
	}
}
