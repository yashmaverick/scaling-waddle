#include<stdio.h>
long long int a[1000000],c[1000000],n;
void merge(long long int low,long long int mid,long long int high)
{
	long long int l,i,j;
	for(i=low,j=mid+1,l=low;i<=mid&&j<=high;l++)
	{
		if(a[i]<a[j])
		{
			c[l]=a[i];
			i++;
		}
		else
		{
			c[l]=a[j];
			j++;
		}
	}
	if(l<=high)
	{
		while(i<=mid)
		{
			c[l]=a[i];
			l++;
			i++;
		}
		while(j<=high)
		{
			c[l]=a[j];
			l++;
			j++;
		}
	}
	for(i=low;i<=high;i++)
		a[i]=c[i];
}
void mergesort(long long int low,long long int high)
{
	long long int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(low,mid);
		mergesort(mid+1,high);
		merge(low,mid,high);
	}
	if(low==high)
		return;
}
int main()
{
	long long int count,i,t,j;
	scanf("%lld",&t);
	while(t--)
	{
		count=0;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		mergesort(0,n-1);
		for(i=1;i<n;i++)
		{
			j=1;
			if(a[i]==a[i-1])
			{
				while(a[i]==a[i-1])
				{
					j++;
					i++;
				}
			}
			count+=(j*(j-1))/2;
		}
		printf("%lld\n",count);
	}
	return 0;
}
