#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,mod,i,x,b[1000],c[1000],d[1000],l,j;
	scanf("%d%d",&n,&mod);
	int **a= (int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
	{
		c[i]=i;
		scanf("%d",&b[i]);
		a[i]=(int *)malloc((b[i]+1)*sizeof(int));
		a[i][0]=b[i];
		l=b[i];
		for(j=1;j<=l;j++)
		{
			scanf("%d",&x);
			a[i][j]=x;
		}
	}
	
	for(i=0;i<n;i++)
	{
		x=0;
		l=a[i][0];
		a[i][0]=0;
		for(j=1;j<=b[i];j++)
		{
			x=(x+a[i][j])%mod;
		}
		a[i][0]=x;
		d[i]=x;
	}
	int p,k;
	p=0;
	for(i=0;i<n;i++)
	{
		p=d[i];
		for(j=0;j<n;j++)
		{
			if(d[j] > p)
			{
				p=d[j];
				d[j]=d[i];
				d[i]=p;
				k=c[i];
				c[i]=c[j];
				c[j]=k;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		k=c[i];
		printf("%d\n",a[k][0]);
		for(j=1;j<=b[k];j++)
		{
			printf("%d\n",a[k][j]);
		}
		printf("\n");
	}
	return 0;
}

