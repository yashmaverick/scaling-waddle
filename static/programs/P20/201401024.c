#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000005
typedef struct node
{
    struct node *next;
    int val;
}node;
node *arr[MAX];
node *insert(node *root,int a)
{
    node *temp=(node*)malloc(sizeof(node));
    temp->val=a;
    temp->next=root;
    return temp;
}
int visited[MAX],max=0,maxel=0;
void dfs(int a,int d)
{
    if(max<d)
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
            dfs(temp->val,d+1);
        }
        temp=temp->next;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {   
        int i,n;
        scanf("%d",&n);
        for(i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            arr[u]=insert(arr[u],v);
            arr[v]=insert(arr[v],u);
        }
        memset(visited,0,sizeof(visited));
        max=0;
        maxel=0;
        dfs(1,0);
        memset(visited,0,sizeof(visited));
        max=0;
        dfs(maxel,0);
        for(i=1;i<=n;i++)
            arr[i]=NULL;
        printf("%d\n",max+1);
    }
    return 0;
}
