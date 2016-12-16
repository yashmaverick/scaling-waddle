#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define f(x) scanf("%d",&x)
typedef struct node
{
    int v;
    struct node *next;
}node;
node **head;
int *heap,*count,*visit,num;
node *insert(node *w,int p)
{
    if(w==NULL)
    {
        node *q;
        q=(node *)malloc(sizeof(node));
        q->v=p;
        q->next=NULL;
        w=q;
    }
    else
    {
        node *q;
        q=(node *)malloc(sizeof(node));
        q->v=p;
        q->next=w;
        w=q;
    }
    return w;
}
void insert1(int d)
{
    num++;
    heap[num]=d;
    int a,temp=num;
    while(heap[temp]<heap[temp/2] && temp>1)
    {
        a=heap[temp];
        heap[temp]=heap[temp/2];
        heap[temp/2]=a;
        temp=temp/2;
    }
}
int delete()
{
    int a,b,temp;
    b=heap[1];
    heap[1]=heap[num];
    num--;
    temp=1;
    while(2*temp<=num)
    {
        if(2*temp==num)
        {
            if(heap[temp*2]<heap[temp])
            {
                a=heap[temp];
                heap[temp]=heap[2*temp];
                heap[2*temp]=a;
            }
            break;
        }
        else if(heap[temp]>heap[temp*2] || heap[temp]>heap[2*temp+1])
        {
            if(heap[2*temp]>heap[2*temp+1])
            {
                a=heap[2*temp+1];
                heap[2*temp+1]=heap[temp];
                heap[temp]=a;
                temp=2*temp+1;
            }
            else
            {
                a=heap[2*temp];
                heap[2*temp]=heap[temp];
                heap[temp]=a;
                temp=2*temp;
            }
        }
        else
            break;
    }
    return b;
}
void dfs(node *r)
{
    node *q;
    q=r;
    while(q!=NULL)
    {
        count[q->v]--;
        if(count[q->v]==0)
            insert1(q->v);
        q=q->next;
    }
}
int main()
{
    int i,j,k,l,t,n,z=0;
    f(t);
    heap=(int *)malloc(sizeof(int)*(t+1));
    count=(int *)malloc(sizeof(int)*(t+1));
    visit=(int *)malloc(sizeof(int)*(t+1));
    head=(node **)malloc(sizeof(node *)*(t+1));
//    memset(count,0,sizeof(count));
//    memset(visit,0,sizeof(count));
    num=0;
    for(i=1;i<=t;i++)
    {head[i]=NULL;
        count[i]=0;
    }
    f(n);
    for(i=1;i<=n;i++)
    {
        f(k);
        f(l);
        head[k]=insert(head[k],l);
        count[l]++;
    }
    for(i=1;i<=t;i++)
    {
        if(count[i]==0)
            insert1(i);
    }
    while(num!=0)
    {
        k=delete();
        visit[z]=k;
        z++;
       // printf("%d ",k);
        dfs(head[k]);
    }
    for(k=0;k<(z-1);k++)
        printf("%d ",visit[k]);
    printf("%d\n",visit[k]);
    return 0;
}





    









