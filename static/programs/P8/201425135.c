#include<stdio.h>
#include<math.h>
int expo(long long int x, long long int n, long long int N)
{
	if(n==0)
		return 1;
	else if(n==1)
		return x%N;
	else if(n%2==0)
		return (expo((x*x)%N, n/2, N)%N);
	else if(n%2!=0)
		return (x*expo((x*x)%N, (n-1)/2, N))%N;

}
int main()
{
	int T,l;
	// printf("%d\n", expo(2,32,7));
	scanf("%d", &T);
	for(l=0;l<T;l++)
	{
		long long int upper, d, m, N, i, j, k;
		scanf("%lld%lld%lld%lld", &upper, &d, &m, &N);
		long long int store[N];
		for(i=0;i<N;i++)
		{
			store[i] = expo(i, d, N);
			// printf("%lld ",store[i]);
		}
		long long int count[N];
		// printf("\n");
		for(i=0;i<N;i++)
		{
			count[i] = (upper + N - i)/N;
			// printf("%lld ",count[i]);
		}
		// printf("\n");
		long long int tot=0;
		for(i=0;i<N;i++)
		{
			if(store[i]<0)
				continue;
			for(j=0;j<N;j++)
			{
				if(store[j]<0)
					continue;
				for(k=0;k<N;k++)
				{
					if(store[k]<0)
						continue;
					if( (store[i] + store[j] + store[k])%N == m)
					{
						long long int x1 = (count[i]*count[j])%1000000007;
						tot = (tot + (x1*count[k])%1000000007)%1000000007;
					}
				}
			}
		}
		printf("%lld\n", tot%1000000007);
	}
	return 0;
}

