#include<stdio.h>
int main()
{
	long long int x,z;
	scanf("%lld",&z);
	for(x=0;x<z;x++)
	{
		long long int p,q,r,i;
		scanf("%lld",&p);
		long long int a[p];
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&q);
		long long int b[q];
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&r);
		long long int c[r];
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		long long int k[p],j;
		for(i=0;i<p;i++)
			k[i]=0;
		for(i=0;i<q && i<p;i++)
		{
			for(j=i;j<r && j<q;j++)
			{
				if(a[i]<=b[j])
				{	k[i]=q-j;
					break;
				}
			}
			//printf("%lld ",k[i]);		
		}
		long long int l[q];
		for(i=0;i<q;i++)
			l[i]=0;
		for(i=0;i<q && i<r;i++)
		{
			for(j=i;j<r;j++)
			{
				if(b[i]<=c[j])
				{			
					l[i]=r-j;
					break;
				}	
			}
			//printf("%lld ",l[i]);

		}
		long long int m=0;
		for(i=0;i<p;i++)
		{
			for(j=i;j<k[i]+i;j++)
				m=m+l[j];
		}
		printf("%lld\n",m);
	}
	return 0;
}











