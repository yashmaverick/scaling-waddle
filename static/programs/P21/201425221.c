#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    long long int dis;
    struct node *next;
}node;
long long int vis[1000001],dist[1000001],size,mdis;
node * heap[1000001];
void swap(node **heap,int i)
{
    node * t=heap[i];
    heap[i]=heap[i/2];
    heap[i/2]=t;
}
void insert(int x,int d)
{
    heap[++size]=malloc(sizeof(node));
    heap[size]->val=x;
    heap[size]->dis=d;
    int i=size;
    while(heap[i]->dis<heap[i/2]->dis && i>1)
    {
	swap(heap,i);
	i/=2;
    }
}
void deletemin()
{
    if(size==0)
    {
	return;
    }
    heap[1]=heap[size];
    size--;
    int i=1;
    int mc;
    while((i*2)+1<=size||i*2<=size)
    {
	if(i*2!=size && heap[i*2]->dis>heap[(i*2)+1]->dis)
	    mc=(i*2)+1;
	else
	    mc=i*2;
	if(heap[mc]->dis>heap[i]->dis)
	    break;
	else
	    swap(heap,mc);
	i=mc;
    }
}
int main()
{
    int m,n,i,u,v,w,s,t;
    node *graph[100001];
    node *temp,*temp2;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
	dist[i]=1000000000000;
	vis[i]=0;
	graph[i]=NULL;
    }
    for(i=0;i<m;i++)
    {
	scanf("%d%d%d",&u,&v,&w);
	temp=malloc(sizeof(node));
	temp->val=v;
	temp->dis=w;
	temp2=graph[u];
	graph[u]=temp;
	graph[u]->next=temp2;
    }
    scanf("%d%d",&s,&t);
    size=0;
    vis[s]=1;
    dist[s]=0;
    mdis=0;
    heap[++size]=malloc(sizeof(node));
    heap[size]->val=s;
    heap[size]->dis=0;
    while(heap[1]->val!=t && size!=0)
    {
	i=heap[1]->val;
	temp=graph[i];
	mdis=heap[1]->dis;
	while(temp!=NULL)
	{
	    if(vis[temp->val]==0 && mdis+(temp->dis)<dist[temp->val])
	    {
		insert(temp->val,(temp->dis) + mdis);	
	    }
	    temp=temp->next;
	}
	vis[heap[1]->val]=1;
	dist[i]=(heap[1]->dis);
	deletemin();
    }
    if(size==0)
	printf("NO\n");
    else
	printf("%lld\n",heap[1]->dis);
    return 0;
}
