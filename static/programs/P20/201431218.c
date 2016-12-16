#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *next;
	int vertex;
};
struct node* A[1000008];
int visited[1000008];
int max,maxvertex;
void dfs(int,int);
void insert(int,int);
int main()
{
	int i,n;
	int a,b,edge;
	int test;
	scanf("%d",&test);
	while(test)
	{
		scanf("%d",&n);
		for(i=0;i<=n;A[i++]=NULL);
		//for(i=0;i<n;i++)
		//{
		//scanf("%d",&edge);
		edge=n-1;
		for(i=0;i<edge;i++)
		{
			scanf("%d%d",&a,&b);
			insert(a,b);
			insert(b,a);
		}
		//}
		for(i=0;i<=n;i++)
			visited[i]=0;
		int count;
		count=0;
		max=0;
		maxvertex=1;
		dfs(1,count);
		//printf("%d %d\n",max,count);
		count=0;
		max=0;
		for(i=0;i<=n;i++)visited[i]=0;
		dfs(maxvertex,count);
		printf("%d\n",max);
		test--;
	}
	return 0;
}
void insert(int a,int b)
{
	struct node *m,*n;
	n=(struct node*)malloc(sizeof(struct node));
	n->vertex=b;
	n->next=NULL;
	if(A[a]==NULL)
		A[a]=n;
	else
	{
		m=A[a];
		while(m->next!=NULL)
			m=m->next;
		m->next=n;
	}
}
void dfs(int i,int count)
{
	struct node *m;
	m=A[i];
	//printf("%d\n",i);
	count++;
	if(max<=count)
	{
		max=count;
		maxvertex=i;
	}
	visited[i]=1;
	while(m!=NULL)
	{
		i=m->vertex;
		if(!visited[i])
			dfs(i,count);
		m=m->next;
	}
}
