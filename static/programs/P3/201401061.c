#include<stdio.h>
int main()
{
	long long int arr[100000],min,maxdiff;
	int t,i,j=0,n,a,b;
	scanf("%d",&t);
	while(j<t)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		maxdiff=arr[1]-arr[0];
		min=arr[0];
		for(i=0;i<n;i++)
		{
			if(arr[i]-min>maxdiff)
				maxdiff=arr[i]-min;
			if(arr[i]<min)
				min=arr[i];
		}
			printf("%lld\n",maxdiff);
		j++;
	}
		return 0;
}
