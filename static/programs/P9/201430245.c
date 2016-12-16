#include<stdio.h>
#include<stdlib.h>
void insertion(int **a,int n)
{
	int *temp;
	int i,j;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while((*temp<a[j][0])&&(j>=0))
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=temp;
	}
}
int main()
{
	int n,mod;
	scanf("%d%d",&n,&mod);
	int **a;
	a=(int **)malloc(sizeof(int *)*n);
	int i,j,k,l,m[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&m[i]);
		a[i]=(int *)malloc(sizeof(int)*(m[i]+2));
		a[i][0]=0;
		a[i][1]=m[i];
		for(j=2;j<=m[i]+1;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][0]=(a[i][0]+a[i][j])%mod;
		}
	}
	insertion(a,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<=a[i][1]+1;j++)
		{
			if(j!=1)
			{
				printf("%d\n",a[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
