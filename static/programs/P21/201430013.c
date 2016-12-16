#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node node;
typedef node *next;
struct node
{
	int val;
	node* next;
	int weight;
};
/*Global Declarations*/
int a[1000000];
int link[1000000];
int ptr;
int distance[1000000];
int visited[1000000];
int dist[1000000];
/*Function Declarations*/
void func(node* head,int val1);
void insert_heap(node *head,int k);
void delete();
void refresh1(int p);
void refresh2(int p);
void bfs(node* n[],int i);
/*Insertion*/
node* insert(node *head,int data,int w)
{
	node *temp=malloc(sizeof(node));
	temp->val=data;         temp->next=head;        temp->weight=w;
	return temp;
}
void bfs(node* n[],int i)
{
	int j;
	int q=dist[i];
	node *head=n[i];
	while(head!=NULL)
	{
		if(dist[head->val]>q+head->weight)
		{
			if(visited[head->val]==-1)
			{
				visited[head->val]=1;
				a[ptr]=head->val;
				link[head->val]=ptr;
				ptr++;
			}
			dist[head->val]=q+head->weight;
			refresh1(ptr-1);
		}
		head=head->next;
	}
}
void dijkstra(node*n[],int root)
{
	link[root]=1;
	a[1]=root;
	dist[a[1]]=0;
	ptr++;
	while(ptr!=1)
	{
		int i;
		bfs(n,a[1]);
		distance[a[1]]=dist[a[1]];
		delete();
	}
}
int main()
{
	int i;
	ptr=1;
	distance[0]=-1;
	a[0]=0;
	node* n[1000001]={NULL};
	int ver,j,k,r;
	scanf("%d %d",&ver,&k);//number of vertices and edges
	for(i=1;i<=2*ver+5;i++)
	{
		dist[i]=1000000001;
		visited[i]=-1;
		a[i]=-1;
		distance[i]=0;
	}
	for(j=0;j<k;j++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
	     	n[u]=insert(n[u],v,w);
	}
	int dest;
	scanf("%d %d",&r,&dest);
	dijkstra(n,r);
	if(distance[dest]==0&&r!=dest)
		printf("NO\n");
	else
		printf("%d\n",distance[dest]);
	return 0;
}
void swap(int m,int n)
{
	if(m>ptr&&n>ptr)
		return ;
	int temp=a[m];
	a[m]=a[n];
	a[n]=temp;
}
int min(int m,int n)
{
	if(a[m]==-1)//have to correct
		return n;
	else if(a[n]==-1)
		return m;
	else
	{
		if(dist[a[m]]<dist[a[n]])
			return m;
		return n;
	}
}
void refresh1(int p)
{
	if(p==0)
		return;
	if(dist[a[p]]<dist[a[p/2]])
	{
		swap(p,p/2);
		refresh1(p/2);
	}
}
void refresh2(int p)
{
	if(p==0)
		return;
	if(a[2*p]!=-1)
	{
		int r=min(2*p,2*p+1);
		if(dist[a[r]]<dist[a[p]])
		{
			swap(r,p);
			refresh2(r);
		}
	}
}
void delete()
{
	int i;
	link[a[1]]=-1;
	a[1]=a[ptr-1];
	link[a[ptr-1]]=1;
	a[ptr-1]=-1;
	refresh2(1);
	ptr--;
}
