#include<stdio.h>
int k,A[10001],min,B[10001],n;
int minf(int i)
{
	int p,min=A[i];
	for(p=i+1;p<=i+k-1;p++)
		if(A[p]<min)
			min=A[p];
	B[i]=min;
	return min;
}
int main()
{
	int i,t,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&A[i]);
		for(i=1;i<=n-k+1;i++)
		{
			//printf("i=%d min=%d\n",i,min);
			if(i==1 || min==A[i-1])
			
				min=minf(i);
			else
			{
				if(A[i+k-1]<min)
				{
					B[i]=A[i+k-1];
					min=B[i];
				}
				else
				{
					B[i]=B[i-1];
					//min=B[i];
				}
			}
			//printf("i=%d min=%d\n\n",i,min);
		}
		for(i=1;i<=n-k+1;i++)
			if(i!=n-k+1)
				printf("%d ",B[i]);
			else
				printf("%d",B[i]);
		printf("\n");
		min=0;
	}
	return 0;
}
