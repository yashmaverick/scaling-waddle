#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int front=-1,rear=-1;
char queue[10000][105];

void Append(char a[][105],int size,char data[105])
{
	if(front==-1 && rear==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==size-1)
	{
		rear=0;
		if(front==0)
			front=1;
	}
	else if(front==rear+1)
	{
		rear++;
		if(front!=size-1)
			front=rear+1;
		else
			front=0;
	}               
	else            
		rear++; 
	strcpy(a[rear],data);
}

void Remove(int size)
{
	if(front==-1 && rear==-1)
		return;
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==size-1)
	{
		front=0;
	}
	else
		front++;
}

void List(char queue[][105],int size)
{
	int j; 
	if(front==-1&&rear==-1)
		return;
	if(front>rear)
	{
		for(j=front;j<size;j++)
		{
			printf("%s\n",queue[j]);
		}
		for(j=0;j<=rear;j++)
			printf("%s\n",queue[j]);
	}
	else
	{
		for(j=front;j<=rear;j++)
			printf("%s\n",queue[j]);
	}
}

int main()
{
	int size,line;
	char c;
	char data[105];
	scanf("%d",&size);
	getchar();
	c=getchar();
	while(1)
	{
		if(c=='A')
		{
			scanf("%d",&line);
			while(line--)
			{
				scanf("%s",data);
				Append(queue,size,data);
			}
		}
		else if(c=='R')
		{
			scanf("%d",&line);
			while(line--)
				Remove(size);
		}
		else if(c=='L')
			List(queue,size);
		else if(c=='Q')
			break;
		c=getchar();
	}	
	return 0;
}

