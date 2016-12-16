#include<stdio.h>
#include<string.h>

char A[10001][102];
int front=-1,rear=-1;
int N;
int count;

void add(char s[])
{
	if(N==0)
	{
		return;
	}
	if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if((rear==(N-1))&&(front!=0))
	{
		rear=0;
	}
	else if((rear==(N-1))&&(front==0))
	{
		front++;
		rear=0;
	}
	else if(front==rear+1)
	{
		front++;
		rear++;
		if(front==N)
		{
			front=0;
		}
	}
	else
	{
		rear++;
	}
	count++;
	if(count>N)
	{
		count=N;
	}
	strcpy(A[rear],s);
}

void rem(int k)
{
	if(N==0)
	{
		return;
	}
	if((k==N)||(k==count))
	{
		front=-1;
		rear=-1;
		count=0;
		return;
	}
	count=count-k;
	front=(front+k)%N;
}

void list()
{
	int i;
	if(N==0)
	{
		return;
	}
	if(front==-1)
	{
		return;
	}
	if(front<=rear)
	{
		for(i=front;i<=rear;i++)
		{
			printf("%s\n",A[i]);
		}
	}
	else
	{
		for(i=front;i<N;i++)
		{
			printf("%s\n",A[i]);
		}
		for(i=0;i<=rear;i++)
		{
			printf("%s\n",A[i]);
		}
	}
}

int main()
{
	char str,abc[101],w;
	int n;
	count=0;
	scanf("%d",&N);
	w=getchar();
	front=-1;
	rear=-1;
	while(1)
	{
		scanf("%c",&str);
		if(str=='Q')
		{
			break;
		}
		else if(str=='L')
		{
			list();
		}
		else if(str=='A')
		{
			scanf("%d",&n);
			while(n!=0)
			{
				n--;
				scanf("%s",abc);
				add(abc);
			}
		}
		else if(str=='R')
		{

			scanf("%d",&n);
			rem(n);
		}
	}
	return 0;
}

