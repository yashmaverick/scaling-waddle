#include <stdio.h>
#include <stdlib.h>
long long int comb(long long int n)
{
	//printf("count is -->%lld\n",n);
	if(n<1)
		return 0;
	else
	{
		long long int l;
		if(n%2==0)
			l=(n/2)*(n-1);
		else
			l=((n-1)/2)*n;
		//printf("value is -->%lld\n",l);
		return l;
	}
}
int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,max,min,num;
		long long int pairs=0,count;
		scanf("%d",&n);
		int arr[n],flag=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),compare);
		count=1;
		i=0;
		while(i<n-1)
		{
			//count=1;
			//printf("num--->%d,count--->%d\n",arr[i],count[arr[i]]);
			if(arr[i]==arr[i+1])
				count++;
			else
			{
				if(count>1)
				{
					pairs+=comb(count);
					count=1;
				}
			}
			i++;
		}
		if(count>1)
			pairs+=comb(count);
		printf("%lld\n",pairs);
	}
	return 0;
}