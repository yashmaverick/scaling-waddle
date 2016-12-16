#include<stdio.h>
#include<stdlib.h>
int sakshi=0,pratham;
typedef struct node
{
	struct node *next;
	int vertex;
}node;
node *G[1000005];
int visited[1000005];
int n;
void read_graph();
void insert(int,int);
void DFS(int,int);
int main()
{
	int i,j;
	int gandhar;
	scanf("%d",&gandhar);
	while(gandhar--)
	{
		for(i=0;i<n;visited[i++]=0);
		for(i=0;i<n;G[i++]=0);
		read_graph();
		pratham=0;
		sakshi=0;
		pratham=0;
		DFS(0,0);
		for(j=0;j<n;visited[j++]=0);
		DFS(pratham,0);
		printf("%d\n",sakshi);
	}
	return 0;
}
void DFS(int i,int mandhar)
{
	node *p;
	mandhar++;
	if(sakshi<=mandhar)
	{
		sakshi=mandhar;
		pratham=i;
	}
	p=G[i];
	visited[i]=1;
	while(p!=NULL)
	{
		i=p->vertex;
		if(!visited[i])DFS(i,mandhar);
		p=p->next;
	}
	return;
}
void read_graph()
{
	int i,vi,vj,no_of_edges;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		G[i]=NULL;
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&vi,&vj);
			vi--;
			vj--;
			insert(vi,vj);
			insert(vj,vi);
		}
	}
	return ;
}
void insert(int vi,int vj)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node));
	q->vertex=vj;
	q->next=NULL;
	if(G[vi]==NULL)G[vi]=q;
	else
	{
		p=G[vi];
		while(p->next!=NULL)p=p->next;
		p->next=q;
	}
	return ;
}


