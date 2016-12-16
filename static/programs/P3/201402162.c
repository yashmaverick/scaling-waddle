#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,ans,max=0;
		scanf("%d",&n);
		int arr[n];
		int diff[n-1];
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		for(i=0;i<n-1;i++)
		{
			diff[i]=arr[i+1]-arr[i];
		}
		ans=0;
		for(i=0;i<n-1;i++)
		{
			if(ans+diff[i]>0)
			{
				if(ans+diff[i]>max)
				{
					max=ans+diff[i];
				}
				ans=ans+diff[i];
			}
			else
				ans=0;
		}
		printf("%d\n",max);
	}
	return 0;
}
