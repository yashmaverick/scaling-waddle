#include<stdio.h>
#include<stdlib.h>
long long int inf=1000000000000001;
int nheap,visited[100003],Index[100003];
typedef struct elem{
	int val;
	long long int dist;
}elem;

elem heap[100003];

void exchange(int x,int y)
{
	elem temp;
	temp=heap[x];
	heap[x]=heap[y];
	heap[y]=temp;
}

void sup(int p)
{
	int i;
	i=p;
	while(heap[i].dist<heap[i/2].dist)
	{
		if(i==1)
		{
			break;
		}
		exchange(i,i/2);
		Index[heap[i].val]=i;
		Index[heap[i/2].val]=i/2;
		i=i/2;
	}
}

void sdown(int p)
{
	int i;
	elem temp;
	i=p;
	if(2*i>nheap)
	{
		return;
	}
	else
	{
		while((heap[i].dist>heap[2*i].dist)||(heap[i].dist>heap[2*i+1].dist))
		{
			if(heap[2*i].dist<heap[2*i+1].dist)
			{
				temp=heap[2*i];
				heap[2*i]=heap[i];
				heap[i]=temp;
				Index[heap[i].val]=i;
				Index[heap[2*i].val]=2*i;
				i=2*i;
			}
			else
			{
				temp=heap[2*i+1];
				heap[2*i+1]=heap[i];
				heap[i]=temp;
				Index[heap[i].val]=i;
				Index[heap[2*i+1].val]=2*i+1;
				i=2*i+1;
			}
			if(2*i>nheap)
			{
				break;
			}
		}
	}
}

 

elem rem()
{
	elem x;
	x=heap[1];
	heap[1]=heap[nheap];
	nheap=nheap-1;
	visited[x.val]=1;
	sdown(1);
	return x;
}

void update(int i,long long int x)
{
	heap[i].dist=x;
	sup(i);
	sdown(i);
}

typedef struct node{
	int value;
	long long int weight;
	struct node *next;
}node;

node *head[100001];

void insert(int y,int x,long long int wt)
{
	node *p;
	p=(node *)(malloc(sizeof(node)));
	p->value=x;
	p->next=NULL;
	p->weight=wt;
	if(head[y]==NULL)
	{
		head[y]=p;
		return;
	}
	else
	{
		p->next=head[y];
		head[y]=p;
	}
}

void display(node *head)
{
	node *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->value);
		p=p->next;
	}
}

int main()
{
	int x,y,m,n,t;
	long long int wt,td;
	int i,j,u,v;
	elem U,V;
	node *temp;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %lld",&x,&y,&wt);
		insert(x,y,wt);
	}
	for(i=1;i<=n;i++)
	{
		insert(i,i,0);
	}
	scanf("%d %d",&u,&v);
	int k;
	k=1;
	for(i=2;i<=n;i++)
	{
		heap[i].dist=inf;
	}
	i=2;
	while(i<=n)
	{
		if(k!=u)
		{
			heap[i].val=k;
			Index[k]=i;
			i++;
		}
		k++;
	}
	heap[1].dist=0;
	heap[1].val=u;
	Index[u]=1;
	visited[u]=1;
/*		for(i=1;i<=n;i++)
		{
		printf("val:%d dist:%lld Index:%d\n",heap[i].val,heap[i].dist,Index[heap[i].val]);
		}*/
	U.val=u;
	U.dist=0;
	nheap=n;
	while(visited[v]!=1)
	{
		temp=head[U.val];
		t=U.val;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			x=temp->value;
			td=temp->weight+U.dist;
			if(visited[x]!=1)
			{
		//		printf("weight:%lld dist:%lld\n",temp->weight,U.dist); 
				if(td<heap[Index[x]].dist)
				{
					update(Index[x],td);
/*					printf("heap: ");
					for(i=1;i<=nheap;i++)
					{
						printf("%d:%lld, ",heap[i].val,heap[i].dist);
					}
					printf("\n");*/
				}
			}
		}
	/*	printf("heap: ");
		for(i=1;i<=nheap;i++)
		{
			printf("%d:%lld, ",heap[i].val,heap[i].dist);
		}
		printf("\n");*/
		U=rem();
//		printf("chosen:%d\n",U.val);
	}
	if(U.dist==inf)
	{
		printf("NO\n");
	}
	else
	{
	printf("%lld\n",U.dist);
	}
	return 0;
}
