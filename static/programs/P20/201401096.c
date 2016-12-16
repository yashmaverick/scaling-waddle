#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 1000000
int root_max;

//int stack[size];
int front,rear;
int n;
int top;
int visited[size];
typedef struct node{
    int data;
    struct node *next;
}node;

node *adj[size];
node *dfs_root;

void insert(int src,int dest)
{
  node *p = (node*)malloc(sizeof(node));
  p->data=dest;
  p->next=NULL;
  if(adj[src]==NULL)
      adj[src]=p;
  else
    {
        p->next=adj[src];
        adj[src]=p;
    }
  return;
 }
void dfs(node *root,int level)
{
    if (!root)
        return;
    else
    {
        //printf("%d->",root->data);
        (level)++;
        if(level>root_max)
        {
            root_max=level;
            dfs_root=root;
        }
        visited[root->data]=1;
        node *ptr=adj[root->data];
        while(ptr)
        {
            if(visited[ptr->data]==0)
            {
                dfs(ptr,level);
            }
            ptr=ptr->next;

        }
    }
}

int main()
{
    int test,i,src,dest;
    scanf("%d",&test);
    
    while(test--)
    {
        memset(visited,0,size);
        for(i=0;i<size;++i)
            adj[i]=NULL;
        root_max=0;
        scanf("%d",&n);
        for(i=0;i<n-1;++i)
        {
            scanf("%d%d",&src,&dest);
            insert(src,dest);
            insert(dest,src);
        }
        
    node *root;
        for (i=0;i<n;++i)
            if(adj[i]!=NULL)
                {root=adj[i];break;}

    //root is the first element contained in
    dfs(root,0);
    //printf("from:%d\n",dfs_root->data);
        memset(visited,0,size);
        root_max=0;
        dfs(dfs_root,0);
   // printf("to:%d\n",dfs_root->data);
    printf("%d\n",root_max);
    root=NULL;

    }
    
    return 0;
}
