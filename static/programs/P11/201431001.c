#include <stdio.h>

#define MAX 100001
#define ll long long int

int main()
{
	ll n, i;
	ll data[MAX], left[MAX], right[MAX];

	while(1)
	{
		scanf("%lld",&n);
		if(n == 0)
			break;
		ll temp;
		for(i = 1; i <= n; i++)
		{
			scanf("%lld", &data[i]);

			temp = i - 1;
			left[i] = 1;

			while(temp > 0 && data[temp] >= data[i])
			{
				left[i] += left[temp];
				temp -= left[temp];
			}
		}
		for(i = n; i >= 1; i--)
		{
			temp = i + 1;
			right[i] = 1;

			while(data[temp] >= data[i] && temp <= n)
			{
				right[i] += right[temp];
				temp += right[temp];
			}
		}
		ll max=0,ans;

		for(i = 1; i <= n; i++)
		{
			ans = data[i] * (left[i] + right[i] - 1);
			if(ans > max)
				max = ans;
		}
		printf("%lld\n",max);
	}
	return 0;
}
