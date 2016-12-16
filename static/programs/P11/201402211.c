#include<stdio.h>
#include<string.h>
typedef long long ll;

ll fences[100005], N, rSmall[100005], lSmall[100005];

struct node {
	ll ind;
	ll val;
} stack[100005];

ll top;

int main()
{
	ll i, j, k;
	while ( scanf("%lld ",&N) )
	{
		if ( !N ) break;
		memset(lSmall,0,sizeof(lSmall));
		memset(rSmall,0,sizeof(rSmall));
		top = 0;
		for ( i = 1; i <= N; i++ )
		{
			scanf("%lld",&fences[i]);
			while ( top && stack[top].val > fences[i] )
			{
				rSmall[ stack[top].ind ] = i;
				top--;
			}
			top++;
			stack[top].val = fences[i];
			stack[top].ind = i;
		}
		top = 0;
		for ( i = N; i > 0; i-- )
		{
			while ( top && stack[top].val > fences[i] )
			{
				lSmall[ stack[top].ind ] = i;
				top--;
			}
			stack[++top].val = fences[i];
			stack[top].ind = i;
		}
		
		//for ( i = 1; i <= N; i++ ) printf("%lld ",lSmall[i]); printf("\n");
		//for ( i = 1; i <= N; i++ ) printf("%lld ",rSmall[i]); printf("\n");
		
		ll max = 0;
		for ( i = 1; i <= N; i++ )
		{
			if ( !rSmall[i] ) rSmall[i] = N+1;
			if ( fences[i] * (rSmall[i]-lSmall[i]-1) > max )
			{
				max = fences[i] * (rSmall[i]-lSmall[i]-1);
			}
		}
		printf("%lld\n",max);
	}
	return 0;
}
