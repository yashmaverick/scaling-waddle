#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		int arr[n];
		for (i = 0; i < n; ++i)
		{
			scanf("%d",&arr[i]);
		}
		if(n==1)
		{
			printf("0\n");
		}
		else
		{
			int min=arr[0];
			int max_diff=arr[1]-arr[0];
			for(i=1;i<n;i++)
			{
				if(arr[i]-min>max_diff)
					max_diff=arr[i]-min;
				if(min>arr[i])
					min=arr[i];
			}
			if(max_diff>0)
				printf("%d\n",max_diff);
			if(max_diff<=0)
				printf("0\n");
		}
	}
	return 0;
}