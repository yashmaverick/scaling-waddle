#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define f(x) scanf("%d",&x)
typedef struct node
{
    int data;
    struct node *next;
}node;
node *insert(node *head,int p)
{
    if(head==NULL)
    {
        node *q;
        q=malloc(sizeof(node));
        q->data=p;
        q->next=NULL;
        head=q;
    }
    else
    {
        node *q;
        q=malloc(sizeof(node));
        q->data=p;
        q->next=head;
        head=q;
    }
    return head;
}
node *head[1000001];
int max=0,vertex=0,visit[1000001];
void dfs(int current,int val)
{
  //  printf("%d ",val);
    if(visit[current]==1)
        return ;
    if(val>max)
    {
        max=val;
        vertex=current;
    }
    val++;
    visit[current]=1;
    node *q;
    q=head[current];
    while(q!=NULL)
    {
        if(visit[q->data]==0)
        {dfs(q->data,val);
        }
        q=q->next;
    }
}
int main()
{
    int i,j,k,l,t,n,m,a,b;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {f(n);
        for(k=1;k<=n;k++)
            head[k]=NULL;
        max=0;
        vertex=0;
        l=0;
        for(k=1;k<n;k++)
        {
            f(a);
            f(b);
            head[a]=insert(head[a],b);
            head[b]=insert(head[b],a);}
        memset(visit,0,sizeof(visit));
        dfs(1,l);
        m=0;
       // max=0;
       // printf("%d\n",vertex);
        max=0;
        memset(visit,0,sizeof(visit));
        dfs(vertex,m);
        printf("%d\n",max+1);
    }
    return 0;
}









