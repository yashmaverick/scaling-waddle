#include <stdio.h>

#include <stdlib.h>


typedef struct link1
{
    int d;
    struct link1 *next;
}node;


node *a[1000005];
int n,s,d;
int top=-1;
int visited[1000005];


void print()
{
    int i;
    for(i=0;i<n;i++)
    {
        node *v=a[i];
        while(v!=NULL)
        {
            printf("%d ",v->d);
            v=v->next;
        }
        printf("\n");
    }
}


int k,maxdepth;
int flag1=0;
int flag2=0;
node *f;

void dfs(node *v,int depth)
{
    //  flag1=0;
    visited[v->d-1]=1;
    //  printf("%d  ",v->d);
    if(depth>maxdepth)
    {
        maxdepth=depth;
        f=v;
    }
    if(v->next==NULL)
        return;
    else
    {
        v=v->next;
        while(v!=NULL)
        {
            int r=v->d;
            if(visited[r-1]==0)
            {
                visited[r-1]=1;
                dfs(a[r-1],depth+1);
            }
            v=v->next;
            // dfs(v->next->next,depth+1);
        }
    }
}


int main()
{
    int m,i,x,y;
    int t,u;
    scanf("%d",&t);
    for(u=1;u<=t;u++)
    {
        maxdepth=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            a[i]=(node *)malloc(sizeof(node));
            a[i]->d=(i+1);
            a[i]->next=NULL;
            visited[i]=0;
        }
        if(n==1)
        {
            printf("1\n");
        }
        else
        {
            for(i=0;i<n-1;i++)
            {
                scanf("%d %d",&x,&y);
                node *p=(node *)malloc(sizeof(node));
                node *q=(node *)malloc(sizeof(node));
                q->d=x;
                q->next=a[y-1]->next;
                p->d=y;
                p->next=a[x-1]->next;
                a[x-1]->next=p;
                a[y-1]->next=q;
                //print();
            }
            dfs(a[0],0);
            //   printf("\n");
            for(i=0;i<n;i++)
                visited[i]=0;
            dfs(f,0);
            printf("%d\n",maxdepth+1);
        }
    }
    //    printf("depth=%d",depth);
    return 0;
}


