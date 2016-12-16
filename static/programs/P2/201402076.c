#include<stdio.h>
int a[100005],b[100005],c[100005],d[100005],e[100005];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int p,q,r,i;
		scanf("%d",&p);
		for(i=0;i<p;i++)
		{
			scanf("%d",&a[i]);
		}
		scanf("%d",&q);
		for(i=0;i<q;i++)
		{
			scanf("%d",&b[i]);
		}
		scanf("%d",&r);
		for(i=0;i<r;i++)
		{
			scanf("%d",&c[i]);
		}
		int j=0;
		i=0;
		while(j<r)
		{
			if(j<i)
			{
				j++;
			}
			if(c[j]>=b[i])
			{
				d[i]=r-j;
				i++;
			}
			else
			{
				j++;
			}
		}
		for(j=i;j<q;j++)
			d[j]=0;
//		for(j=0;j<q;j++)
//			printf("%d ",d[j]);
	
		j=0;i=0;
		while(j<q)
		{
			if(j<i)
			{
				j++;
			}
			if(b[j]>=a[i])
			{
				e[i]=q-j;
				i++;
			}
			else
			{
				j++;
			}
		}
		for(j=i;j<p;j++)
			e[j]=0;
//		for(i=0;i<p;i++)
//			printf("%d ",e[i]);
		long long ans=0,sum=0;
		j=0;
		for(i=p-1;i>=0;i--)
		{
			while(e[i]>j)
			{
				sum=sum+(long long)d[q-j-1];
				j++;
			}
			ans=ans+sum;
		}
		printf("%lld\n",ans);

	}
	return 0;
}
