#include<stdio.h>
#include<stdlib.h>
#define Max 100003
long long int size,vis[Max],ind[Max],sdis[Max];
typedef struct heap
{
	long long int dis,ver;
}heap;
heap min[Max];
typedef struct graph
{
	long long int ver,dis;
	struct graph *next;
}graph;
graph *head[Max];
void swap(long long int p,long long int c)
{
	ind[min[p].ver]=c;
	ind[min[c].ver]=p;
	heap t=min[p];
	min[p]=min[c];
	min[c]=t;
}
void ins_graph(long long int a,long long int b,long long int d)
{
	graph *node=(graph*)malloc(sizeof(graph));
	node->ver=b;
	node->dis=d;
	node->next=head[a];
	head[a]=node;
}
void insmin(long long int c)
{
	long long int p=c/2;
	while(p>0 && min[p].dis>min[c].dis)
	{
		swap(p,c);
		c=p;
		p=c/2;
	}
}
void heapify(long long int p)
{
	long long int c=2*p;
	while(c<=size)
	{
		if(c+1<=size && min[c].dis>min[c+1].dis)
			c++;
		if(min[p].dis>min[c].dis)
			swap(p,c);
		else
			break;
		p=c;
		c=2*p;
	}
}
int main()
{
	long long int v,e,a,b,d,i,end,root,tail;
	scanf("%lld%lld",&v,&e);
	for(i=0;i<e;i++)
	{
		scanf("%lld%lld%lld",&a,&b,&d);
		ins_graph(a,b,d);
		//ins_graph(b,a,d);
	}
	scanf("%lld%lld",&root,&tail);
	min[1].ver=root;
	ind[root]=1;
	min[1].dis=0;
	for(i=1;i<=v;i++)
		if(i!=root)
			ind[i]=vis[i]=0;
	size=1;
	for(i=1;size!=0;i++)
	{
		long long int t=min[1].ver;
		long long int d=min[1].dis;
		vis[t]=1;
		graph *temp=head[t];
		swap(1,size--); //del
		heapify(1);     //del
		sdis[t]=d;
		if(t==tail)
			break;
		while(temp!=NULL)
		{
			if(!vis[temp->ver])
			{
				if(ind[temp->ver]==0)
				{
					size++;
					min[size].dis=d+temp->dis;
					min[size].ver=temp->ver;
					ind[temp->ver]=size;
					insmin(size);
				}
				else if(min[ind[temp->ver]].dis>d+temp->dis)
				{
					min[ind[temp->ver]].dis=d+temp->dis;
					insmin(ind[temp->ver]);
				}
			}
			temp=temp->next;
		}
	}
	/*if(size==0)
		sdis[i]=min[1].dis;*/
	if(ind[tail]==0)
		printf("NO\n");
	else
		printf("%lld\n",sdis[tail]);
	return 0;
}
