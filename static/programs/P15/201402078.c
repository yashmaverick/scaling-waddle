#include<stdio.h>
int main()
{
	int t,k,n,a[10009],i,j,l;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int ans,pt;
		scanf("%d%d",&n,&k);
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		for(j=0;j<n-k+1;j++)
		{
			if(j==0)
			{
				ans=a[0];
				pt=0;
				for(l=j;l<j+k;l++)
				{
					if(ans>a[l])
					{
						ans=a[l];
						pt=l;
					}
				}
			}
			if(pt==j-1)
			{
				if(a[pt]>a[j+k-1])
				{	
					ans=a[j+k-1];
					pt=j+k-1;
				}
				else
				{
					ans=a[j];
					pt=j;
					for(l=j;l<j+k;l++)
					{
						if(ans>a[l])
						{
							ans=a[l];
							pt=l;
						}
					}
				}

			}
			else
			{
				if (ans>a[j+k-1])
				{
					ans=a[j+k-1];
					pt=j+k-1;
				}
			}
			if(j!=n-k)
				printf("%d ",ans);
		}
		printf("%d",ans);
		printf("\n");
	}
	return 0;
}
