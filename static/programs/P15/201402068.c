#include <stdio.h>
int main()
{
	int n,k,t;
	int arr[10005];
	int x1[10005];
	int x2[10005];
	int temp[10005];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int range=n-k+1;
		int x;
		int i;
		if(k==1)
		{
			for(i=0;i<n;i++)
				scanf("%d",&arr[i]);
			for(i=0;i<range;i++)
				if(i<range-1)
					printf("%d ",arr[i]);
				else
					printf("%d",arr[i]);
			printf("\n");
		}
		else if(n==k)
		{   int min;
			for(i=0;i<n;i++)
			{   scanf("%d",&arr[i]);
				if(i==0)
					min=arr[i];
				if(min>arr[i])
					min=arr[i];
			}
			printf("%d\n",min);
		}

		else
		{
			int index=0;
			x=1;
			for(i=0;i<n;i++)
			{
				scanf("%d",&arr[i]);
				if(x==1)
				{
					x1[i]=arr[i];
					temp[index++]=i;
				}
				else
					x1[i]=x1[i-1]<arr[i]?x1[i-1]:arr[i];
				if(x==k)
					x=0;
				x++;
			}
			index--;
			
			for(i=n;i>=1;i--)
			{
				if(i==n)
					x2[i-1]=arr[i-1];
				else if(i%k==0)
				{
					x2[i-1]=arr[i-1];
					index--;
				}
				else
					x2[i-1]=x2[i]<arr[i-1]?x2[i]:arr[i-1];
			}
/*				printf("array 1\n");
			for(i=0;i<n;i++)
			{
				printf("%d ",x1[i]);
			}
                printf("\n");
				printf("array 2\n");
			for(i=0;i<n;i++)
			{
				printf("%d ",x2[i]);

			}
			printf("\n");*/
			for(i=0;i<range;i++)
			{
				if(i<range-1)
					printf("%d ",x2[i]<x1[i+k-1]?x2[i]:x1[i+k-1]);
				else if(i==range-1)
					printf("%d",x2[i]<x1[i+k-1]?x2[i]:x1[i+k-1]);
			}
			printf("\n");
			
/*			for(i=0;i<range;i++)
			{
				if(i<range-1)
					printf("%d ",x1[i]<x2[i+k-1]?x1[i]:x2[i+k-1]);
				else if(i==range-1)
					printf("%d",x1[i]<x2[i+k-1]?x1[i]:x2[i+k-1]);
			}
			printf("\n");*/
		}
	}
	return 0;
}
