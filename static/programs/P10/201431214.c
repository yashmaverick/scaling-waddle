#include<stdio.h>
#include<stdlib.h>
int flag;
//int size;
typedef struct Queue
{
	char a[10005][105];
	int front;
	int rear;
	int old;
	//	int capacity;
}Queue;
Queue* queue;
void create()
{
	queue=(Queue*)malloc(sizeof(Queue));
	queue->front=0;
	queue->rear=0;
	queue->old=0;
	//	queue->capacity=(value);
}
void enqueue(char s[105],int value)
{
	int i,m;
	for(i=0;s[i]!='\0';i++)
	{
		queue->a[queue->rear][i]=s[i];
	}
	queue->rear=(queue->rear+1)%value;
	queue->old=queue->old+1;
	if(queue->old>value)
	{
		flag=1;
		queue->old=value;
		queue->front=(queue->front+1)%value;
	}
}
void dequeue(int value,int cnt)
{
	if(queue->old==0)
	{
		return ;
	}
	else
	{
		queue->front=(queue->front+1)%value;
                queue->old=queue->old-1;
	}
}

void print(int value)
{
	int j,k,i;
if(queue->old==0)
{
return ;
}
else
{
if(queue->rear<=queue->front)
{
	for(i=queue->front;i<value;i++)
	{
		for(j=0;queue->a[i][j]!='\0'  ;j++)
		{
			printf("%c",queue->a[i][j]);
		}
				
			printf("\n");
			
	}
	for(j=0;(j<queue->rear);j++)
	{
		for(k=0;queue->a[j][k]!='\0' ;k++)
		{
			printf("%c",queue->a[j][k]);
		}
			printf("\n");
	
	}
}
		else
		{
		for(i=queue->front;i<queue->rear;i++)
		{
		for(j=0;queue->a[i][j]!='\0' ;j++)
		{
		printf("%c",queue->a[i][j]);
}
printf("\n");
}
}
}	 
}
int main()
{
	int str,l,p,rem,size,cnt=0;
	char string[105],c;
	scanf("%d",&size);
	create();
if(size==0)
{
return 0;
}
else
{
	while(1)
	{
		scanf("%c",&c);
		if(c=='A')
		{
			scanf("%d",&str);
			for(l=0;l<str;l++)
			{
				scanf("%s",string);
				enqueue(string,size);
			}
			//	printf("\n");
		}
		else if(c=='R')
		{
			scanf("%d",&rem);
			for(p=0;p<rem;p++)
			{
				dequeue( size,cnt);
			}
			//	printf("\n");
		}
		else if(c=='L')
		{
			print( size);
		}
		else if(c=='Q')
		{
			return 0;
		}
	}
}
	return 0;
}
