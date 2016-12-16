#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,m,j;
	long int mod;
	long int **a;
	scanf("%d %ld",&n,&mod);
	a=(long int **)calloc(n,sizeof(long int *));
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		a[i]=(long int *)calloc(m+2,sizeof(long int));
		a[i][0]=m;a[i][m+1]=0;
		for(j=1;j<=m;j++)
		{
			scanf("%ld",&a[i][j]);
			a[i][m+1]=(a[i][m+1]+a[i][j])%mod;
		}
	}
	long int *t;
	int fl=1;
	while(fl)
	{
		fl=0;
		for(i=0;i<n-1;i++)
			if(a[i][a[i][0]+1]>a[i+1][a[i+1][0]+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=t;
				fl=1;
			}
	}
	for(i=0;i<n;i++)
	{
		printf("%ld\n",a[i][a[i][0]+1]);
		for(j=1;j<=a[i][0];j++)
			printf("%ld\n",a[i][j]);
		printf("\n");
	}
	return 0;
}
