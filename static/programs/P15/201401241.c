#include<stdio.h>
int a[1000000],t;
void max(int a[],int n,int k)
{
	int i,j,min=200000000;
	for(i=0;i<n-k;i++)
	{
		min=a[i];
		for(j=1;j<k;j++)
		{
			if(a[i+j]<min)
				min=a[i+j];
		}
		printf("%d ",min);
	}
	if(i==n-k)
	{
		min=a[i];
		for(j=1;j<k;j++)
		{
			if(a[i+j]<min)
				min=a[i+j];
		}
		printf("%d",min);
	}
}

int main()
{
	int n,k,l;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		for(l=0;l<n;l++)
		{
			scanf("%d",&a[l]);
		}
		max(a,n,k);
		printf("\n");
	}
	return 0;
}
