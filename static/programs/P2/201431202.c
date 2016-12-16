#include<stdio.h>
long long int bs(long long int *a,long long int x,long long int low,long long int high)
{
	long long int mid=(low+high)/2,min=1000000000,index=-1;
	while(low<high)
	{
		if(a[mid]<x)
		{
			low=mid+1;
		}
		else if(a[mid]>=x)
		{
			if(a[mid]<min)
			{
				index=mid;
			}
			high=mid;
		}
		mid=(low+high)/2;
	}
	if(low==high)
	{
		if(a[mid]>=x)
		{
			if(a[mid]<min)
			{
				index=mid;
			}
		}
	}
	return index;
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int p,q,r;
		long long int a[100001],b[100001],c[100001],d[100001],e[100001],flag[100001],i;
		scanf("%lld",&p);	
		for(i=1;i<=p;i++)
		{
			scanf("%lld",&a[i]);
		}
		scanf("%lld",&q);
		for(i=1;i<=q;i++)
		{
			scanf("%lld",&b[i]);
		}
		scanf("%lld",&r);
		for(i=1;i<=r;i++)
		{
			scanf("%lld",&c[i]);
		}
		for(i=1;i<=q;i++)
		{
			long long int temp=bs(c,b[i],i,r);
			if(i<=temp && temp!=-1)
				d[i]=r-temp+1;
			else
				d[i]=0;
		}
		long long int j;
		d[q+1]=0;
		for(i=q;i>=1;i--)
		{
			d[i]=d[i]+d[i+1];
		}
		for(i=1;i<=p;i++)
		{	
			long long int temp=bs(b,a[i],i,q);
			if(temp>=i && temp!=-1)
			{
				e[i]=temp;
			}
			else
				e[i]=0;
		}
		long long int sum=0;
		i=1;
		long long int index;
		while(i<=q)
		{
			if(i<=p)
			{
				if(e[i]>=1)
				{
					sum=sum+d[e[i]];
					index=i;
				}
			}
			i++;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
