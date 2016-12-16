#include<stdio.h>
int main()
{
	int x,y;
	scanf("%d",&x);
	for(y=0;y<x;y++)
	{
		long long int n,k,a[100001],b[100001];
		scanf("%lld %lld",&n,&k);
		int d,i,m,c,j;
		d=(n-k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		m=a[0];
		c=0;
		for(i=0;i<=d;i++)
		{
			if(c>i)
			{
				if(a[i+k-1]<m)
					m=a[i+k-1];
				b[i]=m;
			}
			else
			{
				m=a[i];
				c=i;
				for(j=i;j<(i+k);j++)
				{
					if(a[j]<m)
					{
						m=a[j];
						c=j;
					}
				}
				b[i]=m;
			}
		}
		for(i=0;i<d;i++)
			printf("%lld ",b[i]);
		printf("%lld\n",b[d]);
	}
	return 0;
}
