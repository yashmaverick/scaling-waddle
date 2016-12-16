#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int n,mod;
	scanf("%lld%lld",&n,&mod);
	long long int *a[n],i,j;
	long long int x[n],w;
	int y[n];
	for(i=0;i<n;i++)
	{
		w=0;
		scanf("%d",&y[i]);
		a[i]=(long long int *)malloc(y[i]*sizeof(long long int));
		for(j=0;j<y[i];j++)
		{
			scanf("%lld",&a[i][j]);
			w=w+a[i][j];
		}
		x[i]=w%mod;
	}
	long long int temp,z[n];
	for(i=0;i<n;i++)
		z[i]=i;
	for(i=n-1;i>0;i--)
	{
		for(j=0;j<i;j++)
		{
			if(x[z[j]]>x[z[j+1]])
			{
				temp=z[j];
				z[j]=z[j+1];
				z[j+1]=temp;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%lld\n",x[z[i]]);
		for(j=0;j<y[z[i]];j++)
			printf("%lld\n",a[z[i]][j]);
		printf("\n");
	}
	return 0;
}
