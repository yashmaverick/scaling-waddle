#include<stdio.h>
int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}
int main()
{
	long long int t;
	scanf("%lld",&t);
	while(t--)
	{
		long long int n,i,same,count=0,ans=0;
		scanf("%lld",&n);
		int arr[n];
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr, n, sizeof(int), cmpfunc);
		same=arr[0];
		for(i=0;i<n;i++)
		{
			if(same==arr[i])
			{
				count++;
			//	printf("no more sorrow");
			}
			else
			{
				same=arr[i];
				if(count>1)
				{
					ans+=((count*(count-1))/2);
				}
				count=1;
			}
		}
			if(count>1)
				ans+=((count*(count-1))/2);
		printf("%lld\n",ans);
	}
	return 0;
}	
