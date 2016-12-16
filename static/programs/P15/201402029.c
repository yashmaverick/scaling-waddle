#include<stdio.h>
void mergeSort(long long int b[],long long int low,long long int mid,long long int high)
{
	long long int i,m,k,l,temp[high+1];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(b[l]<=b[m])
		{
			temp[i]=b[l];
			l++;
		}
		else
		{
			temp[i]=b[m];
			m++;
		}
		i++;
	}
	if(l>mid)
	{
		for(k=m;k<=high;k++)
		{
			temp[i]=b[k];
			i++;

		}
	}
	else
	{
		for(k=l;k<=mid;k++)
		{
			temp[i]=b[k];
			i++;
		}
	}
	for(k=low;k<=high;k++)
	{
		b[k]=temp[k];
	}
}
void partition(long long int b[],long long int low,long long int high)
{
	long long int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(b,low,mid);
		partition(b,mid+1,high);
		mergeSort(b,low,mid,high);
	}
}
int main()
{
	long long int x,k,i;
	scanf("%lld",&x);
	while(x--)
	{
		long long int n;
		scanf("%lld %lld",&n,&k);
		long long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(k>n)
		{
			continue;
		}
		if(k==1)
		{
			for(i=0;i<n-1;i++)
			{
				printf("%lld ",a[i]);
			}
			printf("%lld", a[n-1]);
			printf("\n");
			continue;
		}
		long long int count=0,b[k];
		while(count<n-k+1)
		{
			long long int y=0;
			for(i=count;i<k+count;i++)
			{
				b[y]=a[i];
				y++;
			}
			partition(b,0,y-1);
			if(count!=n-k)
				printf("%lld ",b[0]);
			else
				printf("%lld", b[0]);
			count++;
		} 
		printf("\n");
	}
	return 0;
}
