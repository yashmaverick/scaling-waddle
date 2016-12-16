#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
    int v;
    struct graph *next;
}node;

int n,m;
node *arr[100001];
int visited[100001];
int vorder[200001];
int top;

node *insert(int v,node *root)
{
  node *temp=(node *)malloc(sizeof(node));
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
/*void print()
{
  int i;
  for(i=1;i<=n;i++)
  {
    node *temp=arr[i];
    if(temp==NULL)
    {
      printf("gere!\n");
      continue;
    }
    else
    {
      printf(" i %d",i);
      while(temp!=NULL)
      {
        printf("--%d--",temp->v);
        temp=temp->next;
      }
      printf("\n");
    }
  }
}
*/

void dfs(int vertex,int stack[])
{
  visited[vertex]=1;
//  printf("%d ",vertex);
  int i;
  node *temp=arr[vertex];
  while(temp!=NULL)
  {
   if(visited[temp->v]==0)
   {
     dfs(temp->v,stack);
   }
  temp=temp->next;
  }
  stack[top]=vertex;
  top++;
}

void sort()
{
  int i;
  int stack[100001]={0};
  for(i=1;i<=n;i++)
    visited[i]=0;
  for(i=n;i>=1;i--)
  {
    if(visited[i]==0)
    {
      dfs(i,stack);
     // printf("\n");
    }
  }
  top--;
  while(top>0)
  {
    printf("%d ",stack[top]);
    top--;
  }
  printf("%d\n",stack[top]);
}

int main()
{
  int u,v,i,index=1;
  scanf("%d",&n);
  scanf("%d",&m);
  for(i=1;i<=m;i++)
  {
    scanf("%d%d",&u,&v);
    vorder[index]=v;
    index=index+1;
    vorder[index]=u;
    index=index+1;
    arr[u]=insert(v,arr[u]);
  }
  top=0;
//  print();
  sort();
  return 0;
}
