#include<stdio.h>
int a[100000],dq[100000],ans[100000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k,i;
		scanf("%d %d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int front=-1,end=-1;
		for(i=0;i<n;i++)
		{
			if(i>k-1&&dq[front]==a[i-k])
			{
				if(front==end)
					front=end=-1;
				else
					front++;
			}
			while(end!=-1&&dq[end]>a[i])
			{
				if(end==front)
				{
					front=end=-1;
					break;
				}
				else
					end--;
			}
			if(end==-1)
			{
				front=end=0;
				dq[front]=a[i];
			}
			else
			{
				end++;
				dq[end]=a[i];
			}
			if(i==n-1)
			{
				printf("%d\n",dq[front]);
				continue;
			}
			if(i>=k-1)
				printf("%d ",dq[front]);
		}
	}
	return 0;
}

