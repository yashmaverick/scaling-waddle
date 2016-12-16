#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int rear,front;
char array[1000][1000];

void enqueue(int N);
void dequeue(int N);
void print(int N);

char element[1000];

int main()
{
	int N;
	//printf("Enter the size of the buffer:\n");
	scanf("%d",&N);
	int array[N];
	//	int front,rear;
	char choice[2];
	front=0;
	rear=0;
	//	int c;
	//int n,b;
	//int i,j;
	int flag=0;
	//printf("Enter the input choice:\n");

	while(flag==0)
	{
		scanf("%s",choice);
		if(choice[0]=='A')
		{
			//			printf("Enter the number of elements to be appended:\t");
			//			scanf("%d",&n);
			//for(i=0;i<n;i++)
			enqueue(N);
			//		break;
		}
		else if(choice[0]=='R')
		{
			//		printf("Enter number of elements to be removed:\t");
			//		scanf("%d",&b);
			//		for(j=0;j<b;j++)
			dequeue(N);
			//		continue;
		}
		else if(choice[0] =='L')
		{
			print(N);
			//		continue;
		}
		else if(choice[0]=='Q')
			flag=1;
	}
	return 0;
}

void enqueue(int N)
{
	//printf("Enter elements to be appended:\t");
	int n,i;
	//	int element;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",element);
		strcpy(array[(front+rear)%N],element);
		//array[(front+rear)%N]=element;
		if(rear!=N) rear++;
		else front=(front+1)%N;
		//printf("rear=%d\n",rear);
		
		//rear=(rear+1)%N;
		/*if(front == -1)
		{
			front = 0;
			rear =0;
		}*/
		//printf("%d %dEnqueue successful!\n",front,rear);
	}
}

void dequeue(int N)
{
	//printf("Enter the number of elements to be dequeued:\t");
	int j,b;
	scanf("%d",&b);
	if(/*(front == rear) &&*/ (rear == -1))
		printf("Circular buffer underflow.\n");
	else
	{
		front=(front+b)%N;
		rear-=b;
	}
		//printf("Dequeue Successful!\n");
}

void print(int N)
{
	//printf("%d%d",front,rear);
	int i;
	if(front==-1)
		printf("circular buffer is empty.\n");
	else
	{
		for(i=0;i<rear;i++)
			printf("%s\n",array[(i+front)%N]);
	}
	//printf("%d\n",array[rear]);
}
