#include<stdio.h>
#include<stdlib.h>
typedef struct bag
{
	int num;
       long long int weight;
	long long int *head;  
}bag;
void sort(bag arr[], int N)
{
	int i, j;
	bag temp;
	long long int wt;
	for(i=1; i<N; i++)
	{
		temp=arr[i];
		wt=arr[i].weight;
		for(j=i-1; wt<arr[j].weight && j>=0; j--)
			arr[j+1]=arr[j];
		arr[j+1]=temp;
	}

}
int main()
{
	int N,i,j;
       long long int MOD, weight;
       bag arr[1001];
	scanf("%d %lld",&N, &MOD);
	for(i=0; i<N; i++)
	{
		scanf("%d", &arr[i].num);
		weight=0;
		arr[i].head=malloc(sizeof(long long int)*arr[i].num);
		for(j=0; j<arr[i].num; j++)
		{
		    	scanf("%lld", &arr[i].head[j]);
			weight=(weight+arr[i].head[j])%MOD;
		}
		arr[i].weight=weight;
	}

	sort(arr, N);
	//printf("OUTPUT:\n");
	for(i=0; i<N; i++)
	{
		printf("%lld\n", (arr[i].weight)%MOD);
		for(j=0; j<arr[i].num;j++)
			printf("%lld\n", arr[i].head[j]);
		printf("\n");
	}

	return 0;

}
			
	





	
