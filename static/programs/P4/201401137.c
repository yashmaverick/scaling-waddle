#include<stdio.h>
#include<string.h>

void cumulative_sum(int a[],int i)
{
	int j;
	for(j=i-1;j>=0;j--)
	{
		a[j]=a[j]+a[j+1];
	}
}

void merge(int left[],int right[],int c[],int m,int u)
{
	int i=0,j=0,k=0;
	while(i<m && j<u)
	{
		if(left[i]<=right[j])
		{
			c[k++]=left[i++];
		}	
		if(left[i]>=right[j])
		{
			c[k++]=right[j++];
		}
	}
	while(i<m)
	{
		c[k++]=left[i++];
	}
	while(j<u)
	{
		c[k++]=right[j++];
	}
}
int merge_sort(int a[],int n)
{

	int i,middle;
	int left[n],right[n];
	middle=n/2;
	if(n<=1)
	{
		return;
	}
	for(i=0;i<middle;i++)
	{
		left[i]=a[i];
//		printf("%d ",left[i]);
	}
	for(i=middle;i<n;i++)
	{
		right[i-n/2]=a[i];
//		printf("%d ",a[i]);
	}
	merge_sort(left,n/2);
	merge_sort(right,n-n/2);
	merge(left,right,a,n/2,n-n/2);
}
int main()
{
	int t,h;
	scanf("%d ",&t);
	for(h=0;h<t;h++)
	{
		char v[100001];
		int a[100000],i=0,j,k,result=0,count=0,flag;
		scanf("%s",v);
		while(v[i]!='\0')
		{
			if(v[i]=='J')
				a[i]=1;
			if(v[i]=='M')
				a[i]=100000;
			if(v[i]=='R')
				a[i]=-100001;
			i++;
		}
		a[i]=0;
		cumulative_sum(a,i);
		merge_sort(a,i+1);
//		for(j=0;j<=i;j++)
//			printf("%d\n",a[j]);
		k=a[0];
		for(j=0;j<=i;j++)
		{
			if(a[j]==k)
			{
				count++;
				flag=0;
			}
			else
			{
				if(count>1)
				{
					result=result+((count)*(count-1))/2;
					count=1;
					k=a[j];
					flag=1;
				}
				else
				{
					count=1;
					k=a[j];
				}
			}
//			printf("%d %d\n",count,result);
		}
		if(flag==0)
		{
			result=result+((count)*(count-1))/2;
		}
		printf("%d\n",result);
	}
	return 0;
}

