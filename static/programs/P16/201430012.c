#include <stdio.h>
#define LL long long
long long arr[31] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824LL};

int find(int n)
{
	int low, mid, high;
	low = 0; 
	high = 30;
	while (low != high)
	{
		mid = (low + high) / 2;
		if (arr[mid] == n)
			return mid;
		else if (arr[mid]<n && arr[mid + 1]>n)
			return mid;
		else if (arr[mid] < n)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

int main()
{
	int t, n, i;
	long long ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ans = find(n);
		ans += find((2 * n) / 3);
		printf("%lld\n", ans);
	}
	return 0;
}