#include<stdio.h>

#define MOD 1000000007

long long left_counts[40], modulo_counts[40], right_counts[40];

long long modpow(long long a, long long b, long long n)
{
	long long base, result;
	result = 1 % n;
	base = a % n;
	while (b > 0)
	{
		if (b & 1)
			result = (result * base) % n;
		b >>= 1;
		base = (base * base) % n;
	}
	return result;
}

int main()
{
	int d, i, j, limit, m, N, power, T;
	long long ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d %d", &limit, &d, &m, &N);
		for (i = 0; i < N; i++)
			modulo_counts[i] = 0;
		for (i = 0; (i < N) && (i <= limit); i++)
		{
			power = (int)modpow(i, d, N);
			modulo_counts[power] = (modulo_counts[power] + ((limit - i) / N) + 1) % MOD;
		}
		for (i = 0; i < N; i++)
			left_counts[i] = right_counts[i] = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				left_counts[(i + j) % N] = (left_counts[(i + j) % N] + (modulo_counts[i] * modulo_counts[j]) % MOD) % MOD;
		for (i = 0; i < N; i++)
			right_counts[(m - i + N) % N] = (right_counts[(m - i + N) % N] + modulo_counts[i]) % MOD;
		ans = 0;
		for (i = 0; i < N; i++)
			ans = (ans + (left_counts[i] * right_counts[i]) % MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}