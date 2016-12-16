#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 1000005

int n,e;
int e1,e2,w;

typedef struct hp
{
	int node;
	int dist;
}heap;

typedef struct gr
{
	int val;
	int weight;
	struct gr* next;
}graph;

graph *adjlist[SIZE];
int visited[SIZE];
int path[SIZE];
int in_heap[SIZE];

heap H[1000005];
int size;

void shuffle_up(int pos)
{
	if(pos<=1)
		return;
	if(H[pos].dist<H[pos/2].dist)
	{
		heap temp;
		temp=H[pos/2];
		H[pos/2]=H[pos];
		H[pos]=temp;
		int temp1;
		temp1=in_heap[H[pos].node];
		in_heap[H[pos].node]=in_heap[H[pos/2].node];
		in_heap[H[pos/2].node]=temp1;
		shuffle_up(pos/2);
	}
}

void shuffle_down(int pos)
{
	if(2*pos>size)
		return;
	int l,r;
	l=(2*pos<=size)?2*pos:0;
	r=(2*pos+1<=size)?2*pos+1:0;
	int num=pos;
	if(l!=0&&H[num].dist>H[l].dist)
		num=l;
	if(r!=0&&H[num].dist>H[r].dist)
		num=r;
	if(num!=pos)
    {
		heap temp;
		temp=H[num];
		H[num]=H[pos];
		H[pos]=temp;
		int temp1;
		temp1=in_heap[H[num].node];
		in_heap[H[num].node]=in_heap[H[pos].node];
		in_heap[H[pos].node]=temp1;
		shuffle_down(num);
    }
}

void print_heap()
{
	int i;
	int num,count;
	num=1;
	count=num;
	for(i=1;i<=size;i++)
    {
		printf("[%d:%d] ",H[i].node,H[i].dist);
		if(--count==0)
		{
			printf("\n");
			count=++num;
		}
    }
	printf("\n");
}

void print_graph()
{
	int i;
	for(i=1;i<=n;i++)
    {
		printf("%d: ",i);
		graph *temp=adjlist[i];
		while(temp!=NULL)
		{
			printf("%d:%d ",temp->val,temp->weight);
			temp=temp->next;
		}
		printf("\n");
    }
}

void insert_heap(int node,int dist)
{
	if(in_heap[node]!=-1)
	{	if(dist<H[in_heap[node]].dist)
		{
			H[in_heap[node]].dist=dist;
			H[in_heap[node]].node=node;
			shuffle_up(in_heap[node]);
		}
	}
	else
	{	
		H[++size].node=node;
		H[size].dist=dist;
		in_heap[node]=size;
		shuffle_up(size);
	}
}

int pop_min()
{
	int temp=H[1].node;
	in_heap[temp]=-1;
	if(visited[temp]==0||H[1].dist<path[temp])
		path[temp]=H[1].dist;
	H[1]=H[size--];
	shuffle_down(1);
	return temp;
}

void dijk()
{
	//print_heap();
	int node=pop_min();
	if(visited[node]!=0)
		return;
	else
		visited[node]=1;
	graph *temp=adjlist[node];
	while(temp!=NULL)
    {
		if(visited[temp->val]!=1)
			insert_heap(temp->val,temp->weight+path[node]);
		temp=temp->next;
    }
	if(size&&path[e2]==-1)
		dijk();
}

int main()
{
	int i;
	scanf("%d",&n);
	scanf("%d",&e);
	for(i=1;i<=n;i++)
		adjlist[i]=NULL;
	i=e;
	while(i--)
	{
		scanf("%d",&e1);
		scanf("%d",&e2);
		scanf("%d",&w);
		graph *temp;
		temp=(graph*)malloc(sizeof(graph));
		temp->val=e2;
		temp->weight=w;
		temp->next=adjlist[e1];
		adjlist[e1]=temp;
	}
	//print_graph();
	scanf("%d",&e1);
	scanf("%d",&e2);
	memset(visited,0,sizeof(int)*SIZE);
	memset(path,-1,sizeof(int)*SIZE);
	memset(in_heap,-1,sizeof(int)*SIZE);
	insert_heap(e1,0);
	dijk();
	/* for(i=1;i<=n;i++) */
	/* 	printf("%d ",path[i]); */
	/* printf("\n"); */
	if(path[e2]==-1)
		printf("NO\n");
	else
		printf("%d\n",path[e2]);
	/* for(i=1;i<=n;i++) */
	/*   printf("%d ",path[i]); */
	/* printf("\n"); */
	return 0;
}
