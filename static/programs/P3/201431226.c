#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long int a[100001],max,i,n,p[100001],c[100001],j,k,x,min;
		scanf("%lld",&n);
		max=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		min=a[0];
		for(j=0;j<n;j++)
		{
			if(min>=a[j])
			{
				min=a[j];
			}
			p[j]=min;
		}
		for(x=n-1;x>=0;x--)
		{
			if(max<=a[x])
			{
				max=a[x];
			}
			c[x]=max;
		}
		max=0;
		for(k=0;k<n;k++)
		{
			if(c[k]-p[k]>max)
				max=c[k]-p[k];
		}
		/*	for(k=0;k<n;k++)
			{
			d[k]=c[k]-p[k];
			}
			for(s=0;s<n;s++)
			{
			if(max2<=d[s])
			{
			max2=d[s];
			}*/
	
	printf("%lld\n",max);
	}
	return 0;
}



