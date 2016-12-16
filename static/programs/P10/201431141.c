#include<stdio.h>
int front=0,rear=0;
char A[10000][100];
int size=0;
void enqueue(int N)
{
	scanf("%s",A[rear]);
	if(front==rear && size!=0)
		front=(front+1)%N;
	rear=(rear+1)%N;
}
void dequeue(int N)
{
	int i;
	front=(front+1)%N;
}
void print(int N)
{
	int i=front%N;
	int j;
	if(i==rear && size!=0)
	{
		printf("%s\n",A[i]);
		i=i+1;
		while(i!=rear)
		{
			printf("%s\n",A[i]);
			i=(i+1)%N;
		}
	}
	else
	{
		while(i!=rear)
		{
			printf("%s\n",A[i]);
			i=(i+1)%N;
		}
	}
}
int main()
{
	int i,N,n;
	scanf("%d",&N);
	char c='a';
	while(c!='Q')
	{
		getchar();
		c=getchar();
		if(c=='A')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				enqueue(N);
				size=size+1;
				if(size>N)
					size=N;
			}
		}
		if(c=='R')
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				dequeue(N);
				size--;
			}
		}
		if(c=='L')
			print(N);
	}
	return 0;
}
