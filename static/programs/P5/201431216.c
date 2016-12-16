#include<stdio.h>

void swap(long long int *c,long long int *d)
{
	long long int temp;
	temp=*c;
	*c=*d;
	*d=temp;
}


long long int partition(long long int a[],long long int left,long long int right)
{
	long long int pivot=a[right];
	long long int pindex=left,j;
	for(j=left;j<right;j++)
	{
		if(a[j]<=pivot)
		{
			swap(&a[j],&a[pindex]);
			pindex++;
		}
	}
	swap(&a[pindex],&a[right]);
	return pindex;
}

void quick(long long int a[],long long int left,long long int right)
{
	if(left<right)
	{
		long long int index=partition(a,left,right);


		quick(a,left,index-1);
		quick(a,index+1,right);

	}
}
int main()
{
	long long int test,j,a[100010],i,n,k;
	char str[100010];
	scanf("%lld",&test);
	for(j=0;j<test;j++)
	{
		scanf("%lld%lld",&n,&k);
		for(i=0;i<n;i++)
		{
			scanf("%s",str);
			scanf("%lld",&a[i]);
		}
		quick(a,0,n-1);
		int flag=0;
		for(i=0;i<n;i++)
		{
			int low=i+1;
			int high=n-1;
			while(low<high)
			{
				if((a[low]+a[high]+a[i])==k)
				{
					flag=1;
					break;
				}
				if((a[low]+a[high]+a[i])<k)
				{
					low++;
				}
				if((a[low]+a[high]+a[i])>k)
				{
					high--;
				}
			}
			if(flag==1)
			{
				printf("YES\n");
				break;
			}
			

		}
		if(flag==0)
		{
			printf("NO\n");
		}

		
	}
	return 0;
}



















