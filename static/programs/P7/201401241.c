#include<stdio.h>
int a[1000000];
void mergeSort(int a[],int low,int mid,int high);
void partition(int a[],int low,int high);
int main()
{
	int t,k,i,l,n;
	int tt;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		partition(a,0,n-1);
		long long int sum=0,count=1,cnt=1;
		for(l=1;l<n;l++)
		{
			if(a[l]==a[l-1])
				cnt++;
		}
		if(cnt==n)
			printf("%lld\n",((cnt)*(cnt-1))/2);
		else
		{
			int temp=a[0];
			for(i=1;i<n;i++)
			{
				if(a[i]==temp)
				{
					++count;
					if(i==n-1)
						sum+=(count*(count-1))/2;
				}
				else
				{
					temp=a[i];
					sum+=(count*(count-1))/2;
					count=1;
				}
			}
			//sum+=(tt*(tt-1))/2;
			printf("%lld\n",sum);
		}
	}
	return 0;
}
void partition(int a[],int low,int high)
{
	int mid;
	if(low<high){
		mid=(low+high)/2;
		partition(a,low,mid);
		partition(a,mid+1,high);
		mergeSort(a,low,mid,high);
	}
}
void mergeSort(int a[],int low,int mid,int high)
{
	int i,m,k,l,temp[1000000];
	l=low;
	i=low;
	m=mid+1;
	while((l<=mid)&&(m<=high))
	{

		if(a[l]<=a[m])
		{
			temp[i]=a[l];
			l++;
		}
		else
		{
			temp[i]=a[m];
			m++;
		}
		i++;
	}

	if(l>mid){
		for(k=m;k<=high;k++)
		{
			temp[i]=a[k];
			i++;
		}
	}
	else{
		for(k=l;k<=mid;k++)
		{
			temp[i]=a[k];
			i++;
		}
	}

	for(k=low;k<=high;k++)
	{
		a[k]=temp[k];
	}
}
