#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void insert(node *tree[],int u,int v)
{
    node *temp=malloc(sizeof(node));
    temp->data=v;
    temp->next=NULL;
    if(tree[u]==NULL)
    {
        tree[u]=malloc(sizeof(node));
        tree[u]=temp;
    }
    else
    {
        temp->next=tree[u]->next;
        tree[u]->next=temp;
    }
}

int q[1000001],front=1,rear=0;

int bfs(int s,int n,node *tree[])
{
    int vis[n+1],dis[n+1],i,max=0;
    for(i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=0;
        q[i]=0;
    }
    q[++rear]=s;
    vis[s]=1;
    dis[s]=1;
    while(front!=n)
    {
        node *temp=tree[q[front]];
        while(temp!=NULL)
        {
            if(vis[temp->data]==0)
            {
                q[++rear]=temp->data;
                vis[temp->data]=1;
                dis[temp->data]=dis[q[front]]+1;
            }
            if(dis[temp->data] > max)
                max=dis[temp->data];
            temp=temp->next;
        }
        front++;
    }
/*    for(i=1;i<=n;i++)
    {
        printf("dis:%d\n",dis[i]);
        printf("q:%d\n",q[i]);
        printf("vis:%d\n",vis[i]);
    }*/
    return max;
}


int main()
{
    int t;
    for(scanf("%d",&t);t--;)
    {
        int n,i,u,v,x,y;
        scanf("%d",&n);
        node *tree[n+1];
        for(i=1;i<=n;i++)
            tree[i]=NULL;
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            insert(tree,u,v);
            insert(tree,v,u);
        }
        x=bfs(1,n,tree);
        int s=q[rear];
        front=1,rear=0;
        y=bfs(s,n,tree);
        printf("%d\n",y);
        front=1,rear=0;
    }
    return 0;
}




