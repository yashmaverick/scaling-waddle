#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
typedef struct edge edge;
struct edge{
	long long int weight;
	int par;
	int chi;
};
struct node{
	struct edge edger;
	struct node* next;
};
long long int dist[100100];
//int vis[500100];
edge heap[500100];
node* adj[100100];
void delete(int);
void add_heapify(edge);
void insert(int,int,long long int);
void construct(int);
int main()
{
	long long int weigh;
	int ver,ed,t,i,j,k,l,v1,v2,n,src,dest;
//	scanf("%d",&t);
		t=1;
	while(t--)
	{
		heap[0].par=0;
		scanf("%d%d",&n,&ed);
		for(i=0;i<=n;i++)
		{
			adj[i]=NULL;
			dist[i]=-1;
			//vis[i]=0;
		}
		for(i=0;i<ed;i++)
		{
			scanf("%d%d%Ld",&v1,&v2,&weigh);
			insert(v1,v2,weigh);
		}
		scanf("%d%d",&src,&dest);
		dist[src]=0;
		construct(src);
		edge top;
		while(1)
		{
			if((dist[dest]!=-1)||heap[0].par<=0)
			{
				break;
			}
			top=heap[1];
			heap[1]=heap[heap[0].par];
			(heap[0].par)--;
			delete(1);
			if(dist[top.chi]!=-1)
			{
				continue;
			}

			dist[top.chi]=top.weight;
			src=top.chi;
			construct(top.chi);
		}
		if(dist[dest]!=-1)
		{
			printf("%Ld\n",dist[dest]);
			//			printf("%Ld %Ld %Ld\n",dist[1],dist[2],dist[3]);
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
void insert(int v1,int v2,long long int w)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->edger.par=v1;
	tmp->edger.chi=v2;
	tmp->edger.weight=w;
	tmp->next=adj[v1];
	adj[v1]=tmp;
	return;
}
void construct(int i)
{
	node* temp;
	for(temp=adj[i];temp!=NULL;temp=temp->next)
	{
		if(dist[temp->edger.chi]==-1)
		{
			//			printf("AEFSFE\n");
			temp->edger.weight+=dist[i];
			add_heapify(temp->edger);
			//			printf("%Ld %Ld %Ld\n",heap[1].par,heap[1].chi,heap[1].weight);
		}
	}
}
void add_heapify(edge a)
{
	(heap[0].par)++;
	heap[heap[0].par]=a;
	int ind=heap[0].par;
	edge tmp;
	while(ind>1)
	{
		if(heap[ind].weight<heap[ind>>1].weight)
		{
			tmp=heap[ind>>1];
			heap[ind>>1]=heap[ind];
			heap[ind]=tmp;
			ind=ind>>1;
		}
		else
		{
			break;
		}
	}
}
void delete(int in)
{
	int la=in;
	edge tmp;
	if((in<<1)<=heap[0].par&&heap[in].weight>heap[in<<1].weight)
	{
		la=(in<<1);
	}
	if((in<<1)+1<=heap[0].par&&heap[la].weight>heap[(in<<1)+1].weight)
	{
		la=(in<<1)+1;
	}
	if(la!=in)
	{
		tmp=heap[in];
		heap[in]=heap[la];
		heap[la]=tmp;
		delete(la);
	}
}

