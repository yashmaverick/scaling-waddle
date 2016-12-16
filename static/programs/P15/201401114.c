#include<stdio.h>
typedef long long int lint;
typedef struct array
{
	lint val;
	int index;
}array;
void print(array stack[], int topl, int topr)
{
	int i;
	for(i=topl; i<=topr; i++)
		printf("%lld- ", stack[i].val);
	printf("\n");
}
void find(lint arr[], int N, int K)
{
	int i,j, topl=0,topr=0;
	array stack[100001];
	stack[topr].val=arr[0];
	stack[topr].index=0;
	for(i=0; i<K; i++)
	{
		if(arr[i]>stack[topr].val)
		{
			stack[++topr].val=arr[i];
			stack[topr].index=i;
		}
		else if(arr[i]<stack[topr].val)
		{
			while(arr[i]<stack[topr].val && topr>=topl)
				topr--;
			stack[++topr].val=arr[i];
			stack[topr].index=i;
		}
	}
	//print(stack,topl,topr);
	for(i=K; i<N; i++)
	{
		printf("%lld ", stack[topl].val);

		while((i>stack[topl].index+K-1) && (topl<=topr))
			topl++;
		if(topl>topr)
		{
			topl=topr=0;
			stack[topl].val=arr[i];
			stack[topl].index=i;

		}
		else
		{
			while((arr[i]<stack[topr].val) && (topl<=topr))
				topr--;
			if(topl>topr)
			{
				topl=0;
				topr=0;
				stack[topl].val=arr[i];
				stack[topl].index=i;
			}
			else
			{
				stack[++topr].val=arr[i];
				stack[topr].index=i;
			}
		}
		//printf("For %lld stack is: ",arr[i]);
		//print(stack,topl,topr);
	}
	printf("%lld\n",stack[topl].val);
	//print(stack,topl,topr);
}
int main()
{
	int T,N,K,i;
	lint arr[10001];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &N, &K);
		for(i=0; i<N; i++)
			scanf("%lld", &arr[i]);
		find(arr,N,K);
	}
	return 0;
}




