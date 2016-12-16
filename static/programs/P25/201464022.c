#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
	long long int val;
	long long int weight;
	struct node *next;
}node;
node heap[1000005];
long long int visitedcount=0,sum=0,count=0,*dist,*visited;
void insert(long long int a,long long int wt)
{
	node temp;
	count++;
	heap[count].val=a;
	heap[count].weight=wt;
	long long int i=count,flag=0;
	while(i>1)
	{
		if(heap[i].weight<heap[i/2].weight)
		{
			flag=1;
			temp=heap[i];
			heap[i]=heap[i/2];
			heap[i/2]=temp;
		}
		if(flag==0)
			break;
		flag=0;
		i=i/2;
	}
}
void delete()
{
	heap[1]=heap[count];
	count--;
	node temp;
	long long int flag=0;
	long long int i=1,min,minindex;
	while(i<=(count/2))
	{
		if(heap[2*i].weight<heap[(2*i)+1].weight)
			minindex=2*i;
		else minindex=(2*i)+1;
		if(heap[i].weight>heap[minindex].weight)
		{
			flag=1;
			temp=heap[i];
			heap[i]=heap[minindex];
			heap[minindex]=temp;
		}
		if(flag==0)
			break;
		flag=0;
		i=minindex;
	}
}
void create(long long int v1,long long int v2,long long int wt,node *head)
{
	node *p=malloc(sizeof(node));
	p->val=v2;
	p->weight=wt;
	p->next=NULL;
	node *q=malloc(sizeof(node));
	q->val=v1;
	q->weight=wt;
	q->next=NULL;
	node *temp=&head[v1];
	if(temp->next==NULL)
	{
		temp->next=p;
	}
	else
	{
		p->next=temp->next;
		temp->next=p;
	}
	temp=&head[v2];
	if(temp->next==NULL)
		temp->next=q;
	else
	{
		q->next=temp->next;
		temp->next=q;
	}
	

}
void prims(long long int v1,node *head,long long int vertices)
{
	sum=0;
	long long int temp,i;
	dist[v1]=0;
	insert(v1,dist[v1]);
	while(visitedcount!=vertices && count!=0)
	{
		temp=heap[1].val;
		delete();
		while(visited[temp]!=0)
		{
			temp=heap[1].val;
			delete();
		}
	//	sum+=dist[temp];
//		printf(":adding vertex=%lld\n",temp);
//		printf("adding to sum=%lld\n",dist[temp]);
		visited[temp]=1;
		visitedcount++;
		node *temp1=&head[temp];
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
			if(visited[temp1->val]==1)
				continue;
			if(dist[temp1->val]>temp1->weight)
			{
			//	visitedcount++;
				dist[temp1->val]=temp1->weight;
				insert(temp1->val,temp1->weight);
			}
		}
//		for(i=1;i<=count;i++)
//			printf("v=%lld w=%lld ",heap[i].val,heap[i].weight);
	}
}


int main()
{
	long long int vertices,edges,i,v1,v2,weight;
	node *head;
	scanf("%lld%lld",&vertices,&edges);
	dist=malloc(sizeof(long long int)*(vertices+1));
	head=malloc(sizeof(node)*(vertices+1));
	visited=malloc(sizeof(long long int)*(vertices+1));
	for(i=0;i<=vertices;i++)
		dist[i]=INT_MAX;
	for(i=0;i<=vertices;i++)
		visited[i]=0;
	for(i=0;i<edges;i++)
	{

		scanf("%lld%lld%lld",&v1,&v2,&weight);
		create(v1,v2,weight,head);
	}
/*	for(i=1;i<=vertices;i++)
	{
		node *temp=&head[i];
		while(temp->next!=NULL)
		{
			temp=temp->next;
			printf("%d %d ",temp->val,temp->weight);
		}
		printf("\n");
	}*/


	prims(v1,head,vertices);
//	printf("%lld\n",visitedcount);
	if(visitedcount!=vertices)
	{
		printf("-1\n");
		return 0;
	}
//	for(i=1;i<=vertices;i++)
		//printf("%lld ",visited[i]);
	for(i=1;i<=vertices;i++)
		sum+=dist[i];
	printf("%lld\n",sum);
	return 0;
}


