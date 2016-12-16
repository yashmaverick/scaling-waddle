#include<stdio.h>
#include<stdlib.h>
int *a[1005],b[2][1005],c[1005];
int main()
{
	int i,j,k,n,mod,sum,t,t1;
	scanf("%d%d",&n,&mod);
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
		sum=0;
		a[i]=(int*)malloc((c[i]+1)*sizeof(int));
		for(j=1;j<=c[i];j++)
		{
			scanf("%d",&t);
			sum=(sum+t%mod)%mod;
			a[i][j]=t;
		}
		a[i][0]=sum;
	}
	for(i=0;i<n;i++)
	{
		b[0][i]=a[i][0];
		b[1][i]=i;
	}
	for(i=n-2;i>=0;i--)
	{
		for(j=0;j<=i;j++)
		{
			if (b[0][j]>b[0][j+1])
			{
				t=b[0][j];
				b[0][j]=b[0][j+1];
				b[0][j+1]=t;
				t1=b[1][j];
				b[1][j]=b[1][j+1];
				b[1][j+1]=t1;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<c[b[1][i]]+1;j++)
		{
			printf("%d\n",a[b[1][i]][j]);
		}
		printf("\n");
	}
	return 0;
}
