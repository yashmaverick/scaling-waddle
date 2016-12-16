#include<stdio.h>
#include<stdlib.h>
typedef struct Bags
{
	int start, M, total;
}x;

int main()
{
	int N;
        long long int MOD;
	scanf("%d %lld", &N, &MOD);
	int a;
	a = N;
	int A[1000001];


	struct Bags *ptr;
	ptr=(struct Bags*)malloc(sizeof(struct Bags)*N); 
	int i;
	int j;
	for(i=0 ; i<N ;i++)
	{
		//ptr[i];
		scanf("%d", &(ptr[i].M));
		ptr[i].total=0;

	//	int j;
		for(j=ptr[i].start; j<(ptr[i].start+ptr[i].M); j++ )
		{
			scanf("%d", &A[j]);
			ptr[i].total+=A[j];
			ptr[i].total=ptr[i].total%MOD;
		}
		ptr[i+1].start=ptr[i].start+ptr[i].M;
	}

	for(i=0; i<N; i++ )
	{
		for(j=1;j<N;j++ )
		{
			if(ptr[j].total<ptr[j-1].total)
			{
				struct Bags temp = ptr[j];
				ptr[j] = ptr[j-1];
				ptr[j-1]= temp;
			}
		}
	}


	for ( i=0; i<N; i++ )
	{
		printf("%d\n", ptr[i].total );
		for (j=ptr[i].start; j<ptr[i].start+ptr[i].M; j++ )
		{
			printf("%d\n", A[j]);
		}
		printf("\n");
	}
	


	return 0;
}
