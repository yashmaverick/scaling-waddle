#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int arr[1005];
bool compute(int arr[], int n, int k);
void merge_sort(int *arr, int lower, int upper, int n);
void merge(int *arr, int lower, int upper, int n);

int main()
{
	int t, i, k, length;
	char s[1000];
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d%d", &length, &k);
		for (i = 0; i < length; i++)
			scanf("%s%d", s,&arr[i]);
		merge_sort(arr, 0, length - 1, length);
		if (compute(arr, length, k))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
void merge_sort(int *arr, int lower, int upper, int n)
{
	int middle;
	if (lower<upper)
	{
		middle = (lower + upper) / 2;
		merge_sort(arr, lower, middle, n);
		merge_sort(arr, middle + 1, upper, n);
		merge(arr, lower, upper, n);
	}
}

void merge(int *arr, int lower, int upper, int n)
{
	int i, j, k, middle;
	int *temp;
	middle = (lower + upper) / 2;
	i = k = lower;
	j = middle + 1;
	temp = (int *)malloc(n*sizeof(int));
	while ((i <= middle) && (j <= upper))
	{
		if (arr[i]<arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	while (j <= upper)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}
	while (i <= middle)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	for (i = lower; i<k; i++)
		arr[i] = temp[i];
	free(temp);
	temp = NULL;
}

bool compute(int arr[], int n, int k)
{
	int left, right, i;
	for (i = 0; i < n - 2; i++)
	{
		left = i + 1;
		right = n - 1;
		while (left < right)
		{
			if (arr[i] + arr[left] + arr[right] == k)
				return true;
			else if (arr[i] + arr[left] + arr[right] < k)
				left++;
			else
				right--;
		}
	}
	return false;
}