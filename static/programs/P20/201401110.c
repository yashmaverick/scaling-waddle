#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
  int v;
  struct node* next;
}node;

node *arr[1000001];
int visited[1000001];
int maxnode;
node *insert(int v,node *root)
{
  node *temp=malloc(sizeof(node));
  node *tempnode;
  temp->v=v;
  if(root==NULL)
  {
    root=temp;
    root->next=NULL;
  }
  else
  {
    tempnode=root;
    root=temp;
    root->next=tempnode;
  }
  return root;
}
int max;
void dfs(int v,int path)
{
  visited[v]=1;
//  printf("node %d\n ",v);
  if(path>max)
  {
        maxnode=v;
        max=path;
  }
  node *temp=arr[v];
  while(temp!=NULL)
  {
    if(visited[temp->v]==0)
    {
      dfs(temp->v,path+1);
    }
    temp=temp->next;
  }
}
  
int main()
{
  int test,t,n,i,u,v,length;
  scanf("%d",&test);
  for(t=0;t<test;t++)
  {
    max=0;
    length=1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
      arr[i]=NULL;
      visited[i]=0;
    }

    for(i=1;i<n;i++)
    {
      scanf("%d%d",&u,&v);
      arr[u]=insert(v,arr[u]);
      arr[v]=insert(u,arr[v]);
    }
    dfs(u,length);
    length=1;
    for(i=1;i<=n;i++)
      visited[i]=0;
    dfs(maxnode,length);
    printf("%d\n",max);
    
  }
  return 0;
}








