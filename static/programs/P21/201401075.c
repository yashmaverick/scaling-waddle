#include<stdio.h>
#include<stdlib.h>
typedef struct ll
{
	int val;
	int weight;
	struct ll *next;
}node;

node *ar[500005];
int state[500005];

void insert(int a,int b,int w)//insert to adjacency list
{
	if(ar[a]==NULL)
	{
		ar[a]=(node *)malloc(sizeof(node));
		ar[a]->val=b;
		ar[a]->weight=w;
		ar[a]->next=NULL;
	}
	else
	{
		node *temp=(node *)malloc(sizeof(node)),*t;
		temp->val=b;
		temp->weight=w;
		temp->next=ar[a];
		ar[a]=temp;
	}
}//correct

int pt[500005],d[500005];
int heap[500005][2];
int ptr;
void decpty(int val,int pos)//decrease priority
{
	heap[pos][0]=val;
	int x=pos;
	while(x>0)
	{
		if(heap[x][0]>=heap[x/2][0])
			break;
		else
		{
			pt[heap[x][1]]=x/2;
			pt[heap[x/2][1]]=x;
			int temp=heap[x][0],t2=heap[x][1];
			heap[x][0]=heap[x/2][0];
			heap[x][1]=heap[x/2][1];
			heap[x/2][0]=temp;
			heap[x/2][1]=t2;
			x=x/2;
		}
	}
}

void hinsert(int val,int val2)//insert to heap
{
	heap[ptr][0]=val;
	heap[ptr][1]=val2;
	pt[val2]=ptr;
	int x=ptr;
	ptr++;
	while(x>0)
	{
		if(heap[x][0]>=heap[x/2][0])
			break;
		else
		{
			pt[heap[x][1]]=x/2;
			pt[heap[x/2][1]]=x;
			int temp=heap[x][0],t2=heap[x][1];
			heap[x][0]=heap[x/2][0];
			heap[x][1]=heap[x/2][1];
			heap[x/2][0]=temp;
			heap[x/2][1]=t2;
			x=x/2;
		}
	}
}

int hdeletemin()//delete min elem from heap
{
	int ret;
	ret=heap[1][1];
	pt[heap[1][1]]=-1;
	pt[heap[ptr-1][1]]=1;
	heap[1][0]=heap[ptr-1][0];
	heap[1][1]=heap[ptr-1][1];
	ptr--;
	int x=1;
	while(x<ptr)
	{
		if(2*x+1>=ptr)
		{
			if(2*x<ptr)
			{
				if(heap[2*x][0]<heap[x][0])
				{
					pt[heap[x][1]]=2*x;
					pt[heap[2*x][1]]=x;
					int temp=heap[x][0];
					int temp2=heap[x][1];
					heap[x][0]=heap[2*x][0];
					heap[x][1]=heap[2*x][1];
					heap[2*x][0]=temp;
					heap[2*x][1]=temp2;
					x=2*x;
				}
				else
					break;
			}
			else
				break;
		}
		else if(heap[x][0]<=heap[2*x][0] && heap[x][0]<=heap[2*x+1][0])
			break;
		else
		{
			if(heap[2*x][0]<=heap[2*x+1][0])
			{
				pt[heap[x][1]]=2*x;
				pt[heap[2*x][1]]=x;
				int temp=heap[x][0];
				int temp2=heap[x][1];
				heap[x][0]=heap[2*x][0];
				heap[x][1]=heap[2*x][1];
				heap[2*x][0]=temp;
				heap[2*x][1]=temp2;
				x=2*x;
			}
			else
			{
				pt[heap[x][1]]=2*x+1;
				pt[heap[2*x+1][1]]=x;
				int temp=heap[x][0];
				int temp2=heap[x][1];
				heap[x][0]=heap[2*x+1][0];
				heap[x][1]=heap[2*x+1][1];
				heap[2*x+1][0]=temp;
				heap[2*x+1][1]=temp2;
				x=2*x+1;
			}
		}
	}
	return ret;
}

void dikstra(int u,int v)
{
	while(ptr!=1)
	{
		int v=hdeletemin();
		node *temp=ar[v];
		while(temp!=NULL)
		{
			int w=temp->val;
			if(d[v]+temp->weight < d[w])
			{
				d[w]=d[v]+temp->weight;
				decpty(d[w],pt[w]);
			}
			temp=temp->next;
		}
	}
}

int main()
{
	int n,m,u,v,w,i;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n;i++)
		state[i]=0;
	while(m--)
	{
		scanf("%d%d%d",&u,&v,&w);
		insert(u,v,w);
	}
	scanf("%d%d",&u,&v);
	ptr=1;
	hinsert(0,u);
	d[u]=0;
	for(i=1;i<=n;i++)
	{
		if(i!=u)
		{
			hinsert(1000000000,i);
			d[i]=1000000000;
		}
	}
	dikstra(u,v);
	if(d[v]==1000000000)
		printf("NO\n");
	else
		printf("%d\n",d[v]);
	return 0;
}
