#include<stdio.h>
#include<stdlib.h>
//int N=10;
int max=0,maxn=0;
typedef struct node
{
        int val;
        struct node *next;
}node;
node *l[1000010];
int vis[1000010],h[1000010];
node *createNode(int v)
{
        node *t=(node*)malloc(sizeof(node));
        t->val = v;
        t->next = NULL;
        return t;
}
void addEdge(int x, int y)
{
        node *a=createNode(x);
        node *b=createNode(y);
        a->next = l[y];
        l[y] = a;
        b->next = l[x];
        l[x] = b;
}
void dfs(int i,int ht)
{
        vis[i]=1;
        //printf("node-%d height-%d",i,ht);
        node *t=l[i];
        if(ht > max)
        {
                max=ht;
                maxn=i;
        }
        while(t!=NULL)
        {
                if(vis[t->val]==0)
                {
                        h[t->val]=ht;
                        dfs(t->val,ht+1);
                }
                t=t->next;
        }
}
int main()
{
        int n,x,y,i,ni,t;
        scanf("%d",&t);
        while(t--)
        {
                max=0;
                for(i=0;i<1000010;i++)
                {
                        vis[i]=0;
                        h[i]=0;
                        l[i] = NULL;
                }
                scanf("%d",&n);
                ni=n-1;
                while(ni--)
                {
                        scanf("%d %d",&x,&y);
                        addEdge(x,y);
                }
                //print(n);
                dfs(x,0);
                for(i=0;i<1000010;i++)
                {
                        h[i]=0;
                        vis[i]=0;
                }
                dfs(maxn,0);
                printf("%d\n",max+1);
        }
        return 0;
}
