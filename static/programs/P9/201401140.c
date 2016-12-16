#include<stdio.h>
#include<stdlib.h>
void inst(long long int c[],long long int n,long long int d[])
{
	long long int i,j,temp;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(c[d[i]]>c[d[j]])
			{
				temp=d[i];
				d[i]=d[j];
				d[j]=temp;
			}
		}
	}
}
int main()
{
	long long int n,mod,j,i,m;
	scanf("%lld%lld",&n,&mod);
	long long int *a[n],b[n],sum,c[n],d[n];
	for(i=0;i<n;i++)
	{
		sum=0;
		scanf("%lld",&m);
		b[i]=m;
		a[i]=(long long int *)malloc(m*sizeof(long long int));
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
			sum=(sum+a[i][j])%mod;
		}
		c[i]=sum;
		d[i]=i;
	}
	inst(c,n,d);
	for(i=0;i<n;i++)
	{
		printf("%lld\n",c[d[i]]);
		for(j=0;j<b[d[i]];j++)
		{
			printf("%lld\n",a[d[i]][j]);
		}
		printf("\n");
	}
	return 0;
}
