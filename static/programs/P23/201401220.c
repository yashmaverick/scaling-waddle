#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int d;
	struct node* next;
}node;
node *head[1000001];
int vis[1000001];
void insert(int i,int j)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->d=j;
	temp->next=NULL;
	if(head[i]==NULL)
	{
		head[i]=temp;
		return;
	}
	else
	{
		temp->next=head[i];
		head[i]=temp;
		return;
	}
}
int stack[1000001];
int top=0;
void push(int i)
{	

	stack[top]=i;
	//printf("pushed:%d\n",stack[top]);
	top++;
}
int pop(int *vis)
{
	top--;
	int popped=stack[top];
	//	printf("popped:%d\n",popped);
	vis[stack[top]]=1;
	return popped;
}
int count=0,max=-99,f;
void dfs(int e)
{
	int k;
	node* temp;
	temp=head[e];
	vis[e]=1;
	/*if(max<count)
	  {
	  max=count;
	  f=i;
	  }*/
	while(temp!=NULL)
	{
		k=temp->d;
		if(!vis[k])
		{
			dfs(k);
		}
		temp=temp->next;
	}
	push(e);
}
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
	int n,m,i;
	int ij,ii;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		/*for(i=1;i<1000001;i++)
		  {
		  vis[i]=0;
		  }*/
		scanf("%d%d",&ii,&ij);
		insert(ii,ij);
	}
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
	for(i=n;i>0;i--)
		vis[i]=0;
	for(i=n;i>0;i--)
	{
		if(vis[i]==0)
			dfs(i);
	}
	for(i=top-1;i>0;i--)
		printf("%d ",stack[i]);
	printf("%d\n",stack[0]);
	/*for(i=1;i<1000001;i++)
	  {
	  vis[i]=0;
	  }
	  count=0;
	  dfs(f);
	  printf("%d\n",max);
	  max=-9;
	  for(i=0;i<=nn;i++)
	  head[i]=NULL;
	  count=0;*/
	//printf("%d\n",l);
	return 0;
}
