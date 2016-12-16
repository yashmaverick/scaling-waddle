#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	int weight;
	struct node* next;
}node;
typedef struct heap
{
	int v;
	int w;
}heap;
node a[1000010];
heap minheap[1000010];
int d[1000010],visited[1000010],p[1000010];
void swap(heap* a,heap* b)
{
	heap temp=*a;
	*a=*b;
	*b=temp;
	
}
int smin=0;
void heapifymin(int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int min=i;
	if(l<smin&&minheap[l].w<minheap[i].w)
		min=l;
	if(r<smin&&minheap[r].w<minheap[min].w)
		min=r;
	if(min!=i)
	{
		int temp=p[minheap[i].v];
		p[minheap[i].v]=p[minheap[min].v];
		p[minheap[min].v]=temp;
		swap(&minheap[i],&minheap[min]);
		heapifymin(min);
	}
}
int delmin()
{
	if(smin<=0)
		return;
	if(smin==1)
	{
		smin--;
		return minheap[0].v;
	}
	int x=minheap[0].v;
	minheap[0].w=minheap[smin-1].w;
	p[minheap[0].v]=smin-1;
	p[minheap[smin-1].v]=0;
	minheap[0].v=minheap[smin-1].v;
	smin--;
	heapifymin(0);
	return x;
}
void mininsert(int k,int in)
{
	int i=smin;
	smin++;
	minheap[i].w=k;
	minheap[i].v=in;
	p[in]=i;
	while(i>0&&minheap[(i-1)/2].w>minheap[i].w)
	{
		int temp=(i-1)/2;
		swap(&minheap[i],&minheap[(i-1)/2]);
		p[in]=temp;
		i=(i-1)/2;
	}
}
void decrease(int i,int newval)
{
	minheap[i].w=newval;
	while(i>0&&minheap[(i-1)/2].w>minheap[i].w)
	{
		p[minheap[i].v]=(i-1)/2;
		p[minheap[(i-1)/2].v]=i;
		swap(&minheap[i],&minheap[(i-1)/2]);
		i=(i-1)/2;
	}
}
void dijkstra(int x,int y)
{
	node* temp=a[delmin()].next;
	while(smin>0)
	{
		node* temp=a[x].next;
		while(temp!=NULL)
		{
			if(visited[temp->val]==0)
			{
				if(d[temp->val]>d[x]+temp->weight)
				{
					d[temp->val]=d[x]+temp->weight;
					decrease(p[temp->val],d[temp->val]);
				}
			}
			temp=temp->next;
		}
		int xyz=delmin();
		visited[xyz]=1;
		x=xyz;
	}
}
void adj(int x,int y,int w)
{
	node* new1=(node*)malloc(sizeof(node));
	new1->val=y;
	new1->weight=w;
	new1->next=a[x].next;
	a[x].next=new1;
}

int main()
{
	int n,m,i,x,y,u,v,w;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		a[i].next=NULL;
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		adj(u,v,w);
	}

	scanf("%d%d",&x,&y);
	for(i=0;i<=n;i++)
		d[i]=1000000;
	d[x]=0;
	visited[x]=1;
	for(i=1;i<=n;i++)
		mininsert(d[i],i);
	dijkstra(x,y);
	if(d[y]==1000000)
		printf("NO\n");
	else
		printf("%d\n",d[y]);
	return 0;
}


