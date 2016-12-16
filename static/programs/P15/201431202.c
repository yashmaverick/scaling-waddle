#include<stdio.h>
int min(int i,int j,int a[])
{
	int k,min1=a[i];
	for(k=i;k<=j;k++)
	{
		if(a[k]<min1)
			min1=a[k];
	}
	return min1;
}
int main()
{
	int t,n,i,k;scanf("%d",&t);
	int a[100001]={};
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n-k+1;i++)
		{
			if(i==n-k+1)
				printf("%d",min(i,i+k-1,a));
			else
				printf("%d ",min(i,i+k-1,a));
		}
		printf("\n");
	}
	return 0;
}
