#include<stdio.h>
#include<string.h>
char a[1000][1000];
char b[1000];
int rear=-1;
int front=0;
int cnt=0;
int flag=0;
int count1=0;
int count2=0;
int size=0;
void enqueue(int n)
{
	if(size!=n)
	{
	rear=(rear+1)%n;
		size=size+1;
	}
	else if(size==n)
	{
	rear=(rear+1)%n;
		front=(front+1)%n;
	}
	strcpy(a[rear],b);
}
void dequeue(int n,int r)
{
	if(size==r){
		front=0;
		rear=-1;
		size=0;
	}
	else{
		int i;
		for(i=0;i<r;i++){
		front=(front+1)%n;
		if(size>0){
			size--;
		}
		}
	}
}
void print(int n)
{  
	int i;
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
			printf("%s\n",a[i]);
	}
	else
	{
		if(rear!=-1){
			for(i=front;i<n;i++)
				printf("%s\n",a[i]);
			for(i=0;i<=rear;i++)
			{
				printf("%s\n",a[i]);
			}
		}
	}
}
int main()
{
	int n,i,m,r;
	scanf("%d",&n);
	char c;
	while(1)
	{
		scanf(" %c",&c);
		if(c=='A')
		{
			scanf("%d",&m);
			for(i=0;i<m;i++)
			{
				scanf("%s",b);
				enqueue(n);
			}
		}
		else if(c=='R')
		{
			scanf("%d",&r);
				dequeue(n,r);
		}
		else if(c=='L')
		{
			print(n);
		}
		else if(c=='Q')
		{
			break;
		}

	}
	return 0;
}
