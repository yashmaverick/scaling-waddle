#include<stdio.h>
long long int a[1000005],b[1000005];
void merge(long long int start,long long int mid,long long int end)
{
	long long int k=start;
	long long int i=start;
	long long int j=mid+1;
	long long int l;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
			b[k++]=a[i++];
		else
			b[k++]=a[j++];
	}
	if(i>mid)
	{
		while(j<=end)
			b[k++]=a[j++];
	}
	if(j>end)
	{
		while(i<=mid)
			b[k++]=a[i++];
	}
	for(l=start;l<=end;l++)
		a[l]=b[l];
	return ;
}
void mergesort(long long int start,long long int end)
{
	long long int mid;
	if(start>=end)
		return ;
	else
	{
		mid=(start+end)/2;
		mergesort(start,mid);
		mergesort(mid+1,end);
		merge(start,mid,end);
		return ;
	}
}
int main()
{
	long long int t,n,last,i,ans,plus;
	scanf("%lld",&t);
	while(t--)
	{
		ans=0;
		plus=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		mergesort(0,n-1);
		last=1000000000;
		for(i=0;i<n;i++)
		{
			if(a[i]!=last)
			{
				last=a[i];
				plus=0;
			}
			ans+=plus;
			plus++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
