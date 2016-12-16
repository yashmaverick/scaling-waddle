#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int n,mod,i,j,m,temp,k,min,p,L;
	scanf("%lld%lld",&n,&mod);
long long int *a[1009],*b,*c,*d,*o;
	//	*a=(int *)malloc(sizeof(int)*n); 
	b=(long long int *)malloc(sizeof(long long int)*n);
	c=(long long int *)malloc(sizeof(long long int)*n);
	d=(long long int *)malloc(sizeof(long long int)*n);
	o=(long long int *)malloc(sizeof(long long int)*n);
	for(i=0;i<n;i++)
	{
		b[i]=0;
		scanf("%lld",&c[i]);
		a[i]=(long long int *)malloc(sizeof(long long int)*c[i]);
		for(j=0;j<c[i];j++)
		{
			scanf("%lld",&a[i][j]);
			b[i]=b[i]+a[i][j];
		}
		b[i]=b[i]%mod;
	}
	for(i=0;i<n;i++)
		o[i]=b[i];
        for(i=0;i<n;i++)
	{
		k=0;
		for(j=0;j<n;j++)
		{
				if(b[j]<b[k])
				{
				k=j;}
		}
		d[i]=k;
		b[k]=1000000007;
	}
/*        for(i=0;i<n;i++)
	printf("%d\n",d[i]);*/
	for(i=0;i<n;i++)
	{
		p=d[i];
		printf("%lld\n",o[p]);
		for(j=0;j<c[p];j++)
		printf("%lld\n",a[p][j]);
	//	if(i!=n-1)
		printf("\n");
	}
	return 0;
}

