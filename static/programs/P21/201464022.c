#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node
{
	long long int vertex;
	long long int weight;
	struct node *next;
}node;
node *a;
long long *visited,*dist,count=0;
node heap[1000005];
void insert(long long int a,long long int wt)
{
	node temp;
	count++;
	heap[count].vertex=a;
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
void create(long long v1,long long v2,long long wt,node *a)
{
	node *p=malloc(sizeof(node));
	node *q=malloc(sizeof(node));
	p->vertex=v2;
	q->vertex=v1;
	p->weight=wt;
	q->weight=wt;
	node *temp=&a[v1];
	if(temp->next==NULL)
		temp->next=p;
	else
	{
		p->next=temp->next;
		temp->next=p;
	}
/*	temp=&a[v2];
	if(temp->next==NULL)
		temp->next=q;
	else
	{
		q->next=temp->next;
		temp->next=q;
	}*/
}
void dijkstra(long long int s,long long int t,long long int n)
{
	long long int temp,i;
	dist[s]=0;
	insert(s,dist[s]);
	while(visited[t]!=1 && count!=0)
	{
		temp=heap[1].vertex;
//		printf("temp=%lld\n",temp);
		visited[temp]=1;
		delete(heap);
		node *temp1=&a[temp];
		while(temp1->next!=NULL)
		{
			temp1=temp1->next;
			if((long long int)dist[temp]+temp1->weight<dist[temp1->vertex])
			{
				dist[temp1->vertex]=(long long int)dist[temp]+temp1->weight;
				insert(temp1->vertex,dist[temp1->vertex]);
			}
		}
	}
}
int main()
{
	long long int n,m,v1,v2,i,j,weight,s,t;
	scanf("%lld%lld",&n,&m);
	visited=malloc(sizeof(long long int)*(n+1));
	dist=malloc(sizeof(long long int)*(n+1));
	a=malloc(sizeof(node)*(n+1));
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&v1,&v2,&weight);
		create(v1,v2,weight,a);
	}
	scanf("%lld%lld",&s,&t);
	for(i=0;i<=n;i++)
		dist[i]=INT_MAX;
	dijkstra(s,t,n);
//	for(i=1;i<=n;i++)
//		printf("%lld ",visited[i]); 
//	printf("viisted[v2]=%lld\n",visited[t]);
	if(dist[t]==INT_MAX)
		printf("NO\n");
	else
	printf("%lld\n",dist[t]);
	return 0;
}


	


