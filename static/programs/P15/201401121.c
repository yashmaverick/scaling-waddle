#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		int a[10004],b[10004],front=-1,rear=-1;
		int i=0;
		for(;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<k;i++)
		{
			while(rear>=front&&front!=-1&&a[i]<=a[b[rear]])
			{
				rear--;
			}
			if(rear==-1)
			{
				front=0;
			}
				rear++;	
			b[rear]=i;
		}
		for(i=k; i<n;i++)
		{
			printf("%d ",a[b[front]]);
			while(front<=rear&&b[front]<=i-k)
			{
				front++;
			}
			if(front>rear)
				front=rear=-1;

			while(rear>=front&&front!=-1&&a[i]<=a[b[rear]])
			{
				rear--;
			}
			if(rear==-1)
			{
				front=0;
			}
			rear++;
			b[rear]=i;
		}
		printf("%d\n",a[b[front]]);
	}
	return 0;
}

