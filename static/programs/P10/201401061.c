#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
//#include<ctype.h>
int front=-1,rear=-1;
char a[10000][101];
void append(char [][101],int,int);
void rem(int,int);
void list(char [][101],int);
int main()
{
	int n,i,j,x;
	char c;
	scanf("%d",&n);
	getchar();
	c=getchar();
	while(c!='Q')
	{
		if(c=='A')
	        {
		        scanf("%d",&x);
			getchar();
			append(a,x,n);
		}
		else if(c=='R')
		{
			scanf("%d",&x);
		        rem(x,n);
		}
		else if(c=='L')
		        list(a,n);
                c=getchar();
	}	
	return 0;
}	

void append(char a[100000][101],int x,int n)
{
        int i;
	for(i=0;i<x;i++)
	{
		if(front==-1 && rear==-1)
	        {
		        front=0;
		        rear=0;
	        }
		else if(rear==n-1)
		{
			rear=0;
			if(front==0)
				front=1;
		//	{
		//		rear=front;
		//		front=rear+1;
		//	}
		}	
		else if(front==rear+1)
		{
			rear++;
			if(front!=n-1)
			front=rear+1;
			else
				front=0;
		}
		else 
			rear++;
		scanf("%s",a[rear]);
	}
/*                for(i=0;i<n;i++)
		printf("%s\n",a[i]);*/
}

void rem(int x,int n)
{
	while(x--)
	{
		if(front==-1 && rear==-1)
			break;
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
	        else if(front==n-1)
		{
			front=0;
		}
		else
			front++;
	}
}

void list(char a[10000][101],int n)
{
	int i,j;
	//printf("%d %d",front,rear);	
	if(front==-1&&rear==-1)
		return;
	if(front>rear)
	{
		for(i=front;i<n;i++)
		{
			printf("%s\n",a[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%s",a[i]);
			if(i!=rear)
				printf("\n");
		}
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%s",a[i]);
			if(i!=rear)
			printf("\n");
		}
	}
	printf("\n");
}
