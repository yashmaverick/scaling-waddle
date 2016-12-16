#include<stdio.h>

int main()
{
	long long int n,i,j,a[100000],b[100000],c[100000],d[100000],fl;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			return 0;
		else
		{
			for(i=0;i<n;i++)
				scanf("%lld",&a[i]);
			b[0]=-1;
			for(i=1;i<n;i++)
			{
				j=i-1;fl=0;
				while(a[j]>=a[i])
				{
					j=b[j];
					if(j==-1)
					{
						fl=1;
						break;
					}
				}
				if(fl)
					b[i]=-1;
				else
					b[i]=j;
			}
			c[n-1]=n;
			for(i=n-2;i>=0;i--)
			{
				j=i+1;fl=0;
				while(a[j]>=a[i])
				{
					j=c[j];
					if(j==n)
					{
						fl=1;
						break;
					}
				}
				if(fl)
					c[i]=n;
				else
					c[i]=j;
			}
//			for(i=0;i<n;i++) printf("%lld ",a[i]);printf("\n");
//			for(i=0;i<n;i++) printf("%lld ",b[i]);printf("\n");
//			for(i=0;i<n;i++) printf("%lld ",c[i]);printf("\n");
			for(i=0;i<n;i++)
				d[i]=(-b[i]+c[i]-1)*a[i];
			long long int max=d[0];
			for(i=1;i<n;i++)
				if(d[i]>max)
					max=d[i];
//			for(i=0;i<n;i++) printf("%lld ",d[i]);printf("\n");
			printf("%lld\n",max);
		}
	}
}
