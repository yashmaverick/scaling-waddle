#include<stdio.h>
#include<stdlib.h>

long long int MOD;

long long int m[2374];
int c,position;

int main()
{
	long long int *temp;
	long long int *a[2033],position,d;
	long long int i,j,n;
	scanf("%lld %lld",&n,&MOD);
	long long int s[8249],swap;
	for(i=0;i<n;i++)
	{
		long long int mdd;
		scanf("%lld",&m[i]);
		int z=0;
		a[i]=(long long int *)(malloc(m[i]*sizeof(long long int)));
		for(j=0;j<m[i];j++)
		{
			scanf("%lld",&a[i][j]);
			z=(z%MOD+a[i][j]%MOD)%MOD;
		}
		s[i]=z;
	}

	for ( c = 0 ; c < ( n - 1 ) ; c++ )
	{
		position = c;

		for ( d = c + 1 ; d < n ; d++ )
		{
			if ( s[position] > s[d] )
				position = d;
		}
		if ( position != c )
		{
			temp=a[c];
			a[c]=a[position];
			a[position]=temp;

			swap = s[c];
			s[c] = s[position];
			s[position] = swap;

			swap=m[c];
			m[c]=m[position];
			m[position]=swap;

		}
	}

	for(i=0;i<n;i++)
	{
		printf("%lld\n",s[i]);

		for(j=0;j<m[i];j++)
		{
			printf("%lld\n",a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
