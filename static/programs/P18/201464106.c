#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void insert(node *list[],int u,int v)
{
    node *temp=malloc(sizeof(node));
    temp->data=v;
    temp->next=NULL;
    if(list[u]==NULL)
    {
        list[u]=malloc(sizeof(node));
        list[u]=temp;
    }
    else
    {
        temp->next=list[u]->next;
        list[u]->next=temp;
    }
}

int n,vis[1000000],c=0;

/*void dfs(node *list[],int v)
  {
  vis[v]=1;
  node *temp=list[v];
  while(temp!=NULL)
  {
  if(vis[temp->data]==0)
  {
  ret=(ret || dfs(list,temp->data));
  }
  temp=temp->next;
  }
  return ret;
  }*/
void bfs(int v,node *list[])
{
    int front=1,rear=0;
    int q[n+1];
    int i;
    for(i=0;i<=n;i++)
    {
        q[i]=0;
        vis[i]=0;
    }
    q[++rear]=v;
    vis[v]=1;
    while(front!=n)
    {
   /*     for(i=front;i<=rear;i++)
            printf("q_front:%d\n",q[front]);*/
        node *temp=list[q[front]];
        while(temp!=NULL && temp->data!=-1)
        {
            if(vis[temp->data]==0)
            {
                q[++rear]=temp->data;
                vis[temp->data]=1;
            }
            temp=temp->next;
        }
        front++;
    }
    /*void dfs(node *list[],int v)
      {
      if(v<=1000)
      {
      vis[v]=1;
      node *temp=list[v];
      while(temp!=null)
      {
      if(temp->data<=10000 && vis[temp->data]==0)
      dfs(list,temp->data);
      if(temp!=null)
      temp=temp->next;
      }
      }
      }*/
}



int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {
        int i,u,j;
        scanf("%d",&n);
        node *list1[n+1];
        node *list2[n+1];
        int m[100000];
        for(i=0;i<=n;i++)
        {
            list1[i]=NULL;
            list2[i]=NULL;
            vis[i]=0;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&m[i]);
            for(j=1;j<=m[i];j++)
            {
                scanf("%d",&u);
                insert(list1,i,u);          //list1=warriors who can defeat i-th warrior
                insert(list2,u,i);          //list2=warriors who can be defeated by i-th warrior
            }
        }
       /*  printf("i-th can lose from:\n");
           for(i=1;i<=n;i++)
           {
           printf("%d--->",i);
           node *temp=list1[i];
           while(temp!=NULL)
           {
           printf("%d ",temp->data);
           temp=temp->next;
           }
           printf("NULL\n");
           }
           printf("i-th can win from:\n");
           for(i=1;i<=n;i++)
           {
           printf("%d--->",i);
           node *temp=list2[i];
           while(temp!=NULL)
           {
           printf("%d ",temp->data);
           temp=temp->next;
           }
           printf("\n");
           }*/
        int k,x;
        for(i=1;i<=n;i++)
        {
            int c=0,front=1,rear=0;
            bfs(i,list2);
            for(k=1;k<=n;k++)
            {
                if(vis[k]==1)
                    c++;
            }
            if(c==n)
            {
                x=i;
                break;
            }
        }
        int total;
        bfs(x,list1);
        for(i=1;i<=n;i++)
        {
            if(vis[i]==1)
                total++;
        }
        printf("%d\n",total);
        total=c=0;
    }
    return 0;
}

