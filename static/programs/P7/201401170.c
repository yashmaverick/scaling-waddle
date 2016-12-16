#include<stdio.h>
void merge(long long int a[],long long int min,long long int mid,long long int max)
{
	long long int temp[1000003]; 
	long long int i,j,k,m;
	j=min;
	m=mid+1;
	for(i=min;j<=mid && m<=max;i++)
	{
		if(a[j]<=a[m])
		{
			temp[i]=a[j];
			j++;
		} 
		else
		{
			temp[i]=a[m];
			m++;
		}
	}
	while(j<=mid)
		temp[i++]=a[j++];

	while(m<=max)	
		temp[i++]=a[m++];
	for(k=min;k<=max;k++)
		a[k]=temp[k];
}
void merge_sort(long long int a[],long long int low,long long int high)
{
	long long int mid;
	if(low <high)
	{
		mid=(low+high)/2;
		merge_sort(a,low,mid);
		merge_sort(a,mid+1,high);
		merge(a,low,mid,high);
	}

}


int main()
{
	long long int a[1000003];
	long long int i,n,s,count,m,ans;
	scanf("%lld",&m);
	while(m--)
	{
		scanf("%lld",&s);
		for(i=0;i<s;i++)
		{
			scanf("%lld",&a[i]);
		}
		merge_sort(a,0,s-1);
		ans=0;
		for(i=0;i<s;i++)
		{
			count=1;
			while(a[i]==a[i+1])
			{
				count++;
				i++;
			}
			ans+=(count*(count-1))/2;
		}
		printf("%lld\n",ans);
	}
	return 0;

}

