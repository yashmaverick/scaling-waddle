#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,a[100005];
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int ans=0;
		int max=a[n-1];
		for(i=n-1;i>=0;i--)
		{
			if(a[i]>max)
				max=a[i];
			if(max-a[i]>ans)
				ans=max-a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}


