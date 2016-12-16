#include<stdio.h>

int ind1[100009];
int ans=1000000,fcount=0;
int temp;

void ele(int arr[],int start,int end,int count)
{
	if(start>end)
		return;
	if(start==end)
	{	
	//	printf("##%d %d %d %d##\n",ans,fcount,arr[start],count);
		if(fcount<count)
		{
			temp=fcount;
			fcount=count;
			if(count==temp)
			{
				if(arr[start]<ans)
				{
					ans=arr[start];
				}
			}
			else
				ans=arr[start];
	//		printf("**%d %d**\n",ans,fcount);
		}
		return;
	}

	int x=ind1[end];
	ele(arr,start,x,count+1);
	ele(arr,x+1,end-1,count+1);
}

void small(int arr[],int n)
{
	int i,x;
	ind1[0]=-1;
	for(i=1;i<n;i++)
	{
		x=i-1;
		if(arr[i]>arr[x])
			ind1[i]=x;
		else
		{
			do
			{
				x=ind1[x];
				if(x==-1)
				{
					ind1[i]=-1;
					break;
				}
				if(arr[i]>arr[x])
				{
					ind1[i]=x;
					break;
				}
			}while(x!=-1);
		}
	}
//	for(i=0;i<n;i++)
//		printf("%d ",ind1[i]);
//	printf("****\n");

}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,x,depth=0;
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		small(arr,n);
		ele(arr,0,n-1,0);
		printf("%d %d\n",ans,fcount);
		ans=-1;fcount=0;
	}
	return 0;
}

