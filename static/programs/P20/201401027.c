#include<stdio.h>
#include<stdlib.h>
#define Max 1000003
long long int visited[Max],distance[Max],max;
typedef struct queue
{
	long long int data;
	struct queue *next;
}queue;
queue *head,*tail;
typedef struct list
{
	long long int data;
	struct list *next;
}list;
list *arr[Max];
void push(long long int a)
{
	queue* node=(queue*)malloc(sizeof(queue));
	node->data=a;
	node->next=NULL;
	if(head==NULL)
		head=tail=node;
	else
	{
		tail->next=node;
		tail=tail->next;
	}
}
void pop()
{
	if(head==NULL)
		return;
	if(head==tail)
		head=tail=NULL;
	else
	{
		queue *p=head;
		head=head->next;
		free(p);
	}
}
void insert(long long int a,long long int b)
{
	list *node=(list*)malloc(sizeof(list));
	node->data=b;
	node->next=arr[a];
	arr[a]=node;
}
void bfs(long long int i)
{
	list *k;
	push(i);
	visited[i]=1;
	max=0;
	while(head!=NULL)
	{
		k=arr[head->data];
		while(k!=NULL)
		{
			if(!visited[k->data])
			{
				visited[k->data]=1;
				distance[k->data]=distance[head->data]+1;
				push(k->data);
				max=(distance[max]>distance[k->data])?max:k->data;
			}
			k=k->next;
		}
		pop();
	}
}
long long int main()
{
	long long int tc,i,v,e,a,b;
	scanf("%lld",&tc);
	while(tc--)
	{
		scanf("%lld",&v);
		e=v-1;
		for(i=0;i<=v;i++)
			visited[i]=distance[i]=0;
		for(i=0;i<e;i++)
		{
			scanf("%lld%lld",&a,&b);
			insert(a,b);
			insert(b,a);
		}
		bfs(1);
		for(i=0;i<=v;i++)
			distance[i]=visited[i]=0;
		bfs(max);
		printf("%lld\n",distance[max]+1);
		for(i=1;i<=v;i++)
			arr[i]=NULL;
	}
	return 0;
}
