#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	struct node *next;
	int vertex;
}node;
node *G[1000005]={0};
int visited[1000005]={0},stack[1000005]={0},m,n,top=0;
void DFS(int i)
{
	node *p=G[i];
	visited[i]=1;
	while(p!=NULL)
	{
		if(!visited[p->vertex])DFS(p->vertex);
		p=p->next;
	}
	top++;
	stack[top]=i;
	return;
}
void insert(int vi,int vj)
{
	node*p,*q=(node*)malloc(sizeof(node));
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
void read_graph()
{
	int i,vi,vj;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&vi,&vj);
		insert(vi,vj);
	}
	return ;
}
int main()
{
	int x,y,i,j;
	scanf("%d%d",&n,&m);
	read_graph();
	for(i=n;i>=1;i--)
		if(!visited[i])DFS(i);
	for(j=top;j>=1;j--)
		printf("%d%c",stack[j],(j==1)?'\n':' ');
	return 0;
}
