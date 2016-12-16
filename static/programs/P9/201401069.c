#include<stdio.h>
#include<stdlib.h>
int O[1000][2];
void so_rt(int N)
{
	int x,y,swap0,swap1;
	for(x=0;x<(N-1);x++)
	{
		for(y=0;y<(N-x-1);y++)
		{
			if(O[y][1]>O[y+1][1])
			{
				swap0=O[y][0];
				swap1=O[y][1];
				O[y][0]=O[y+1][0];
				O[y][1]=O[y+1][1];
				O[y+1][0]=swap0;
				O[y+1][1]=swap1;
			}
		}
	}
}
int main()
{
	int *A[1000],N,mod,x,M,i,sum=0,m[1000];
	scanf("%d%d",&N,&mod);
	for(x=0;x<N;x++)
	{
		sum=0;
		scanf("%d",&M);
		m[x]=M;
		A[x]=(int*)malloc((M+1)*sizeof(int));
		for(i=1;i<=M;i++)
		{
			scanf("%d",&A[x][i]);
			sum=(sum+A[x][i]%mod)%mod;
		}
		A[x][0]=sum;
		O[x][0]=x; // 0th index of O has index of the main array
		O[x][1]=sum; //1st index of O has the total weight (sum) of the array
	}
	so_rt(N);
	for(x=0;x<N;x++)
	{
		printf("%d\n",A[O[x][0]][0]);
		for(i=1;i<=m[O[x][0]];i++)
		{
			printf("%d\n",A[O[x][0]][i]);
		}
		printf("\n");
	}
	return 0;
}
