#include <stdio.h>
#define DEBUG 0
#define MOD 1000000007
int modPow(int a, int b,int mod)	
{
	int ans = 1;
	while(b > 0)
	{
		if(b%2 == 1)
			ans *= a;
		a *= a;
		a %= mod;
		ans %= mod;
		b /= 2;
		if(ans == 0)	break;
	}
	return ans%mod;
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int upper,d,m,n,i,j,k,array[40],repeat[40],a,b;
		long long ans = 0;
		scanf("%d %d %d %d",&upper, &d, &m, &n);
		for(i = 0; i < n;i++)
			array[i] = modPow(i,d,n);
		a = upper%n;
		b = upper/n;
		for(i = 0;i <= a; i++)
			repeat[i] = b + 1;
		for(i = a+1;i < n; i++)
			repeat[i] = b;
		if(DEBUG)
			for(i = 0;i < n; i++)
				printf("%d ",repeat[i]);
		for(i = 0;i < n && i <= upper;i++)
		{
			for(j = 0;j < n && j <= upper; j++)
			{
				for(k = 0;k < n && k <= upper; k++)
				{
					if((array[i] + array[j] + array[k])%n == m)
					{
						ans += ((((long long)repeat[i]*repeat[j])%MOD)*(long long)repeat[k])%MOD;
						ans %= MOD;
						if(DEBUG)
						{
							printf("repeat = %d %d %d\n",repeat[i], repeat[j],repeat[k]);
							printf("ans = %lld\n",ans);
						}
					}
					if(DEBUG)	printf("%d %d %d\t%d\n",array[i],array[j],array[k],
							(array[i] + array[j] + array[k])%n);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
