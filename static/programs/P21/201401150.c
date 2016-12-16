#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAX 500007
#define s(n) scanf("%d",&n)
#define hode struct hode
#define Node struct Node
int pQ_size,map[MAX],visited[MAX],dist[MAX];
hode
{
	int x,I;//x is the value on which the min or max condition is decided.
};

void insert_heap(hode pQ[],int x,int I)
{
	if(pQ_size==0)
	{
		pQ[1].x=x;
		pQ[1].I=I;
		map[I]=1;
		pQ_size++;
	}
	else
	{
		pQ_size++;
		int i;
		for(i=pQ_size;x<pQ[i/2].x;i/=2)
		{
			pQ[i].x=pQ[i/2].x;
			pQ[i].I=pQ[i/2].I;
			map[pQ[i].I]=i;
			//k=i;
			//map[pQ[i/2].I]
		}				
		//map[pq[i].I]=k;
		pQ[i].x=x;
		pQ[i].I=I;
		map[I]=i;
	}
}

void swap(hode A[],int i,int j)
{
	hode t=A[i];
	A[i]=A[j];
	A[j]=t;
	int k=map[A[i].I];
	map[A[i].I]=map[A[j].I];
	map[A[j].I]=k;
}


void changevalinpQ(hode pQ[],int x,int I)
{
	if(map[I]==0)// err
		pQ[I].x=x;
	else
		pQ[map[I]].x=x;
	int i=map[I];
	while(pQ[i].x<pQ[i/2].x)
	{
		swap(pQ,i,i/2);
		//map[i]=i/2;
		//map[i/2]=i;
		i/=2;
	}
}

void delete_min(hode pQ[])
{
	hode bot=pQ[pQ_size];
	map[pQ[1].I]=0;
	map[pQ[pQ_size].I]=1;
	pQ_size--;
	pQ[1]=bot;
	int i=1;
	while(pQ[i].x>pQ[2*i].x || pQ[i].x>pQ[2*i+1].x)
	{
		if(2*i>pQ_size)
			break;
		if(pQ[2*i].x<pQ[2*i+1].x)
		{
			swap(pQ,i,2*i);
			i=2*i;
		}
		else
		{		
			swap(pQ,i,2*i+1);
			i=2*i+1;
		}
	}
}

int peekMin_hode(hode pQ[])
{
	int i=pQ[1].I;
	//delete_min(pQ);
	return i;
}

void init()
{
	memset(map,0,sizeof(map)/sizeof(int));
	memset(dist,-1,sizeof(dist)/sizeof(int));
	pQ_size=0;
}

void display_all(hode P[])
{
	int i;
	for(i=1;i<=pQ_size;i++)
		printf("%d: Weight: %d ; Index mapping: %d\n",i,P[i].x,P[i].I);
}

Node
{
	int v,weight;
	Node *next;
};

Node *insert_edge(Node *N, int v,int w)
{
	Node *t=(Node*)malloc(sizeof(Node));
	t->weight=w;
	t->v=v;
	t->next=N;
	N=t;
	return N;
}

void heap_init(hode pQ[],int A,int V)
{
	int i;
	for(i=1;i<=V;i++)
	{
		pQ[i].x=INT_MAX;
		pQ[i].I=i;
		map[i]=i;
		pQ_size++;
	}
	changevalinpQ(pQ,0,A);
}

void ENdijkstra(Node* A[],hode P[],int V,int dest)
{
	int i;
	for(i=1;i<=V;i++)
	{
		int VuI=peekMin_hode(P);
		//printf("VuI=%d\n",VuI);
		Node* T=A[VuI];
		while(T!=NULL)
		{
			if(visited[T->v]==0 && P[map[VuI]].x!=INT_MAX && P[map[VuI]].x + T->weight < P[map[T->v]].x)
				changevalinpQ(P,P[map[VuI]].x + T->weight,T->v);
			
			T=T->next;
		}
		visited[VuI]=1;
		dist[VuI]=P[map[VuI]].x;
		//printf("dist:%d\n",dist[VuI]);
		delete_min(P);
		//printf("peekMin_hode=%d\n",peekMin_hode(P));
	}
	if(dist[dest]==INT_MAX || dist[dest]==-1)
		printf("NO\n");
	else
		printf("%d\n",dist[dest]);
}

int main()
{
	hode pQ[MAX];
	pQ[0].x=INT_MIN;
	int t,i,n,k,V,K;

	Node* G[MAX];
	init();
	s(V);s(K);
	int a,b,c,j;
	for(j=0;j<K;j++)
	{
		s(a);s(b);s(c);
		G[a]=insert_edge(G[a],b,c);
		//G[b]=insert_edge(G[b],a,c);
	}
	int A,B;	
	s(A);s(B);
	heap_init(pQ,A,V);
	//display_all(pQ);
	ENdijkstra(G,pQ,V,B);

	return 0;
}