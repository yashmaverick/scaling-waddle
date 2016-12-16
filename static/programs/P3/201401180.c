#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a[100010];
		long long int d[100010];
		int i;
		int n;
		int j;
		long long int t;
		long long int ans=0;
		long long int max=0;
		scanf("%d",&n);
		for (i = 0; i < n; i++)
		{
			scanf("%lld",&a[i]);
		}
		for (i = n-1; i >= 0; i--)
		{
			if (a[i] > max)
			{
				max = a[i];
				for (j = i-1; j >= 0; j--)
				{
					d[j] = max;
					t = d[j]-a[j];
					if (t > ans)
						ans = t;
				}
			}
		}
		printf("%lld\n",ans);		
	}
	return 0;
}	

