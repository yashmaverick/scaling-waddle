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
long long int sum=0;
int f=0,d[1000010],visited[1000010],p[1000010],par[1000010];
int smin=0;
void heapifymin(int i)
{
	int temp;
	int l=2*i+1;
	int r=2*i+2;
	int min=i;
	heap t;
	if(l<smin)
		if(minheap[l].w<minheap[i].w)
			min=l;
	if(r<smin)
		if(minheap[r].w<minheap[min].w)
			min=r;
	if(min!=i)
	{
		temp=p[minheap[i].v];
		p[minheap[i].v]=p[minheap[min].v];
		p[minheap[min].v]=temp;
		t=minheap[i];
		minheap[i]=minheap[min];
		minheap[min]=t;
		heapifymin(min);
	}
	return;
}
int delmin()
{
	int x=minheap[0].v;
	smin--;
	minheap[0].w=minheap[smin].w;
	p[minheap[0].v]=smin;
	p[minheap[smin].v]=0;
	minheap[0].v=minheap[smin].v;
	heapifymin(0);
	return x;
}
void mininsert(int k,int in)
{
	int i=smin;
	heap temp;
	smin++;
	minheap[i].w=k;
	minheap[i].v=in;
	p[in]=i;
	if(i>0)
	while(minheap[(i-1)/2].w>minheap[i].w)
	{
		temp=minheap[i];
		minheap[i]=minheap[(i-1)/2];
		minheap[(i-1)/2]=temp;
		p[in]=(i-1)/2;
		i=(i-1)/2;
		if(i<=0)
			break;
	}
	return;
}
void mst()
{
	int x,xyz;
	if(smin==1)
	{
		smin--;
		x=minheap[0].v;
	}
	else
		x=delmin();
	visited[x]=1;
	//	node* temp=a[x].next;
	while(smin>0)
	{
		node* temp=a[x].next;
		while(temp!=NULL)
		{
			int y=temp->val;
			if(visited[temp->val]==0)
			{
				if(d[temp->val]>temp->weight)
				{
					d[y]=temp->weight;
					int i=p[y];
					minheap[i].w=d[y];
					while(i>0&&minheap[(i-1)/2].w>minheap[i].w)
					{
						p[minheap[i].v]=(i-1)/2;
						p[minheap[(i-1)/2].v]=i;
						heap t=minheap[i];
						minheap[i]=minheap[(i-1)/2];
						minheap[(i-1)/2]=t;
						i=(i-1)/2;
					}
				}
			}
			temp=temp->next;
		}
		if(smin==1)
		{
			smin--;
			xyz=minheap[0].v;
		}
		else
			xyz=delmin();
		if(d[xyz]!=1000000)
			sum+=d[xyz];
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
	node* new2=(node*)malloc(sizeof(node));
	new2->val=x;
	new2->weight=w;
	new2->next=a[y].next;
	a[y].next=new2;
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

	//	scanf("%d%d",&x,&y);
	for(i=1;i<=n;i++)
	{
		//	par[i]=-1;
		d[i]=1000000;
	}
	d[1]=0;
	visited[1]=0;
	//p[0]=0;
	//par[0]=0;
	for(i=1;i<=n;i++)
		mininsert(d[i],i);
	mst();
	for(i=1;i<=n;i++)
		if(d[i]==1000000)
		{
			f=1;
			break;
		}
	if(f==1)
		printf("-1\n");
	else printf("%lld\n",sum);
	return 0;
}


