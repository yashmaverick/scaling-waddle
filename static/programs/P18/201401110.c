#include<stdio.h>
#include<stdlib.h>
typedef struct graph
{
  int v;
  struct graph *next;
}node;

typedef struct revgraph
{
  int v;
  struct revgraph *next;
}revnode;

node *arr[1001];
revnode *revarr[1001];
int visited[1001];

node *insert(int v,node *root,int i)
{
  if(v==0)
    return;
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
/*void print(int n)
{
  int i;
  for(i=1;i<=n;i++)
  {
    node *temp=arr[i];
    if(temp==NULL)
    {
      continue;
    }
    else
    {
      //printf(" i %d",i);
      while(temp!=NULL)
      {
     // printf("--%d--",temp->v);
      temp=temp->next;
      }
    }
   // printf("\n");
  }
}
*/   
revnode  *revinsert(int v,revnode *root,int i)
{
  if(v==0)
    return;
  revnode *temp=(revnode *)malloc(sizeof(revnode));
  revnode *tempnode;
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

void dfs(int vertex)
{
  visited[vertex]=1;
  int i;
 // printf("dfs called for %d ",vertex);
  revnode *temp=revarr[vertex];
  while(temp!=NULL)
  {
    if(visited[temp->v]==0)
    {
      dfs(temp->v);
    }
    temp=temp->next;
  }
}
int count;
void setstack(int v,int index,int vis[])
{
  vis[v]=1;
  if(v!=0)
    count++;
  node *temp=arr[v];
 // if(temp==NULL)
 //   return;
  while(temp!=NULL)
  {
//    printf("for %d entered\n",index);
    if(vis[temp->v]==0)
    {
      setstack(temp->v,index,vis);
    }
    temp=temp->next;
  }
//  printf("stack[%d]:%d\n",top,stack[top-1]);
}

void reverse(int n)
{
  int v,newv;
  for(v=1;v<=n;v++)
  {
    node *temp=arr[v];
    if(temp==NULL)
      continue;
    while(temp!=NULL)
    {
      newv=temp->v; //need to insert v into adj of newv
      //printf("New V: %d\n",newv);
      revarr[newv]=revinsert(v,revarr[newv],newv);
      temp=temp->next;
    }
  }
}

int scc(int n)
{
  int stack[1001]={0};
     int v;
  int i,top=0,k,counter;
  for(i=1;i<=n;i++)
    visited[i]=0;
  for(i=1;i<=n;i++)
  {
      int vis[1001]={0};
      counter=0;
      count=0;
      setstack(i,i,vis);
     /* for(k=1;k<=n;k++)
      {
          if(visited[k]==1)
            counter++;
          visited[k]=0;
      }*/
     //   printf("Compare Count %d Counter %d\n",count,counter);
      if(count==n)
      {
        v=i;
        break;
      }
    
  }
  reverse(n);
  for(i=1;i<=n;i++)
    visited[i]=0;
    if(visited[v]==0)
    {
      dfs(v);
    //  printf("\n");
    }
        
}

int main()
{
  int test,t,n,m,i,j,u;
  scanf("%d",&test);
  for(t=0;t<test;t++)
  {
    scanf("%d",&n);
    for(i=0;i<=n;i++)
      visited[i]=0;
 //   node *arr=malloc((n+1)*sizeof(node *));
    for(i=0;i<=n;i++)
    {
      arr[i]=NULL;
      revarr[i]=NULL;
    }
    for(i=1;i<=n;i++)
    {
      scanf("%d",&m);
      for(j=1;j<=m;j++)
      {
        scanf("%d",&u);
        if(u!=0)
          arr[u]=insert(i,arr[u],u);
      }
    }
//   print(n);
    scc(n);
    
    //for(i=0;i<=n;i++)
    //  printf(" %d : %d\n",i,visited[i]);
    int count=0; 
    for(i=1;i<=n;i++)
      if(visited[i]==1)
        count++;
    printf("%d\n",count);
  }
  return 0;
}

