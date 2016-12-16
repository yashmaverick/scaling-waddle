#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node node;
typedef node *next;
struct node{
	int val;
	node* next;
};
node* insert(node *head,int data)//to insert a new element(imp. step-node* datatype)//O(1)
{
	node* temp=malloc(sizeof(node));
	temp->val=data; 	temp->next=head;
	return temp;
}
long long int s=0,w=0,m,max;//s and w are the pointers of queue which locates till where the function has completed its process.
int c[1000000],level[1000001],visited[1000001];
void bfs(node* a[],int i)
{
	if(level[i]>max)
		max=level[i];
	node *head=a[i];
	if(visited[i]==-1)
	{
		visited[i]=1;	c[s++]=i;
	}
	while(head!=NULL)
	{
		if(visited[head->val]==-1)
		{
			c[s++]=head->val;
			visited[head->val]=1;
			level[head->val]=level[i]+1;
		}
		head=head->next;
	}
	while(s!=w-1)
	{
		w++;
		bfs(a,c[w]);//recursive pattern with w as counter of functn. and s as the no. of nodes visited
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		memset(visited,-1,1000001);
		memset(c,0,1000001);
		node* a[1000001]={NULL};//array of node*s
		int n,i,j,k,r,p1,p2;
		s=w=0;
		scanf("%d",&n);//number of vertices and edges
		for(j=0;j<n-1;j++)
		{
			int u,v;
			scanf("%d %d",&u,&v);	a[u]=insert(a[u],v);	a[v]=insert(a[v],u);
		}
		max=0;
		bfs(a,1);
		k=c[n-1];
		memset(visited,-1,1000001);
		s=w=0;
		max=0;
		level[k]=0;
		bfs(a,k);
		printf("%lld\n",max+1);
	}
	return 0;
}
