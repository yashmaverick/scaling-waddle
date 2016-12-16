#include<stdio.h>
long long int a[1000009];
void merge(long long int a[],long long int low,long long int mid,long long int high)
{
	long long int i=low,k=0,j=mid+1,t[1000009];
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
			t[k++]=a[i++];
		else if(a[j]<a[i])
			t[k++]=a[j++];
		else
		{
			t[k++]=a[i++];
			t[k++]=a[j++];
		}
	}
	while(i<=mid)
	{
		t[k++]=a[i++];
	}
	while(j<=high)
	{
		t[k++]=a[j++];
	}
	for(k=0,i=low;i<=high;i++,k++)
	{
		a[i]=t[k];
	}
}
void mergesort(long long int a[],long long int low,long long int high)
{
	if(low>high)
		return;

	long long int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
int main()
{
	long long int w;
	scanf("%d",&w);
	while(w--)
	{
		long long int n,i,k,c;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		mergesort(a,0,n-1);
		k=0;
		for(i=0;i<n-1;i++)
		{
			c=1;
			while(a[i]==a[i+1])
			{
				c++;
				i++;

			}
			k+=(c*(c-1))/2;
		}
		printf("%lld\n",k);
	}
	return 0;
}



