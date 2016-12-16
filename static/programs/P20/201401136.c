#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
node *a[1000010];
void insert(node *c,int num)
{
    node *temp;
    temp=malloc(sizeof(node));
    temp->val=num;
    temp->next=c->next;
    c->next=temp;
}
int visited[1000010]={0};
int maxn=0;
int maxd=0;
void dfs(int src,int count)
{
    visited[src]=1;
    if(count>=maxd)
    {
        maxd=count;
        maxn=src;
    }        
    node *temp=a[src];
    temp=temp->next;
    while(temp!=NULL)
    {
        if(visited[temp->val]!=1)
            dfs(temp->val,count+1);
        temp=temp->next;
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        maxn=maxd=0;
        memset(visited,0,sizeof(visited));
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            a[j]=NULL;
            a[j]=malloc(sizeof(node));
            a[j]->next=NULL;
        }
        for(j=0;j<n-1;j++)
        {
            int v1,v2;
            scanf("%d%d",&v1,&v2);
            insert(a[v1],v2);
            insert(a[v2],v1);
        }
        dfs(1,1);
        memset(visited,0,sizeof(visited));
        dfs(maxn,1);
        printf("%d\n",maxd);
    }
    return 0;
}
