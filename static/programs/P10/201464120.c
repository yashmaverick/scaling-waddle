#include<stdio.h>
int front=-1;
int rear=-1;
int i=0,size,psize=0;
//char a[size][110];
void enque(char a[size][110])
{
//	printf("%d %d\n",front,rear);
	//psize++;
	if(front==-1&&rear==-1)
	{
		front++;
		rear++;
		scanf("%s",a[rear]);
	}
	else if(front==rear+1)
	{
		//printf("overflow\n");
		if(front==size-1)
			front=0;
		else
			front++;
		rear++;
		scanf("%s",a[rear]);
		
	}
	else if(rear>=size)
	{
		rear=0;
		if(front==0)
		{
		scanf("%s",a[rear]);
			front++;
		}
		else
		scanf("%s",a[rear]);

	}
	else if(front==rear && front==0 && size==1)
	{
		front=rear=0;
		scanf("%s",a[rear]);
	}

	else
	{
		if(front==0 && rear==size-1)
			front++;
		rear=(rear+1)%size;
		scanf("%s",a[rear]);
	}
	//printf("%s %d %d\n",a[rear],front,rear);
}

void deque(char a[size][110])
{	
	//psize--;
	if(front==-1 && rear==-1)
	{
		//printf("underflow\n");
		return;
	}
	else if(front==rear && front!=-1)
	{
		front=rear=-1;
	}

	else if(front==size-1)               //front=rear condn left
	{

		front=0;
	}
	else
	{
		front++;
	}

}

void print(char a[size][110])
{
	int i=0;
	if(front==-1 || rear==-1)
	{
		return;
	}
	else if(front<=rear)
	{
		for(i=front;i<=rear;i++)
			printf("%s\n",a[i]);
	}
	else
	{
		for(i=front;i<size;i++)
			printf("%s\n",a[i]);
		for(i=0;i<=rear;i++)
			printf("%s\n",a[i]);
	}
//	printf("\n");
}
int main()
{
	int n,j;
	char ch='y';
	scanf("%d\n",&size);
	char a[size][110];
	//printf("-------MENU------");
	//printf("1.Enque\n2.Deque\n3.Print\n4.exit\n");
	while(ch!='Q')
	{	
		scanf("%c",&ch);
		if(ch=='A')
		{
			scanf("%d",&n);
			for(j=0;j<n;j++)
				enque(a);
			
		}
		else if(ch=='R')
		{
			scanf("%d",&n);
			for(j=0;j<n;j++)
				deque(a);
		}
		else if(ch=='L')
			print(a);

	}	


	return 0;
}

