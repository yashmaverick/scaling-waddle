#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int N;
int count=0;

typedef struct Queue
{
	int front;
	int last;
	//char *qu[1001];
	char qu[10005][101];
}Queue;

Queue queue;

void enqueue(char s1[101])
{	
	queue.last = (((queue.last))+1) %N ;
	//queue.qu[queue.last]=s1;
	strcpy(queue.qu[queue.last], s1);
	if(queue.last==queue.front && count!=0)
	{
		queue.front= ((queue.front)+1)%N;
	}
	//free(s1);
}

void dequeue()
{
	/*char *p;
	p=queue.qu[queue.front];
	free(p);*/
	queue.front = ((queue.front)+1) %N ;
}

void display()
{
	int i;
	int j;
	j=queue.front;
	for(i=0;i<count;i++)
	{
		printf("%s\n",queue.qu[j%N]);
		j++;
	}
}

int main()
{
	int number;
	scanf("%d",&N);
	//queue.qu=(char *)malloc(sizeof(char) * N);
	queue.front =0,queue.last=-1;
	char s,s1[101];
	while(1)
	{
		scanf("%c",&s);
		if(s=='A')

		{
			scanf("%d",&number);
			while(number--)
			{
			//	s1=(char *)malloc(sizeof(char) * 101);
				char s1[101];
				scanf("%s",s1);
			//	printf("%s-\n", s1);
				enqueue(s1);
				if(count<N)
					count++;
			//	free(s1);
			}
		}
		else if(s=='R')
		{
			scanf("%d",&number);
			while(number--)
			{
				dequeue();
				count--;
			}
		}
		else if(s=='L')
		{
			display();
		}
		else if(s=='Q')
			return 0;
	}
	return 0;
}

