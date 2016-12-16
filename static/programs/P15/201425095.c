#include<stdio.h>

int main()
{
	int A[10005];
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int N, K,min,j,i;
		scanf("%d %d", &N, &K);
		for(i=1; i<=N; i++)
		{	
			scanf("%d", &A[i]);
		}
		for(i=1; i<=N-K+1; i++)
		{
			if (min<i || i==1)
			{
				min =i;
				for(j=i+1; j<=i+K-1; j++)
				{
					if(A[min]>A[j])
						min=j;

				}
			}
			else if (A[min]>A[i+K-1])
					min=i+K-1;

			if(i==N-K+1)
				printf("%d", A[min]);
			else
				printf("%d ",A[min]);
		}
		printf("\n");
	}
	return 0;
}
