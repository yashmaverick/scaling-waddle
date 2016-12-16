#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    long long int wt;
}node;

typedef struct heap_node
{
    int v;
    long long int d;
}heap_node;

heap_node heap[1000001];
int sz=0;

void swap(heap_node *p,heap_node *q)
{
    heap_node hold=*p;
    *p=*q;
    *q=hold;
}

void ins_heap(heap_node x)
{
    int i;
    heap[++sz]=x;
    i=sz;
    while(heap[i/2].d > heap[i].d)
    {
        swap(&heap[i/2],&heap[i]);
        i=i/2;
    }
}

int vis[1000001];

/*heap_node del_heap(int n)
  {
  sz--;
  heap_node minEle;
  minEle=heap[1];
  heap[1]=heap[sz];
  heap[sz].v='\0';
  heap[sz].d='\0';
//   sz--;
int i=1;
while(heap[i].d>heap[2*i].d || heap[i].d>heap[2*i+1].d)
{
if(2*i>=n)
break;
if(heap[2*i].d<=heap[2*i+1].d)
{
swap(&heap[2*i],&heap[i]);
i=2*i;
}
else
{
swap(&heap[2*i+1],&heap[i]);
i=2*i+1;
}
}
printf("minEle:%d\n",minEle.v);
if(vis[minEle.v]==0)
{
return minEle;
}
}*/

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



void insert(node *list[],int u,int v,long long int w)
{
    node *temp=malloc(sizeof(node));
    temp->data=v;
    temp->wt=w;
    temp->next=NULL;
    if(list[u]==NULL)
    {
        list[u]=malloc(sizeof(node));
        list[u]=temp;
    }
    else
    {
        temp->next=list[u]->next;
        list[u]->next=temp;
    }
}



void prim(int s,node *list[],int n)
{
    int mst[n+1],i,dis[n+1];
    long long int sum=0;
    for(i=1;i<=n;i++)
    {
        vis[i]=0;
        dis[i]=INT_MAX;
    }
    vis[0]='\0';
    heap_node x,min;
    x.d=0;
    x.v=s;
    dis[s]=0;
    ins_heap(x);
    i=1;
    int j,c=0;
    while(sz!=0)
    {
//        for(j=1;j<=sz;j++)
  //          printf("heap:%d ",heap[j].v);
//        printf("\n");
        min=del_heap(n);
        if(vis[min.v]==0)
        {
            vis[min.v]=1;
            c++;
            mst[i]=min.d;
            node *temp=list[min.v];
            sum+=mst[i];
            while(temp!=NULL)
            {
                x.v=temp->data;
                x.d=temp->wt;
                if(vis[x.v]==0 && x.d<dis[x.v])
                {
                    dis[x.v]=x.d;
                    ins_heap(x);
                }
                temp=temp->next;
            }
            i++;
        }
    }
    if(c>=n)
        printf("%lld\n",sum);
    else
        printf("-1\n");
}



int main()
{
    int n,i,u,v;
    long long e,w;
    scanf("%d",&n);
    node *list[n+1];
    for(i=1;i<=n;i++)
        list[i]=NULL;
    scanf("%lld",&e);
    for(i=1;i<=e;i++)
    {
        scanf("%d%d%lld",&u,&v,&w);
        insert(list,u,v,w);
        insert(list,v,u,w);
    }
    /*printf("Adj. list.:\n");
      for(i=1;i<=n;i++)
      {
      printf("%d--->",i);
      node *temp=list[i];
      while(temp!=NULL)
      {
      printf("val:%d wt(%d,%d):%d ",temp->data,i,temp->data,temp->wt);
      temp=temp->next;
      }
      printf("\n");
      }*/
    prim(1,list,n);
    return 0;
}



