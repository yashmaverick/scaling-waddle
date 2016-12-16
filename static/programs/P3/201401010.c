#include<stdio.h>

long long arr[100000];
int main()
{
	int t,i;
	long long n,j,min,max_diff;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld",&n);
		for(j=0;j<n;j++)
			scanf("%lld",&arr[j]);
		if(n==2)
		{	
			if(arr[1]>arr[0])
				printf("%lld\n",arr[1]-arr[0]);
			else
				printf("0\n");
		}
		else if(n==1)
		{
			printf("0\n");
		}
		else
		{
			min=0;
			max_diff=arr[1]-arr[0];
			for(j=1;j<n;j++)
			{
				if(arr[j]-arr[min]>max_diff)
					max_diff=arr[j]-arr[min];
				if(arr[j]<arr[min])
					min=j;
			}
			printf("%lld\n",max_diff);
		}
	}
	return 0;
}
