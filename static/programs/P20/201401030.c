#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    struct node *next;
    int val;
}node;
node *arr[1000056];
node *insert(node *root,int a)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->val=a;
    temp->next=root;
    return temp;
}
int max=0,maxel=0,q[1000056],level[1000056];
void dfs(int a,int d,int visited[])
{
    visited[a]=1;
    if(max<d && visited[a]==1)
    {
        max=d;
        maxel=a;
    }
    node *temp= arr[a];
    while(temp!=NULL)
    {
        if(visited[temp->val]==0)
        {
            visited[temp->val]=1;
            int x = d+1;
            dfs(temp->val,x,visited);
        }
        temp=temp->next;
    }
}
void bfs(int a,int level[])
{
    int front=0,rear=0;
    q[rear]=a;
    rear++;
    level[a]=0;
    while(front!=rear)
    {
        int p=q[front];
        front++;
        node *temp=arr[p];
        while(temp!=NULL)
        {
            if(level[temp->val]==-2)
            {
                level[temp->val]=level[p]+1;
                if(max<level[temp->val])
                {
                    maxel=temp->val;
                    max=level[temp->val];
                }
                q[rear]=temp->val;
                rear++;
            }
            temp=temp->next;
        }
    }
}
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {  
        int visited[1000000],level[1000000];
        long long int i;
        long long int n;
        scanf("%lld",&n);
        for(i=1;i<n;i++)
        {
            int u;
            int v;
            scanf("%d%d",&u,&v);
            arr[u]=insert(arr[u],v);
            arr[v]=insert(arr[v],u);
        }
        for(i=1;i<=n;i++)
            level[i]=-2;
        max=0;
        maxel=max;
        bfs(1,level);
//        memset(visited,0,sizeof(visited));
//        for(i=1;i<=n;i++)
//          bfs(i,level);
        for(i=1;i<=n;i++)
            visited[i]=0;
        max=0;
        dfs(maxel,0,visited);
        for(i=1;i<=n;i++)
            arr[i]=NULL;
        printf("%d\n",max+1);
    }
    return 0;
}
