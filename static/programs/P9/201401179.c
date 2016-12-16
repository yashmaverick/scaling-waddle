#include <stdio.h>
#include <stdlib.h>
 
typedef struct Bags
{
	long int Sum;
	long int *weights;
	int nofw;

}Bags;

struct Bags items[1001];
struct Bags temp;

int main()
{
	
	int N,i,j;
	long long int Mod;
	scanf("%d%lld",&N,&Mod);
	for (i = 0; i < N; i++)
	{
		items[i].Sum=0;
		scanf("%d",&items[i].nofw);
		items[i].weights=(long int)malloc(items[i].nofw*(sizeof(long int)));
		for (j = 0; j < items[i].nofw; j++)
		{
			scanf("%ld",&items[i].weights[j]);
			items[i].Sum+=items[i].weights[j];
		}
		items[i].Sum=(items[i].Sum)%Mod;

	}


	for(i=0;i<=N-1;i++)
		for(j=0;j<(N-1);j++)
			if(items[j].Sum>items[j+1].Sum)
			{
				temp = items[j+1];
				items[j+1]=items[j];
				items[j]=temp;

			}

	for(i=0;i<N;i++)
	{
		printf("%ld",items[i].Sum);
		printf("\n");
		for(j=0;j<items[i].nofw;j++)
			printf("%ld\n",items[i].weights[j]);
		printf("\n");

	}		

   return 0;
}
