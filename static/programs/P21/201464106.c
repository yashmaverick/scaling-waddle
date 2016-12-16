#include<stdio.h>
#include<malloc.h>
#include<limits.h>
typedef struct node
{
    int data;
    long long int wt;
    struct node *next;
}node;

typedef struct heap_node
{
    int v;
    long long int d;
}heap_node;

long long int sz=0; 
heap_node heap[10000001];

void swap(heap_node *p,heap_node *q)
{
    heap_node hold=*p;
    *p=*q;
    *q=hold;
}

void ins_heap(heap_node x)
{
    sz++;
    heap[sz]=x;
    int i=sz;
    while(heap[i/2].d > heap[i].d)
    {
        swap(&heap[i/2],&heap[i]);
        i=i/2;
    }
}

heap_node del_heap(int n)
{
    int i=1;
    heap_node min;
    min=heap[1];
    heap[1]=heap[sz];
    heap[sz].d='\0';
    sz--;
    while(i<=sz/2)
    {
        if((heap[i].d>heap[2*i+1].d) && (heap[i].d>heap[2*i].d) && (heap[2*i].d!='\0') && (heap[2*i+1].d!='\0'))
        {
            if(heap[2*i].d > heap[2*i+1].d)
            {
                swap(&heap[i],&heap[2*i+1]);
                i=2*i+1;
            }
            else
            {
                swap(&heap[i],&heap[2*i]);
                i=2*i;
            }
        }
        else if((heap[i].d>heap[2*i+1].d) && (heap[2*i+1].d!='\0'))
        {
            swap(&heap[i],&heap[2*i+1]);
            i=2*i+1;
        }
        else if((heap[i].d>heap[2*i].d) && (heap[2*i].d!='\0'))
        {
            swap(&heap[i],&heap[2*i]);
            i=2*i;
        }
        else
            break;
    }
    return min;
}


void insert(node *list[],int p,int q,long long int w)
{
    node *temp=malloc(sizeof(node));
    temp->data=q;
    temp->wt=w;
    temp->next=NULL;
    if(list[p]==NULL)
    {
        list[p]=malloc(sizeof(node));
        list[p]=temp;
    }
    else
    {
        temp->next=list[p]->next;
        list[p]->next=temp;
    }
}


void dij(node *list[],int u,int t,int n)
{
    int vis[n+1],flag=0;
    long long int dis[n+1];
    int i;
    for(i=1;i<=n;++i)
    {
        vis[i]=0;
        dis[i]=INT_MAX;
    }
    heap_node temp;
    dis[u]=0;
    int cur_dis;
    temp.d=0;
    temp.v=u;    
    ins_heap(temp);
    while(sz)
    {
        heap_node min=del_heap(n);
        vis[min.v]=1;
        if(min.v==t)
        {
            flag=1;
            break;
        }
        node *y=list[min.v];
        while(y!=NULL)
        {
            temp.v=y->data;
            cur_dis = y->wt + dis[min.v];
            temp.d=cur_dis;
            if(vis[temp.v]!=1 && cur_dis <= dis[temp.v])
            {
                ins_heap(temp);
                dis[temp.v]=cur_dis;
            }
            y=y->next;
        }
    }
    if(vis[t]==1)
        printf("%lld\n",dis[t]);
    else
        printf("NO\n");
}

int main()
{

    int n,i,p,q;
    long long int e,w;
    scanf("%d",&n);
    node *list[n+1];
    for(i=1;i<=n;i++)
        list[i]=NULL;
    scanf("%lld",&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d%d%lld",&p,&q,&w);
        insert(list,p,q,w);
    }
    /*    for(i=1;i<=n;i++)
          {
          printf("%d--->",i);
          node *temp=list[i];
          while(temp!=NULL)
          {
          printf("vertex:%d,wt(%d-%d):%d ",temp->data,i,temp->data,temp->wt);
          temp=temp->next;
          }
          printf("\n");
          }
          printf("enter starting node: ");*/
    int s,t;
    scanf("%d%d",&s,&t);
    dij(list,s,t,n);
    sz=0;
    return 0;
}

