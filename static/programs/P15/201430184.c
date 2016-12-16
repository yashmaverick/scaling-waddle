#include<stdio.h>
int main()
{
	int test,count;
	scanf("%d",&test);
	for(count=0;count<test;count++)
	{
		int n,k,i,min,j,t;
		scanf("%d %d",&n,&k);
		int a[n];
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		min=a[i];
		for(i=1;i<=n-k+1;i++)
		{
			if(i==1||(a[i-1]==min&&a[i+k-1]>min))
			{
				min=a[i];
				for(j=i;j<=i+k-1;j++)
				{
					if(a[j]<=min)
					{
						min=a[j];
					}
				}
				if(i<n-k+1)
				{
					printf("%d ",min);
				}
				else if(i==n-k+1)
				{
					printf("%d\n",min);
				}
			}
			else if((a[i-1]==min&&a[i+k-1]<=min)||((a[i-1]!=min)&&a[i+k-1]<=min))
			{
				min=a[i+k-1];
				if(i<n-k+1)
				{
					printf("%d ",min);
				}
				else if(i==n-k+1)
				{
					printf("%d\n",min);
				}
			}
			else if(a[i-1]!=min && a[i+k-1]>min)
			{
				t=min;
				if(i<n-k+1)
				{
					printf("%d ",t);
				}
				else if(i==n-k+1)
				{
					printf("%d\n",t);
				}
                        }
		}
	}
	return 0;
}
