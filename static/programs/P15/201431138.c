#include<stdio.h>
#include<math.h>
int main()
{
	int t,x;
	scanf("%d",&t);
	for(x=0;x<t;x++)
	{
		int n,k;
		scanf("%d %d",&n,&k);
		int a[n+1],i=0,b[n];
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		int j,min=a[1];
		/*for(i=1;i<n-k;i++)
		{
			min=a[i];
			for(j=i;j<i+k;j++)
			{
				if(min>a[j])
				{
					for(x=1;x<i;x++)
						b[i]=a[i];
				}
			}
		}*/
		for(i=1;i<=n-k+1;i++)
		{
			if(i==1)
			{
				for(j=i;j<=i+k-1;j++)
				{
					if(min>a[j])
						min=a[j];
				}
			}
			
			else if(i!=1)
			{
				if(a[i-1]==min)
				{
					min=a[i];
					for(j=i;j<i+k;j++)
					{
						if(min>a[j])
							min=a[j];
					}
				}
				else
				{
					if(a[i+k-1]<min)
						min=a[i+k-1];
				}
			}
			if(i==n-k+1)
				printf("%d",min);
			else
				printf("%d ",min);
		}
		printf("\n");
	}
	return 0;
}

