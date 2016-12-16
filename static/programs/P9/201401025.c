#include<stdio.h>
#include<stdlib.h>
struct bags
{
	int numbr,sum,*w;
};
int abc(const void *a,const void *b)
{
	struct bags *A;
	struct bags *B;
	A=(struct bags *)a;
	B=(struct bags *)b;
	return ((A->sum)-(B->sum));
}
int main()
{
	int n,i,j,mod,m;
	
	scanf("%d%d",&n,&mod);
	struct bags mani[n];
	//tmp=(int*)malloc(n*sizeof(int));
	//summ=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		mani[i].w=(int*)malloc(m*sizeof(int));
		mani[i].numbr=m;
		mani[i].sum=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&mani[i].w[j]);
			mani[i].sum=mani[i].sum + mani[i].w[j];
			mani[i].sum=mani[i].sum % mod;
		}
		//summ[i]=mani[i].sum;
	}
	qsort(mani,n,sizeof(struct bags),abc);
	for(i=0;i<n;i++)
	{
		printf("%d\n",mani[i].sum);

		//qsort(mani[tmp[i]].w,mani[tmp[i]].numbr,sizeof(int),xyz);
		for(j=0;j<mani[i].numbr;j++)
		{
			printf("%d\n",mani[i].w[j]);
		}
			printf("\n");
	}
	return 0;
}
