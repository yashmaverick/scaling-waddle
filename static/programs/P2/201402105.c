#include <stdio.h>
#include <limits.h>

long long int lower_equal(long long int a[], long long int val, long long int l, long long int r)
{
	if (l > r)
		return 0;
	if (a[r] <= val)
		return (r-l+1);
	if (a[l] > val)
		return 0;
	long long int st = l, ed = r, m;
	while ((ed-st) > 1) {
		m = (st+ed)/2;
		if (a[m] <= val)
			st = m+1;
		else
			ed = m;
	}
	if (a[st] > val)
		return (st-l);
	return (ed-l);
}

long long int upper_equal(long long int a[], long long int val, long long int l, long long int r)
{
	if (l > r)
		return 0;
	if (a[l] >= val)
		return (r-l+1);
	if (a[r] < val)
		return 0;
	long long int st = l, ed = r, m;
	while ((ed-st) > 1) {
		m = (st+ed)/2;
		if (a[m] >= val)
			ed = m-1;
		else
			st = m;
	}
	if (a[ed] < val)
		return (r-ed);
	return (r-st);
}

void merge_sort(long long int a[], long long int l, long long int m, long long int r)
{
	long long int i, j, k;
	long long int x[r-l+10], y[r-l+10];
	for (i = l, j = 0; i <= m; i++, j++)
		x[j] = a[i];
	x[j] = INT_MAX;
	for (i = m+1, j = 0; i <= r; i++, j++)
		y[j] = a[i];
	y[j] = INT_MAX;
	for (i = l, j = 0, k = 0; i <= r; i++) {
		if (x[j] < y[k]) {
			a[i] = x[j];
			j++;
		}
		else {
			a[i] = y[k];
			k++;
		}
	}
}

void merge(long long int a[], long long int l, long long int r)
{
	if (l < r) {
		long long int m = (l+r)/2;
		merge(a, l, m);
		merge(a, m+1, r);
		merge_sort(a, l, m, r);
	}
}

long long int x[100010], y[100010], z[100010];

int main()
{
	long long int t, p, q, r, i, ans, tmp1, tmp2;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld", &p);
		for (i = 0; i < p; i++)
			scanf("%lld", &x[i]);
		scanf("%lld", &q);
		for (i = 0; i < q; i++)
			scanf("%lld", &y[i]);
		scanf("%lld", &r);
		for (i = 0; i < r; i++)
			scanf("%lld", &z[i]);
		merge(x, 0, p-1);
		merge(y, 0, q-1);
		merge(z, 0, r-1);
		ans = 0;
		for (i = 0; i < q; i++) {
			tmp1 = lower_equal(x, y[i], 0, (i > (p-1) ? (p-1) : i));
			tmp2 = upper_equal(z, y[i], i, r-1);
			// printf("%lld %lld %lld\n", y[i], tmp1, tmp2);
			ans += tmp1*tmp2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

