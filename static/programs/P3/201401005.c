#include<stdio.h>
long long int a[100001];

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long int i, n, max=0, diff, min;
		scanf("%lld", &n);
		for(i=0; i<n; i++)
			scanf("%lld", &a[i]);

		min = a[0];
		for(i=0; i<n-1; i++)
		{
			if(a[i] <= min)
				min = a[i];
			if(a[i+1] > min)
				diff = a[i+1]-min;
			
			else
				diff = 0;
			if(diff > max)
				max = diff;
		}
		printf("%lld\n", max);
	}

	return 0;
}
