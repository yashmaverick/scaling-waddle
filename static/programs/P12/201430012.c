#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 500100

int heights[MAX], prev_greater[MAX], prev_greater_equal[MAX], stack[MAX];
char ibuf[4096];
int input;

int readint(void);
void precompute(int);

int main()
{
	int i, N, prev;
	long long count;
	input = 4096;
	while (1)
	{
		N = readint();
		if (N == 0)
			break;
		for (i = 0; i < N; i++)
		{
			prev_greater[i] = prev_greater_equal[i] = -1;
			heights[i] = readint();
		}
		precompute(N);
		count = (long long)N * (N - 1) / 2;
		for (i = 1; i < N; i++)
			for (prev = i - 1; (prev != -1) && (prev >= prev_greater[i]); prev = prev_greater_equal[prev])
				count--;
		printf("%lld\n", count);
	}
	return 0;
}

void precompute(int N)
{
	int i, top;
	top = -1;
	stack[++top] = N - 1;
	for (i = N - 2; i >= 0; i--)
	{
		while ((top != -1) && (heights[stack[top]] < heights[i]))
			prev_greater[stack[top--]] = i;
		stack[++top] = i;
	}
	top = -1;
	stack[++top] = N - 1;
	for (i = N - 2; i >= 0; i--)
	{
		while ((top != -1) && (heights[stack[top]] <= heights[i]))
			prev_greater_equal[stack[top--]] = i;
		stack[++top] = i;
	}
}

int readint(void)
{
	int num;
	while ((input<4096) && (ibuf[input]<'0'))
		input++;
	if (input == 4096)
	{
		fread(ibuf, 1, 4096, stdin);
		input = 0;
		while ((input<4096) && (ibuf[input]<'0'))
			input++;
	}
	num = 0;
	while ((input<4096) && (ibuf[input] >= '0'))
		num = (num << 3) + (num << 1) + (ibuf[input++] - '0');
	if (input == 4096)
	{
		fread(ibuf, 1, 4096, stdin);
		input = 0;
		while ((input<4096) && (ibuf[input] >= '0'))
			num = (num << 3) + (num << 1) + (ibuf[input++] - '0');
	}
	return num;
}