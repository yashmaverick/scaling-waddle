#include<stdio.h>
#include<string.h>

char str[100005];
int counts[100005][2], temp[100005][2];

void merge(int low, int high, int n)
{
	int i, j, k, mid;
	mid = (low + high) / 2;
	i = k = low;
	j = mid + 1;
	while ((i <= mid) && (j <= high))
	{
		if ((counts[i][0] < counts[j][0]) || ((counts[i][0] == counts[j][0]) && (counts[i][1] < counts[j][1])))
		{
			temp[k][0] = counts[i][0];
			temp[k][1] = counts[i][1];
			i++;
		}
		else
		{
			temp[k][0] = counts[j][0];
			temp[k][1] = counts[j][1];
			j++;
		}
		k++;
	}
	while (i <= mid)
	{
		temp[k][0] = counts[i][0];
		temp[k][1] = counts[i][1];
		i++;
		k++;
	}
	while (j <= high)
	{
		temp[k][0] = counts[j][0];
		temp[k][1] = counts[j][1];
		j++;
		k++;
	}
	for (i = low; i < k; i++)
	{
		counts[i][0] = temp[i][0];
		counts[i][1] = temp[i][1];
	}
}

void merge_sort(int low, int high, int n)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge_sort(low, mid, n);
		merge_sort(mid + 1, high, n);
		merge(low, high, n);
	}
}

int main()
{
	int i, j, jcount, mcount, n, rcount, t;
	long long ans;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", str);
		n = strlen(str);
		jcount = mcount = rcount = 0;
		for (i = 0; i < n; i++)
			counts[i][0] = counts[i][1] = 0;
		for (i = 1; i <= n; i++)
		{
			if (str[i - 1] == 'J')
				jcount++;
			else if (str[i - 1] == 'M')
				mcount++;
			else
				rcount++;
			counts[i][0] = jcount - mcount;
			counts[i][1] = jcount - rcount;
		}
		merge_sort(0, n, n + 1);
		ans = 0;
		i = 0;
		while (i <= n)
		{
			j = i + 1;
			while ((j <= n) && (counts[j - 1][0] == counts[j][0]) && (counts[j - 1][1] == counts[j][1]))
				j++;
			ans += (long long)(j - i) * (j - i - 1) / 2;
			i = j;
		}
		printf("%lld\n", ans);
	}
	return 0;
}