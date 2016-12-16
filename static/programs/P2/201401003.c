#include<stdio.h>
long long int n,m,k;
long long int bsearch1(long long int a[],long long int x,long long int start,long long int end)
{
	int mid;
	while((start+1)<end)
	{
		mid=(start+end)/2;
		if(a[mid]<=x && a[mid+1]>x)
			return mid;
		else if(a[mid]>x)
			end=mid-1;
		else
			start=mid+1;
	}
	if(a[start]<=x && a[start+1]>x)
		return start;
	else if(a[end]<=x)
	{
		if(end==(n-1) || (end<(n-1) && a[end+1]>x))
			return end;
	}
	else
		return -1;
}
long long int bsearch2(long long int a[],long long int x,long long start,long long end)
{
	int mid;
	while((start+1)<end)
	{
		mid=(start+end)/2;
		if(a[mid]>=x && a[mid-1]<x)
			return mid;
		else if(a[mid]<x)
			start=mid+1;
		else
			end=mid-1;
	}
	if(a[start]>=x)
	{
		if(start>0 && a[start-1]<x)
			return start;
		else if(start==0)
			return start;
	}
	else if(a[end]>=x && a[end-1]<x)
		return end;
	else
		return -1;
}
int main()
{
	long long int t,i,index1,ans,a[100005],b[100005],c[100005],index2,p,u;
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		scanf("%lld",&m);
		for(i=0;i<m;i++)
			scanf("%lld",&b[i]);
		scanf("%lld",&k);
		for(i=0;i<k;i++)
			scanf("%lld",&c[i]);
		for(i=0;i<m;i++)
		{
			index1=bsearch1(a,b[i],0,n-1);
			index2=bsearch2(c,b[i],0,k-1);
			if(index1==-1)
				u=0;
			else if(index1<=i)
				u=index1+1;
			else
				u=i+1;
			if(u<0)
				u=0;
			if(index2==-1)
				p=0;
			else
			{
				p=k-index2;
				if(p>(k-i))
					p=k-i;
			}
			if(p<0)
				p=0;
			ans+=u*p;
		//	printf("%lld %lld %lld\n",index1,index2,ans);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
