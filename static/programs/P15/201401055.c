#include<stdio.h>

int a[10005];
int n,k,front,rear,min;
void max()
{
	int i,j,minindex;
	for(i=0;i<n-k+1;i++)
	{
		rear=i+k-1;
		if(i==0)
		{
			front=i;
			minindex=i;
			min=a[i];
			for(j=rear;j>=front;j--)
			{
//				printf("%d %d",front,rear");
				if(min>a[j])
				{
//					printf("%d",min);
					min=a[j];
//					printf("%d",minindex);
					minindex=j;
//					printf("minindex %d\n",minindex);
				}
//			printf("%d",rear);
			}
		}
		else
			if(i<=minindex)  //prev min lies in next subarray
			{
//				printf("\ncheck1");
				if(a[rear]<=min)
//				printf("%d %d",front,rear");
				{
//					printf("\ncheck2");
					minindex=rear;
					min=a[rear];
//					printf("min=%d %d",min,minindex);
				}
			}
			else
			{
				front=i; minindex=i;
				min=a[i];
				for(j=rear;j>=front;j--)
				{
					if(min>=a[j])
//				printf("%d %d",front,rear");
					{
						minindex=j;
//					printf("%d",minindex);
						min=a[j];

					}
				}
			}

	
		if(i==n-k)
			printf("%d",min);
		else
			printf("%d ",min);
	
	}
}
int main()
{
//	int n,k,
	int t;
	scanf("%d",&t);
	int j;
	for(j=0;j<t;j++)
	{
		scanf("%d %d",&n,&k);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
//			printf("%d",a[i]);
		}
		max();
		printf("\n");
	}
	return 0;
}


