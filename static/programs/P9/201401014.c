#include<stdio.h>
#include<stdlib.h>
int main()
{
	int N,M,MOD,i,j,cum_weight;
	scanf("%d %d ",&N,&MOD);
	int weight[N+5],index[N+5],num[N+5],*pointer[N+5];
	for(i=0;i<N;i++)
	{
		scanf("%d",&M);
	//	int pointer[i][M+1];
		pointer[i]=(int *)malloc((M+5)*sizeof(int));
		cum_weight=0;
		for(j=0;j<M;j++)
		{
			scanf("%d",&pointer[i][j]);
			cum_weight=(((cum_weight)%MOD)+((pointer[i][j])%MOD)%MOD);
	//		printf("%d cum_weigt--\n",cum_weight);
		}
//		printf("%lld  ----weight\n",cum_weight);
		cum_weight=(cum_weight%MOD);
		weight[i]=cum_weight;
		index[i]=i;
		num[i]=M;
	}
	for(i=N-1;i>=0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(weight[j]>weight[j+1])
			{
				weight[j]=weight[j+1]+weight[j];;
				weight[j+1]=weight[j]-weight[j+1];
				weight[j]=weight[j]-weight[j+1];
				index[j]=index[j+1]+index[j];
				index[j+1]=index[j]-index[j+1];
				index[j]=index[j]-index[j+1];
				num[j]=num[j+1]+num[j];;
				num[j+1]=num[j]-num[j+1];
				num[j]=num[j]-num[j+1];
			}
		}
	}
//	printf("-------------\n");
//	printf("\n");
	for(i=0;i<N;i++)
	{
		printf("%d\n",weight[i]);
		for(j=0;j<num[i];j++)
			printf("%d\n",pointer[index[i]][j]);
//		if(i<N-1)
			printf("\n");
	}
	return 0;
}	
