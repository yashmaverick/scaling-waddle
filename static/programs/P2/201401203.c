#include<stdio.h>
int p,q,r;
int search(int beg,int end,long long int n,long long int a[],int flag)
{
	int mid;
	if(flag==0)
	{
		if(a[0]>n)
			return -1;
		if(p<=end)
			if(n>=a[p-1])
				return p-1;
		if(n>=a[end])
			return end;
	}
	else 
	{
		if(end>=r||a[end]<n)
			return -1;
		if(n<=a[beg])
			return beg;
	}
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(n==a[mid]||(n<a[mid]&&mid==0))
			return mid;
		else if(mid>0&&n<a[mid]&&n>a[mid-1])
			if(flag==0)
				return mid-1;
			else 
				return mid;
		else if(n>a[mid])
			beg=mid+1;
		else if(n<a[mid])
			end=mid-1;
	}
	return -1;
}
int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}
int main()
{
	long long int a[100000],b[100000],c[100000];
	int i,j,k,t,c2,c1,xa[100000],xc[100000];
	scanf("%d",&t);
	long long int sum;
	while(t--)
	{
		sum=0;
		scanf("%d",&p);
		for(i=0;i<p;i++)
			scanf("%lld",&a[i]);
		scanf("%d",&q);
		for(i=0;i<q;i++)
			scanf("%lld",&b[i]);
		scanf("%d",&r);
		for(i=0;i<r;i++)
			scanf("%lld",&c[i]);
		for(i=0;i<q;i++)
		{
			xa[i]=search(0,i,b[i],a,0);
			xc[i]=search(i,r-1,b[i],c,1);
		}
	/*	for(i=0;i<q;i++)
			printf("%d ",xa[i]);
		printf("\n");
		for(i=0;i<q;i++)
			printf("%d ",xc[i]);
		printf("\n");*/
		for(i=0;i<q;i++)
		{
			if(xa[i]>=0&&xc[i]>=0)
			{
				if(xa[i]<=xc[i])
					sum+=(xa[i]+1)*(r-xc[i]);
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
