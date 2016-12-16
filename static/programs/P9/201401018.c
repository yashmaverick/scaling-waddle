#include<stdio.h>
#include<stdlib.h>
typedef struct hello
{
	long long sum;
	//int idx;
	int M;
}bag;
//int cmpfunc (const void * a, const void * b)
//{
//	   return ( *(int*)a - *(int*)b );
//}


int main()
{
	int N,i,j;
	long long MOD;
	scanf("%d%lld",&N,&MOD);
	bag *array_struct;
	array_struct=((bag *)malloc(N*sizeof(bag)));
	long long *A[N];
	for(i=0;i<N;i++)
	{
		array_struct[i].sum=0;
		scanf("%d",&array_struct[i].M);
		//long long *A[i];
		A[i]=((long long *)malloc( array_struct[i].M * sizeof(long long) ));
		for(j=0;j<array_struct[i].M;j++)
		{
			scanf("%lld",&A[i][j]);
		//	array_struct[i].idx=i;
			array_struct[i].sum=((array_struct[i].sum%MOD)+(A[i][j]%MOD))%MOD;
		}
		//array_struct[i].sum=(array_struct[i].sum)%MOD;
	}
	/*
	for(i=0;i<N;i++)
	{
		printf("%lld\n",array_struct[i].sum);
		for(j=0;j<array_struct[i].M;j++)
		{
			//printf("%lld\n",array_struct[i].sum);
			printf("%lld\n",A[i][j]);
		}
		printf("\n");
	}
	*/
	for(i=0;i<(N-1);i++)
	{
		for(j=0;j<N-i-1;j++)
		{
			if(array_struct[j].sum>array_struct[j+1].sum)
			{
				int swap=array_struct[j].sum;
				array_struct[j].sum=array_struct[j+1].sum;
				array_struct[j+1].sum=swap;
				long long *temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				int swap1=array_struct[j].M;
				array_struct[j].M=array_struct[j+1].M;
				array_struct[j+1].M=swap1;
			}
		}
	}

	//printf("\n");

	/*
	for(i=0;i<N;i++)
		         {
			                   printf("%lld\n",array_struct[i].sum);
			                    for(j=0;j<array_struct[i].M;j++)
				                    {
					                              //printf("%lld\n",array_struct[i].sum);
					                               printf("%lld\n",A[i][j]);
					                       }
			                     printf("\n");
			              }
	*/
	for(i=0;i<N;i++)
	{
		printf("%lld\n",array_struct[i].sum);
		for(j=0;j<array_struct[i].M;j++)
		{
			//printf("%lld\n",array_struct[i].sum);
			printf("%lld\n",A[i][j]);
		}
		printf("\n");
	}

	//qsort(array_struct, N, sizeof(int), cmpfunc);
	/*for(i=0;i<N;i++)
	{
		for(j=0;j<array_struct[i].M;j++)
		{
			if(array_struct[i].sum==array_struct[i+1].sum)
			{
				if(array_struct[i].idx<array_struct[i+1].idx)
				{
					
				}
			}
	//		printf("%lld\n",array_struct[i].sum);
	//		printf("%lld\n",A[i][j]);
			//if(array_struct[i].sum==array_struct[i+1].sum)
			//	if(array_struct[i].idx<array_struct[i+1].idx)
			//		printf("%lld\n",A[i][j]);
	//	}
	//	printf("\n");
	//}*/
	return 0;
}
