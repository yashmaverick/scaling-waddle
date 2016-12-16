#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,mod,k,i,j,m;
	scanf("%d%d",&n,&mod);
	int *a[n],b[n],c[n],d[n],temp;
	for(i=0;i<n;i++)
	{

		scanf("%d",&m);
		d[i]=m;		
		a[i]=(int *)malloc(m*sizeof(int));
		b[i]=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
			b[i]=((b[i]%mod)+(a[i][j]%mod))%mod;
		}
		c[i]=i;
	}

	for (i=1;i<n;i++) {
		j=i;

		while (j> 0 && b[j]<b[j-1]) {
			temp=b[j];
			b[j]=b[j-1];
			b[j-1]=temp;
			temp=c[j];
			c[j]=c[j-1];
			c[j-1]=temp;
			temp=d[j];
			d[j]=d[j-1];
			d[j-1]=temp;
			j--;
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d\n",b[i]);
		k=c[i];
		for(j=0;j<d[i];j++)
			printf("%d\n",a[k][j]);
		printf("\n");
	}
	return 0;
}
