#include<stdio.h>
#include<stdlib.h>
int *swap;
int a,b;
void s(int **AB,int n)
{
	for(a=0;a<n-1;a++)
	{ if(*AB[a] > *AB[a+1])
		{
			swap=AB[a];
			AB[a]=AB[a+1];
			AB[a+1]=swap;
			for(b=1;b<=a;b++)
			{
				if(*AB[a-b] > *AB[a-b+1])
				{
					swap=AB[a-b];
					AB[a-b]=AB[a-b+1];
					AB[a-b+1]=swap;
				}
				else
					break;
			}}}}
int main()
{    
	int N,i;int *AB[1001];
	int MOD,sum,F,x,t;
	scanf("%d %d",&N,&MOD);
	for(i=0;i<N;i++)
	{    
		scanf("%d",&F);
		AB[i]=(int *)malloc((F+2)*sizeof(int *));
		sum=0;
		for(x=1;x<=F;x++)
		{    
			scanf("%d",&t);
			*(AB[i]+x)=t;
			sum=((sum % MOD)+(t % MOD))%MOD;
		}
		*(AB[i]+x)=-1;
		*AB[i]=sum;
	}
	s(AB,N);
	for(i=0;i<N;i++)
	{ x=0;
		while(*(AB[i]+x)!=-1)
		{
			printf("%d\n",*(AB[i]+x));
			x++;
		}
		printf("\n");
	}
	return 0;
}

