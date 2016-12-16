#include<stdio.h>
#include<string.h>
#define MAX 100001
long long int temp[MAX],b[MAX];
void partition(long long int arr[],long long int low,long long int high);
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high);
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--)
	{
		long long int n,count=1,i,min,c,ans=0,temp,flag=1;
		char a[100001];
		scanf("%s",a);
		n=strlen(a);
		for(i=0;i<n;i++)
		{
				if(a[i]=='J')
					b[i]=1;
				else if(a[i]=='M')
					b[i]=1010;
				else if(a[i]=='R')
					b[i]=-1011;
		}
		for(i=1;i<n;i++) b[i]=b[i]+b[i-1];
		partition(b,0,n-1);
		count=1;
		ans=0;
		if(b[0]==0)
			ans++;
		for(i=1;i<n;i++)
		{
			if(b[i]==0)
				ans++;
			 if(b[i-1]==b[i])
				count++;
			else
			{
				ans=ans+(count*(count-1))/2;
				count=1;
			}
		}
		ans+=(count*(count-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}
void partition(long long int arr[],long long int low,long long int high)
{
	long long int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		partition(arr,low,mid);
		partition(arr,mid+1,high);
		mergeSort(arr,low,mid,high);
	}
	return ;
}
void mergeSort(long long int arr[],long long int low,long long int mid,long long int high)
{
	long long int i,m,k,l;
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{
		if(arr[l]<=arr[m])
		{
			temp[i]=arr[l];
			l++;
		}
		else
		{
			temp[i]=arr[m];
			m++;
		}
		i++;
	}
		for(k=m;k<=high;k++)
		{
			temp[i]=arr[k];
			i++;
		}
		for(k=l;k<=mid;k++)
		{
			temp[i]=arr[k];
			i++;
		}
	for(k=low;k<=high;k++)
	{
		arr[k]=temp[k];
	}
	return;
}
