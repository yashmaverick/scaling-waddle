#include<stdio.h>
int arr[1000000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,j,k;
		long long int min=1000000007;
		scanf("%d%d",&n,&k);
		int i;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&arr[i]);
			if(i<=k)
			{
				if(min>arr[i])
				{
					min=arr[i];
				}
			}
		}
		if(n!=k)
			printf("%lld ",min);
		else
			printf("%lld",min);
		for(i=2;i<=n-k+1;i++)
		{
			if(min!=arr[i-1])
			{
				if(arr[i+k-1]<min)
				{
					min=arr[i+k-1];
				}
			}
			else
			{
				min=arr[i];
				for(j=i;j<=i+k-1;j++)
				{
					if(arr[j]<min)
						min=arr[j];
				}
			}
			if(i!=n-k+1)	
				printf("%lld ",min);
			else
				printf("%lld",min);
		}
		printf("\n");
	}
	return 0;
}
