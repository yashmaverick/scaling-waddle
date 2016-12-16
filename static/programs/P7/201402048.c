#include<stdio.h>
#include<stdlib.h>
int main()
{
int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int i,j,k,l,n,x,z=0;
		long long int *a,*b;
		a=(long long int *)malloc(sizeof(long long int)*1000000);
		b=(long long int *)malloc(sizeof(long long int)*1000000);
		scanf("%lld",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		long long int m=a[0];
		for(j=0;j<1000000;j++)
			b[j]=0;
		for(k=1;k<n;k++)
		{
			if(m>a[k])
				m=a[k];
		}

		for(l=0;l<n;l++)
		{
			a[l]=a[l]-m;

		}
		for(i=0;i<n;i++)
			b[a[i]]++;
		for(i=0;i<1000000;i++)
		{
			//if(b[i]>1)
			//{
			z=z+((b[i])*(b[i]-1))/2;

			//}
		}
		printf("%lld\n",z);
	}
	
	return 0;
}
