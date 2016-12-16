#include<stdio.h>
#include<malloc.h>

int main()
{
	int *A, *B, *C;
	int i, j, k, P, Q, R, T;
	long long count;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &P);
		A = (int *)malloc(sizeof(int) * P);
		for (i = 0; i < P; i++)
			scanf("%d", &A[i]);
		scanf("%d", &Q);
		B = (int *)malloc(sizeof(int) * Q);
		for (j = 0; j < Q; j++)
			scanf("%d", &B[j]);
		scanf("%d", &R);
		C = (int *)malloc(sizeof(int) * R);
		for (k = 0; k < R; k++)
			scanf("%d", &C[k]);
		count = 0;
		i = k = 0;
		for (j = 0; (i < P) && (j < Q) && (k < R); j++)
		{
			while ((i < P) && (i <= j) && (A[i] <= B[j]))
				i++;
			while ((k < R) && ((k < j) || (C[k] < B[j])))
				k++;
			count += (long long)i * (R - k);

		}
		printf("%lld\n", count);
		free(A);
		free(B);
		free(C);
	}
	return 0;
}