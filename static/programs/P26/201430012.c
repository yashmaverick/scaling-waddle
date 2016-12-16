/*Prime Path*/

#include<stdio.h>
#include<string.h>

#define MAX 9999
#define NUMPRIMES 1061

char isprime[MAX + 1], visited[NUMPRIMES];
int pos[MAX + 1], q[NUMPRIMES];
int dist[NUMPRIMES][NUMPRIMES];

void initialize(void);
void sieve(void);
void precompute(void);

int main()
{
	int end, start, T;
	initialize();
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &start, &end);
		if (dist[pos[start]][pos[end]] != -1)
			printf("%d\n", dist[pos[start]][pos[end]]);
		else
			puts("Impossible");
	}
	return 0;
}

void initialize(void)
{
	sieve();
	precompute();
}

void sieve(void)
{
	int i, j;
	memset(isprime, 1, sizeof(isprime));
	isprime[0] = isprime[1] = 0;
	for (i = 2; i * i <= MAX; i++)
		if (isprime[i])
			for (j = i * i; j <= MAX; j += i)
				isprime[j] = 0;
	j = 0;
	for (i = 1009; i <= MAX; i++)
		if (isprime[i])
			pos[i] = j++;
}

void precompute(void)
{
	int power[5] = { 1, 10, 100, 1000, 10000 };
	int current_prime, head, i, j, k, next_prime, tail;
	memset(dist, -1, sizeof(dist));
	for (i = 1009; i <= MAX; i++)
	{
		if (isprime[i])
		{
			memset(visited, 0, sizeof(visited));
			head = tail = 0;
			q[tail++] = i;
			visited[pos[i]] = 1;
			dist[pos[i]][pos[i]] = 0;
			while (head != tail)
			{
				current_prime = q[head++];
				for (j = 0; j < 4; j++)
				{
					for (k = (j == 3) ? 1 : 0; k <= 9; k++)
					{
						next_prime = ((current_prime / power[j + 1]) * power[j + 1]) + (k * power[j]) + (current_prime % power[j]);
						if (isprime[next_prime] && !visited[pos[next_prime]])
						{
							q[tail++] = next_prime;
							visited[pos[next_prime]] = 1;
							dist[pos[i]][pos[next_prime]] = dist[pos[i]][pos[current_prime]] + 1;
						}
					}
				}
			}
		}
	}
}