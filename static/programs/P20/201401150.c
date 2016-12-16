#include <stdio.h>
#include <stdlib.h>
#define s(n) scanf("%d",&n)
#define Node struct Node
#define MAX 1000007
int visited[MAX],count,lv,max;

Node
{
	int val;
	Node *next;
};

Node *insert(Node *N,int v)
{
	Node *t=(Node*)malloc(sizeof(Node));
	t->val=v;
	t->next=N;
	N=t;
	return N;
}

void DV(Node *G[],int u)
{
	count++;
	if(count>max)
	{
		max=count;
		lv=u;
	}
	Node *T=G[u];
	visited[u]=1;
	while(T!=NULL)
	{
		if(visited[T->val]==0)
			DV(G,T->val);
		T=T->next;
	}
	count--;
	visited[u]=2;
}

void Ginit(Node *G[],int n)
{
	int i;
	for(i=0;i<=n;i++)
		G[i]=NULL;
}

void visinit()
{
	memset(visited,0,sizeof(visited)/sizeof(int));
}

int main()
{
	int t,i,n,k,u,v;
	s(t);
	Node *G[MAX];
	for(i=0;i<t;i++)
	{
		s(n);
		Ginit(G,n);
		visinit();
		count=0;max=-1;lv=0;
		for(k=1;k<n;k++)
		{
			s(u);s(v);
			G[u]=insert(G[u],v);
			G[v]=insert(G[v],u);
		}
		int start=(n/2)+1;
		DV(G,start);
		visinit();
		DV(G,lv);
		printf("%d\n",max);
	}

	return 0;
}