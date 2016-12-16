#include<stdio.h>
long long int a[1005],n,k,b[1005];
int binary(int x,int start,int end)
{
	int mid;
	if(end>=start)
	{	
		mid=(start+end)/2;
		if(x==a[mid])
		{
			return mid;
		}
		else if(x>a[mid])
		{
			return binary(x,mid+1,end);
		}
		else
		{
			return binary(x,start,mid-1);
		}
	}
	else
	{
		return -1;
	}
}
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
	int flag=0;
	long long int t,i,j,p;
	char str[100001];
	scanf("%lld",&t);
	while(t--)
	{
		flag=0;
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			scanf("%lld",&a[i]);
		}
		mergesort(0,n-1);
		for(i=0;i<n;i++)
		{
			for(j=n-1;j>i;j--)
			{
				p=k-a[i]-a[j];
				if(binary(p,i+1,j-1)!=-1)
				{
					flag=1;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
