#include<stdio.h>
#include<stdlib.h>
int front=-1;
int rear=0,count=0;
int a[10001]={-1};
void push(int value)
{
	front++;
	a[front]=value;
	return;
}

void pop_front()
{
	front--;
	return;
}

void pop_back()
{
	rear++;
	return;
}

void display(int arr[])
{
	int i;
	for(i=rear;i<=front;i++)
		printf("%d ",arr[a[i]]);
	printf("\n");
}

void printmin(int arr[],int n,int k)
{
	int i;
	for(i=0;i<k;i++)
	{

		//printf("front is %d and rear is %d and i is %d\n",front,rear,i);
		while(front!=-1&&rear<=front&&arr[i]<arr[a[front]])
			pop_front();
		push(i);
		//printf("Pushed %d\n",arr[i]);
		//display(arr);
	}
	for(;i<n;++i)
	{
		printf("%d ",arr[a[rear]]);
		count++;
		if(count==n-k+1)
			break;
		while(front!=-1&&rear<=front&&a[rear]<=i-k)
			pop_back();
		//display(arr);
		//printf("front is %d and rear is %d and i is %d\n",front,rear,i);
		while(front!=-1&&rear<=front&&arr[i]<arr[a[front]])
			pop_front();
		push(i);
		//display(arr);
	}
	if(count<n-k+1)
		printf("%d\n",arr[a[rear]]);
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d %d",&n,&k);
	    	int arr[n],l;
		for(l=0;l<n;l++)
			scanf("%d",&arr[l]);
		front=-1;
		rear=0;
		count=0;
		int j=0;
		for(j=0;j<10001;j++)
			a[j]=-1;
		printmin(arr,n,k);
	}
			    return 0;
}
