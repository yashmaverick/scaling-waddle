#include<stdio.h>
int main()
{
	long long int n,tmp,i,T=1;
	scanf("%lld",&n);
	while( n )
	{
		long long int A[n],S[n],cases=0,s=0,j;
		scanf("%lld%lld",&A[0],&A[1]);
		S[0]=A[0];
		if( A[1]>S[0] )
		{
			S[0]=A[1];
			cases+=n-2;
		}
		else
		{
			s++;
			S[s]=A[1];
		}
		for( i=2 ; i<n ; i++ )
		{
			scanf("%lld",&A[i]);
			if( A[i]>S[s] )
			{
				S[s]=A[i];
				cases+=n-i-1;
			/*	if( S[0]<S[s] )
				{
					cases+=(n-i-1)*(s-1);
					s=0;
				}
				else*/
				for( j=s ; j>0 ; j-- )
				{
					if( S[j-1]<S[j] )
					{
						cases+=n-i-1;
						s--;
						S[s]=S[s+1];
					}
				}
				//printf("%d\n",S[0]);
			}
			else
			{
				s++;
				S[s]=A[i];
			}
			if( s>1 )
			{
				for( j=s-1 ; j>0 ; j-- )
				{
					if( A[i]<S[j] )
					{
						cases+=j;
						break;
					}
				}
			}
			//printf("%d\n",s);
		}
		printf("%lld\n",cases);
		scanf("%lld",&n);
	}
	return 0;
}
