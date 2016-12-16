#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
node *a[1010];
int nodevisit;
int realm;
int flag=0;
void insert(node *c,int num)
{
    node *p=malloc(sizeof(node));
    p->val=num;
    p->next=c->next;
    c->next=p;
}
int visited[1010];
void dfs(int src)
{
    visited[src]=1;
    nodevisit++;
    node *temp=a[src];
    temp=temp->next;
    while(temp!=NULL)
    {
        if(visited[temp->val]==0)
            dfs(temp->val);
        temp=temp->next;
    }
}
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n;
        scanf("%d",&n);
        int j;
        for(j=1;j<=n;j++)
        {
            a[j]=malloc(sizeof(node));
            a[j]->next=NULL;
        }
        for(j=1;j<=n;j++)
        {
            int m;
            scanf("%d",&m);
            int k;
            for(k=0;k<m;k++)
            {
                int n1;
                scanf("%d",&n1);
                insert(a[n1],j);
            }
        }
        int ans=0;
        for(j=1;j<=n;j++)
        {
                nodevisit=0;
                memset(visited,0,sizeof(visited));
                dfs(j);
                if(nodevisit==n)
                    ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
