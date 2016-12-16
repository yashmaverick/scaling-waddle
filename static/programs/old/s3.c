#include<stdio.h>

void insertionSort(long long int arr[], long long int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key;
	}
}

int main()
{
	long long int n;
	scanf("%lld", &n);
	long long int v[10005];
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%lld", &v[i]);
	}
	insertionSort(v, n);
	long long int k;
	scanf("%lld", &k);

	long long int base = v[0];
	long long int cur = 0;
	long long int ans = 0;
	for(i=0;i<n;i++)
	{
		if(cur + (v[i]-base)*i > k)
			break;
		cur += (v[i]-base)*i;
		base = v[i];
		ans = base;
	}

	ans += (k-cur)/i;

	printf("%lld\n", ans);

	return 0;
}
