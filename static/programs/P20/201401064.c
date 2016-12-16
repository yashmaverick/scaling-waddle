#include<stdio.h>
#include<stdlib.h>
void ins(int,int);
void DFS(int);
struct node{
	int data;
	struct node* next;
}node;
struct node *root[1000009];
int visited[1000007];
int count=0,max=-1,maxel;
/*void dfs1(int ff,int dd)
  {
  push(ff);
  int i;
  vis[ff]=1;
  if(ff==dd)
  return;
  node* temp=head[ff];
  while(temp!=NULL)
  {
  if(vis[temp->d]!=1)
  return dfs1(temp->d,dd);
  temp=temp->next;
  }
  i=pop(vis);
  }*/
int main()
{
	int n,i,test;
	int a,b;
	scanf("%d",&test);
	while(test--)
	{
		int n;
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{scanf("%d%d",&a,&b);
		ins(a,b);
		ins(b,a);}
	/*for(i=1;i<=nn;i++)
	  {
	  node *temp=head[i];
	  printf("%d : ",i);
	  while(temp!=NULL)
	  {
	  printf("%d ",temp->d);
	  temp=temp->next;
	  }
	  printf("\n");
	  }*/
	/*for(i=n;i>0;i--)
		vis[i]=0;
	for(i=n;i>0;i--)
	{
		if(vis[i]==0)
			dfs(i);
	}
	for(i=top-1;i>0;i--)
		printf("%d ",stack[i]);
	printf("%d\n",stack[0]);*/
	DFS(a);
	for(i=1;i<1000001;i++)
	  {
	  visited[i]=0;
	  }
	  count=0;
	  DFS(maxel);
	  printf("%d\n",max);
	  max=-1;
	  for(i=0;i<=n;i++)
	  {root[i]=NULL;
		visited[i]=0;}
	  count=0;
	}
	return 0;
}
void ins(int i,int j)
{
	struct node *p=(struct node *)malloc(sizeof(struct node));
	p->data=j;
	p->next=NULL;
	if(root[i]==NULL)
	{
		root[i]=p;
	}
	else
	{
		p->next=root[i];
		root[i]=p;
	}
}
void DFS(int e)
{
	count++;
	struct node* temp;
	temp=root[e];
	visited[e]=1;
	if(max<count)
	  {
	  max=count;
	  maxel=e;
	  }
	while(temp!=NULL)
	{
		if(visited[temp->data]==0)
		{
			DFS(temp->data);
			count--;
		}
		temp=temp->next;
	}
}
