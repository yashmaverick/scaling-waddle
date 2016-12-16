#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10005

int start,end;
int sieve[SIZE];
int queue[SIZE];
int h_queue[SIZE];
int front,rear,ans;

int visited[SIZE];

typedef struct adj
{
	int val;
	struct adj* next;
}graph;

graph* adjlist[SIZE];

void print_sieve()
{
	int i;
	for(i=1;i<=10000;i++)
		printf("[%d:%d] ",i,sieve[i]);
}

void print_graph()
{
	int i;
	int count=0;
	for(i=1000;i<10000;i++)
    {
		printf("%d: ",i);
		graph *temp=adjlist[i];
		while(temp!=NULL)
		{
			printf("%d ",temp->val);
			temp=temp->next;
			count++;
		}
		printf("\n");
    }
	printf("%d\n",count);
}

void insert_gr(int num)
{
	int temp,prime;
	int i;
	graph* node;
	temp=num+(-1*num%10);
	for(i=0;i<10;i++)
	{
		prime=temp+i;
		if(sieve[prime]==0&&prime!=num&&prime<10000)
		{
			node=(graph*)malloc(sizeof(graph));
			node->val=prime;
			node->next=adjlist[num];
			adjlist[num]=node;
		}
	}
	temp=num+(-10*((num/10)%10));
	for(i=0;i<100;i+=10)
	{
		prime=temp+i;
		if(sieve[prime]==0&&prime!=num&&prime<10000)
		{
			node=(graph*)malloc(sizeof(graph));
			node->val=prime;
			node->next=adjlist[num];
			adjlist[num]=node;
		}
	}
	temp=num+(-100*((num/100)%10));
	for(i=0;i<1000;i+=100)
	{
		prime=temp+i;
		if(sieve[prime]==0&&prime!=num&&prime<10000)
		{
			node=(graph*)malloc(sizeof(graph));
			node->val=prime;
			node->next=adjlist[num];
			adjlist[num]=node;
		}
	}
	temp=num+(-1000*((num/1000)%10));
	for(i=1000;i<10000;i+=1000)
	{
		prime=temp+i;
		if(sieve[prime]==0&&prime!=num&&prime<10000)
		{
			node=(graph*)malloc(sizeof(graph));
			node->val=prime;
			node->next=adjlist[num];
			adjlist[num]=node;
		}
	}
}

void bfs()
{
	int node=queue[front];
	int height=h_queue[front++];
	if(node==end)
	{
		front=0;
		rear=-1;
		ans=height;
		return;
	}
	if(visited[node]==1)
		return;
	visited[node]=1;
	graph *temp;
	temp=adjlist[node];
	while(temp!=NULL)
	{
		if(visited[temp->val]==0)
		{
			queue[++rear]=temp->val;
			h_queue[rear]=height+1;
		}
		temp=temp->next;
	}
	while(front<=rear)
		bfs();
}

int main()
{
	int t,i,j;
	for(i=2;i<=10000;i++)
		if(sieve[i]==0)
		{
			for(j=2*i;j<=10000;j+=i)
				sieve[j]=1;
		}
	for(i=0;i<SIZE;i++)
		adjlist[i]=NULL;
	for(i=1000;i<=9999;i++)
		if(sieve[i]==0)
			insert_gr(i);
	//print_graph();
	scanf("%d",&t);
	while(t--)
	{
		ans=-1;
		scanf("%d",&start);
		scanf("%d",&end);
		if(start==end)
		{
			printf("0\n");
			continue;
		}
		memset(visited,0,sizeof(int)*10000);
		front=0;
		rear=0;
		queue[0]=start;
		h_queue[0]=0;
		bfs();
		printf("%d\n",ans);
	}
}
