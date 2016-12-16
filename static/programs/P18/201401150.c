#include <stdio.h>
#include <stdlib.h>
#define s(n) scanf("%d",&n)
#define MAX 100007
#define Node struct Node
int count,realmCount,visited[MAX];

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

void DFSinit()
{
	count=0;
	memset(visited,0,sizeof(visited)/sizeof(int));
}

void DFS(int a,Node *G[])
{
	Node *T=G[a];	
	visited[a]=1;
	//printf("%d->",a);
	while(T!=NULL)
	{

		if(visited[T->val]==0)
		{
			count++;
			DFS(T->val,G);			
		}
		T=T->next;
	}
}

void display(int n, Node *A[])
{
	int i;
	for(i=0;i<n;i++)
	{
		Node *t=A[i];
		printf("%d\t",i);
		while(t!=NULL)
		{
			printf("%d\t",t->val);
			t=t->next;
		}
		printf("\n");
	}
}

void Ginit(Node *G[],Node *L[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		G[i]=NULL;
		L[i]=NULL;
	}
}

int main()
{
	int t,i,j,k,l,N,M,a;
	s(t);
	for(i=0;i<t;i++)
	{
		s(N);Node *G[MAX],*lost[MAX];
		realmCount=0;
		for(j=1;j<=N;j++)
		{
			s(M);
			for(k=1;k<=M;k++)
			{
				s(a);
				G[a]=insert(G[a],j);
				lost[j]=insert(lost[j],a);
			}
		}
		int f=0;
		for(l=1;l<=N;l++)
		{
			DFSinit();
			DFS(l,G);
			//printf("Count=%d\n",count);
			if(count==N-1)
			{	f=1;break;}
				//realmCount++;
		}
		DFSinit();
		DFS(l,lost);
		if(f==1)
			printf("%d\n",count+1);
		else
			printf("0\n");
		Ginit(G,lost,N);
		//printf("%d\n",realmCount);
	}

	return 0;
}