#include <stdio.h>

#include <stdlib.h>


typedef struct link1
{
    int d;
    struct link1 *next;
}node;


node *a[1005];
node *b[1005];
int n,s,d;
int visited[10005];


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

void print1()
{
    int i;
    for(i=0;i<n;i++)
    {
        node *v=b[i];
        while(v!=NULL)
        {
            printf("%d ",v->d);
            v=v->next;
        }
        printf("\n");
    }
}

int k,maxdepth;
int c;

void dfs1(node *v,int depth)
{
    visited[v->d-1]=1;
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
                dfs1(b[r-1],depth+1);
            }
            v=v->next;
        }
    }
}

void dfs(node *v,int depth)
{
    visited[v->d-1]=1;
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
        }
    }
}


int main()
{
    int t,u;
    scanf("%d",&t);
    for(u=1;u<=t;u++)
    {
        int m,i,x,y,n1,j,ch,k;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            a[i]=(node *)malloc(sizeof(node));
            a[i]->d=(i+1);
            a[i]->next=NULL;
            b[i]=(node *)malloc(sizeof(node));
            b[i]->d=(i+1);
            b[i]->next=NULL;
            visited[i]=0;
        }
        for(m=1;m<=n;m++)
        {
            scanf("%d",&n1);
            for(i=0;i<n1;i++)
            {
                scanf("%d",&x);
                node *p=(node *)malloc(sizeof(node));
                p->d=m;
                p->next=a[x-1]->next;
                a[x-1]->next=p;
                node *q=(node *)malloc(sizeof(node));
                q->d=x;
                q->next=b[m-1]->next;
                b[m-1]->next=q;
            }
            //   print();
            //   print1();
        }
        int stack[n+1];
        int top=-1;
        c=0;
        int flag=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                visited[j]=0;
            if(flag==1)
            {
                dfs(a[i],0);
            }
            int flag1=0;
            for(j=0;j<n;j++)
            {
                if(visited[j]!=1)
                    flag1=1;
            }
            if(flag1==0)
                flag=0;
            if(flag==0)
            {
                for(j=0;j<n;j++)
                    visited[j]=0;
               // printf("%d\n",a[i]->d);
                dfs1(b[a[i]->d-1],0);
                for(j=0;j<n;j++)
                {
                 //       printf("visited[%d]=%d ",j,visited[j]);
                        if(visited[j]==1)
                            c++;
                }
                break;
                /*   for(k=0;k<=top;k++)
                     printf("stack[%d]=%d ",k,stack[k]);
                     printf("\n");*/
            }
        }
        printf("%d\n",c);
    }
    return 0;
}

