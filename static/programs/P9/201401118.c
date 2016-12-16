#include<stdio.h>
#include<stdlib.h>
void qsort(void *base, size_t ntimes, size_t size, int (*compar)(const void *, const void *));
int cmpfunc(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int n,mod,i,j,m,k;
	scanf("%d %d",&n,&mod);
	int *arr[n],love[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		love[i]=m;
		arr[i]=(int *)malloc((m+1) * sizeof(int));
		j=0;
		arr[i][j]=0;
		for(j=1;j<=m;j++)
			scanf("%d",&arr[i][j]);
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<=love[i];j++)
			arr[i][0]=(arr[i][0]%mod)+(arr[i][j]%mod);
		arr[i][0]=arr[i][0]%mod;
	}
	int sum[n];
	for(i=0;i<n;i++)
		sum[i]=arr[i][0];
	qsort(sum,n,sizeof(int),cmpfunc);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[j][0]==sum[i])
			{
				for(k=0;k<=love[j];k++)
					printf("%d\n",arr[j][k]);
				arr[j][0]=-1000;
				printf("\n");
				break;
			}
		}
	}
	return 0;
}
