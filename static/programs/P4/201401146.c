#include<stdio.h>
#include<string.h>
void merge_sort(long long int *arr,int n)
{
	if(n<=1)
		return;
	int i,j;
	long long int left[n/2],right[n-n/2];
	for(i=0;i<n/2;i++)
		left[i]=arr[i];
	for(j=0;j<n-n/2;j++)
		right[j]=arr[i++];
	merge_sort(left,n/2);
	merge_sort(right,n-n/2);
	merge(left,right,n/2,n-n/2,arr);
}
int merge(long long int arr1[],long long int arr2[],int a,int b,long long int c[])
{
	int i=0,j=0,k=0;
	while(i<a&&j<b)
	{
		if(arr1[i]<arr2[j])
			c[k++]=arr1[i++];
		else if(arr1[i]>arr2[j])
			c[k++]=arr2[j++];
		else
		{
			c[k++]=arr1[i++];
			c[k++]=arr2[j++];
		}
	}
	if(i==a)
	{
		while(j<b)
			c[k++]=arr2[j++];
	}
	else if(j==b)
	{
		while(i<a)
			c[k++]=arr1[i++];
	}
}
int main()
{
	int t,i,j,l,min;
	long long int s;
	scanf("%d",&t);
	char str[100000];
	while(t--)
	{
		long long int num[100001];
		num[0]=0;
		scanf("%s",str);
		i=strlen(str);
		for(j=0;j<i;j++)
		{
			if(str[j]=='J')
				num[j+1]=num[j]-100002;
			else if(str[j]=='M')
				num[j+1]=num[j]+1;
			else if(str[j]=='R')
				num[j+1]=num[j]+100001;
		}
		merge_sort(num,i+1);
		l=1;
		s=0;
		min=num[0];
		for(j=1;j<=i;j++)
		{
			if(min==num[j])
				l++;
			else
			{
				min=num[j];
				s=s+(l*(l-1))/2;
				l=1;
			}
		}
		s=s+(l*(l-1))/2;
		printf("%lld\n",s);
	}
	return 0;
}
