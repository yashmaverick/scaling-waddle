#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i,j,min,mini,a[100009];
		scanf("%d%d%d",&n,&k,&a[0]);
		min=a[0];
		mini=0;
		for(i=1;i<k;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<min)
			{
				min=a[i];
				mini=i;
			}
		}
		if(n==k)
			printf("%d\n",min);
		else
			printf("%d ",min);
		for(i=k;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<=min)
			{
				min=a[i];
				mini=i;
			}
			//	else if(a[i]>min && mini>i-k)
			//	{
			//		min=min;
			//	}
			else if(a[i]>min&&mini<=i-k)
			{
				min=a[i-k+1];
				for(j=i-k+2;j<=i;j++)
				{
					if(a[j]<=min)
					{
						min=a[j];
						mini=j;
					}
				}
			}
			if(i!=n-1)
				printf("%d ",min);
			else
				printf("%d\n",min);
		}
	}
	return 0;
}
