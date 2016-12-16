#include<stdlib.h>
#include<stdio.h>
int visit[100007];
struct node
{
    int data;
    struct node* ptr;
};
typedef struct node node;
node* in[100007];
node* out[100007];
void insertinnode(int i,int j)
{
    node* t=(node*)malloc(sizeof(node));
    t->data=i;
    t->ptr=in[j];    
    in[j]=t;
    return;
}
void insertoutnode(int i,int j)
{
    node* t=(node*)malloc(sizeof(node));
    t->data=j;
    t->ptr=out[i];
    out[i]=t;
    return;
}
void dfs(int v)
{
    visit[v]=1;
    node* t;
    for(t=out[v];t!=NULL;t=t->ptr)
        if(visit[t->data]==0)
            dfs(t->data);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int it;
        for(it=1;it<=n;it++)
        {
            visit[it]=0;
            in[it]=NULL;
            out[it]=NULL;
        }
        for(it=1;it<=n;it++)
        {
            int kk;
            scanf("%d",&kk);
            int jt;
            for(jt=1;jt<=kk;jt++)
            {
                int vt;
                scanf("%d",&vt);
                insertinnode(vt,it);
                insertoutnode(vt,it);
            }
        }
/*        for(it=1;it<=n;it++)
        {
            node* t=out[it];
            while(t!=NULL)
            {
                printf("%d ",t->data);
                t=t->ptr;
            }
            printf("\n");
        }*/
        for(it=1;it<=n;it++)
        {
            int jt;
            for(jt=1;jt<=n;jt++)
                visit[jt]=0;
            dfs(it);
            int ct=0;
            for(jt=1;jt<=n;jt++)
            {//   printf("%d ",visit[jt]);
                if(visit[jt]==1)
                    ct++;
            }
            if(ct==n)
            {
                break;
            }                
        }
        int wt=it;
          int jt;
        for(jt=1;jt<=n;jt++)
        {
            visit[jt]=0;
            out[jt]=in[jt];
        }
        dfs(wt);
        int ct=0;
        for(jt=1;jt<=n;jt++)
            if(visit[jt]==1)
                ct++;
        printf("%d\n",ct);

    }
    return 0;
}
