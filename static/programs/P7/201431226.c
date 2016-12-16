#include<stdio.h>
void merge(long long int left[],long long int right[],long long int a[],long long int n)
{
	long long int mid=(n/2);
	long long int nl=(mid);
	long long int nr=(n-mid);
	long long int i=0,j=0,k=0;
	while(i<nl && j<nr)
	{
		if(left[i]<=right[j])
		{
			a[k]=left[i];
			i++;
		}
		else
		{
			a[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<nl)
	{
		a[k]=left[i];
		i++;
		k++;
	}
	while(j<nr)
	{
		a[k]=right[j];
		j++;
		k++;
	}
}
void part(long long int a[],long long int n)
{
	if(n<2)
		return;
	long long int mid=n/2;
	long long int left[mid];
	long long int right[n-mid];
	long long int i;
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	for(i=mid;i<n;i++)
	{
		right[i-mid]=a[i];
	}
	part(left,mid);
	part(right,(n-mid));
	merge(left,right,a,n);
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,a[10000001],i,j;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		part(a,n);
		long long int cnt=1;
		long long int sum=0;
		for(i=0;i<n;i++)
		{
			j=i+1;
			if(a[i]==a[j])
			{
				cnt++;
			}
			else if(a[i]!=a[j]&&cnt>1)
			{
				sum=sum+(cnt*(cnt-1)/2);
				cnt=1;
			}
		}
	printf("%lld\n",sum);
	}
	return 0;
}
