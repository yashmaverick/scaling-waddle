#include <stdio.h>
#define MOD 1000000007
void markMultiples(int arr[], int a, int n)
{
	int i = 2, num;
	while ( (num = i*a) <= n )
	{
		arr[ num-1 ] = 1; 
		++i;
	}
}


void SieveOfEratosthenes(int n)
{
	
	if (n >= 2)
	{
		
		int arr[n];
		memset(arr, 0, sizeof(arr));

		
		int i=1;   
		for (i=1; i<n; ++i)
		{
			if ( arr[i] == 0 )
			{
			
			
				markMultiples(arr, i+1, n);
			}
		}

	}
}
long long pow_(long long a, long long b, long long m)
{
	long long ans =1;
	while(b)
	{
		if(b&1) ans = ans*a%m;
		a=a*a%m;
		b=b/2;
	}
	return ans%m;
}
int main()
{
	long long t,upper,d,m,N,A[40],i,j,k,r,ans;
SieveOfEratosthenes(100);

	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&upper,&d,&m,&N);
		for(i=0;i<N;i++)
			A[i] = 0;

		for(i=0;i<N;i++)
		{
			if(i>upper) continue;
			r=pow_(i,d,N);
			A[r]+=(upper-i)/N + 1;
		}
		ans = 0;
		for(i=0;i<N;i++)
			for(j=0;j<N;j++)
				for(k=0;k<N;k++)
				{
					if((i+j+k)%N != m) continue ;
					ans += (((A[i] * A[j])%MOD) * A[k]) % MOD ;
					ans %= MOD;
				}
		printf("%lld\n",ans);
	}

	return 0;
} 
