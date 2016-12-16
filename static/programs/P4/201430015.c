#include<stdio.h>
#include<string.h>
void merge(long long int a[],long long int b[],long long int res[],int m,int n)
{
	int k,i,j;
	k=0;
	i=0;
	j=0;
	while((i<m)&&(j<n))
	{
		if(a[i]<b[j])
		{
			res[k++]=a[i++];
		}
		else
		{
			res[k++]=b[j++];
		}
	}
	if(i<m)
		{
			while(i<m)
			{
				res[k++]=a[i++];
			}
		}
	else
		{
			while(j<n)
			{
				res[k++]=b[j++];
			}
		}
}
	
void merge_sort(long long int a[],int n)
{
	if(n<=1)
	{
		return;
	}
	int mid,i,j;
	mid=n/2;
	long long int left[mid],right[n-mid];
	for(i=0;i<mid;i++)
	{
		left[i]=a[i];
	}
	j=0;
	for(i=mid;i<n;i++)
	{
		right[j]=a[i];
		j++;
	}
	merge_sort(left,mid);
	merge_sort(right,n-mid);
	merge(left,right,a,mid,n-mid);
}
int main()
{
	char str[100001];
	long long int x,val,sum,max;
	int flag[100001],test,i,n,countz,k,count;
	scanf("%d",&test);
	while(test)
	{
		test--;
		scanf("%s",str);
		n=strlen(str);
		long long int a[n];
		
		for(i=0;i<n;i++)
		{
			if(str[i]=='J')
			{
				a[i]=100002;
			}
			else if(str[i]=='R')
			{
				a[i]=100001;
			}
			else
			{
				a[i]=-200003;
			}
		}
		sum=0;
		countz=0;
		val=0;
		for(i=0;i<n;i++)
		{
			sum+=a[i];
			a[i]=sum;
			if(a[i]==0)
			{
				countz++;
			}
		}
		merge_sort(a,n);
		count=0;
		k=0;
		for(i=0;i<n;)
		{
			x=a[i];
			while((a[i]==x)&&(i<n))
			{
				count++;
				i++;
			}
			flag[k]=count;
			k++;
			count=0;
		}
		count=0;
		for(i=0;i<k;i++)
		{
			count+=(flag[i]*(flag[i]-1))/2;
		}
		count+=countz;
		printf("%d\n",count);
	}
	return 0;
}
