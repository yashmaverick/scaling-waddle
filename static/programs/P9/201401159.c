#include <stdio.h>
#include <stdlib.h>

void swapass(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int main()
{
	int n,i,j,k,arr[1000010];
	long mod;
	scanf("%d %ld",&n,&mod);
	int *arw=(int*)malloc(n*sizeof(int));
	int *arm=(int*)malloc(n*sizeof(int));
	for(i=0,j=0;i<n;i++)
	{
		arm[i]=j;
		scanf("%d",&arr[j]);
		int sum=0;
		for(k=1;k<=arr[j];k++)
		{
			scanf("%d",&arr[j+k]);
			sum=(sum+arr[j+k])%mod;
		}
		j=j+k;
		arw[i]=sum%mod;
	}
	for(i=1;i<n;i++)
	{
		j=i;
		while(j>0&&arw[j]<arw[j-1])
		{
			swapass(arw,j,j-1);
			swapass(arm,j,j-1);
			j--;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",arw[i]);
		k=arm[i];
		for(j=1;j<=arr[arm[i]];j++)
			printf("%d\n",arr[j+k]);
		printf("\n");
	}
	return 0;
}