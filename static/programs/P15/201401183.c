#include<stdio.h>
long long int a[100009],q[100009];
long long int front=-1,rear=-1;
void push(long long int val)
{
	if(rear==-1)
	{
		front=0;
		rear=0;
		q[rear]=val;
	}
	else
		q[++rear]=val;

}
void popf()
{
	if(front==-1)
		printf("-1\n");
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
		++front;
}
void popr()
{
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else --rear;
}

int main()
{
	long long int t,i,j,k,n;
	scanf("%lld",&t);
	while(t--)
	{
	front=-1,rear=-1;
	scanf("%lld",&n);
	scanf("%lld",&k);	
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0,j=0;j<n;j++)
	{
		if(j==0)
			push(a[j]);
		else if(a[j]<q[rear])
		{
			while(front!=-1&&rear!=-1&&a[j]<q[rear])
			{
				popr();
			}
			push(a[j]);
		}
		else if(a[j]>=q[rear])
		{
			push(a[j]);
		}
		if(j>=k-1)
		{
	//		printf("j is %lld \n",j);
			if(j==n-1)printf("%lld",q[front]);
			else printf("%lld ",q[front]);
			if(q[front]==a[i])
				popf();
			i++;
		}
	}
	printf("\n");
	}
	return 0;
}	

