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
int s=0,w=0,m;//s and w are the pointers of queue which locates till where the function has completed its process.
int c[1000000],visited[2000000];
void bfs(node* a[],int i)
{
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
		node* a[200000]={NULL};//array of node*s
		node* z[200000]={NULL};//array of node*s
		int n,i,j,r,p1,p2;
		scanf("%d",&n);//number of vertices and edges
		for(j=0;j<n;j++)
		{
			int k;
			scanf("%d",&k);
			int l;
			for(l=0;l<k;l++)
			{
				int v;
				scanf("%d",&v);	a[v]=insert(a[v],j+1);	z[j+1]=insert(z[j+1],v);
			}
		}
		int count=0;
		for(j=1;j<=n;j++)
		{
			memset(visited,-1,1000000);
			memset(c,0,1000000);
			s=w=0;
			bfs(a,j);
			if(s==n+1)
				break;
		}
		memset(visited,-1,1000000);
		memset(c,0,1000000);
		s=w=0;
		bfs(z,j);
		for(i=1;i<=n;i++)
		{
			if(visited[i]==1)
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}
