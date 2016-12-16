#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
struct element
{
	int depth;
	int deepest;
};
int arr[100000];

struct element find_max_depth(int, int, int);
int smallest_element_greater_than_key(int, int, int);

int main()
{
	int i, N, T;
	scanf("%d", &T);
	struct element ans;
	while (T--)
	{
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		ans = find_max_depth(0, N - 1, 0);
		printf("%d %d\n", ans.deepest, ans.depth);
	}
	return 0;
}

struct element find_max_depth(int low, int high, int depth)
{
	int mid;
	struct element left, ret, right;
	if (low > high)
	{
		ret.depth = -1;
		ret.deepest = INT_MAX;
		return ret;
	}
	if (low == high)
	{
		ret.depth = depth;
		ret.deepest = arr[low];
		return ret;
	}
	mid = smallest_element_greater_than_key(low, high - 1, arr[high]) - 1;
	left = find_max_depth(low, mid, depth + 1);
	right = find_max_depth(mid + 1, high - 1, depth + 1);
	if (left.depth < right.depth)
		return right;
	else
		return left;
}

int smallest_element_greater_than_key(int start, int end, int key)
{
	int high, low, mid;
	if (key < arr[start])
		return start;
	if (key >= arr[end])
		return end + 1;
	low = start;
	high = end;
	while (low < high)
	{
		mid = (low + high) / 2;
		if (arr[mid] <= key)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}