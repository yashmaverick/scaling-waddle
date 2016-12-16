#include <stdio.h>

#include <stdlib.h>


typedef struct link1
{
    long long int weight;
    long long int d;
    struct link1 *next;
}node;


node *a[100005];
long long int n,s,d;
long long int rear;
node *begin;
long long int visited[100005];
long long int visited1[100005];
long long int heap[100005];
long long int distance[100005];
long long int finaldistance;

void print()
{
    long long int i;
    for(i=1;i<=n;i++)
    {
        printf("distance[%lld]=%lld ",i,distance[i]);
    }
    printf("\n");
    for(i=1;i<=rear;i++)
    {
        printf("heap[%lld]=%lld ",i,heap[i]);
    }
    printf("\n");
}

void minheapify();
void minheapify1();

void delheap()
{
    heap[1]=heap[rear];
    rear=rear-1;
    minheapify1(rear);
   // print();
}

void minheapify1(long long int i)
{
    if(i==0)
        return;
    long long int left=2*i;
    long long int right=2*i+1;
    long long int min=i;
    if(left<=rear && distance[heap[min]]>distance[heap[left]])
        min=left;
    if(right<=rear && distance[heap[min]]>distance[heap[right]])
        min=right;
    if(min!=i)
    {
        long long int temp=heap[min];
        heap[min]=heap[i];
        heap[i]=temp;
        minheapify1(min);
    }
}





void minheapify(long long int i)
{
    if(i<=1)
        return;
    long long int parent=i/2;
    minheapify(i/2);
    if(distance[heap[parent]]>distance[heap[i]])
    {
        long long int temp=heap[parent];
        heap[parent]=heap[i];
        heap[i]=temp;
        //        minheapify(parent);
    }
    //  minheapify(parent);
    //   print();
}



void print1()
{
    long long int i;
    for(i=1;i<=n;i++)
    {
        node *v=a[i];
        while(v!=NULL)
        {
            printf("node=%lld weight=%lld ",v->d,v->weight);
            v=v->next;
        }
        printf("\n");
    }
}



void dfs(node *v,int depth)
{
    //  flag1=0;
    visited[v->d]=1;
    //   printf("%d  ",v->d);
    if(v->next==NULL)
        return;
    else
    {
        v=v->next;
        while(v!=NULL)
        {
            long long int r=v->d;
            if(visited[r]==0)
            {
                visited[r]=1;
                dfs(a[r],depth+1);
            }
            v=v->next;
            // dfs(v->next->next,depth+1);
        }
    }
}



void dijkstra()
{
    while(rear>0)
    {
        node *v=a[heap[1]];
        delheap();
        node *p=v;
        if(visited1[v->d]==0)
        {
            visited1[v->d]=1;
            v=v->next;
            while(v!=NULL)
            {
                // printf("%d ",v->d);
                if((distance[p->d]+v->weight)<distance[v->d])
                {
                    distance[v->d]=distance[p->d]+v->weight;
                    rear=rear+1;
                    heap[rear]=v->d;
                    minheapify(rear);
                }
                // print();
                v=v->next;
            }
            //  printf("\n");
        }
    }
}



int main()
{
    long long int m,i,x,y,t,u;
    long long int w;
    scanf("%lld %lld",&n,&m);
    //    a=(node *)malloc(n*sizeof(node));
    for(i=1;i<=n;i++)
    {
        a[i]=(node *)malloc(sizeof(node));
        a[i]->d=(i);
        a[i]->next=NULL;
        visited1[i]=0;
        visited[i]=0;
        distance[i]=10000000000000100;
    }
    for(i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&w);
        node *p=(node *)malloc(sizeof(node));
        /* node *q=(node *)malloc(sizeof(node));
           q->d=x;
           q->weight=w;
           q->next=a[y-1]->next;*/
        p->d=y;
        p->weight=w;
        p->next=a[x]->next;
        a[x]->next=p;
        // a[y-1]->next=q;
        // print1();
    }
    rear=1;
    //print();
    scanf("%lld %lld",&s,&d);
    distance[s]=0;
    heap[rear]=s;
    begin=a[s];
    dfs(a[s],0);
    if(visited[d]==0)
        printf("NO\n");
    else
    {
        dijkstra();
        finaldistance=distance[d];
        printf("%lld\n",finaldistance);
    }
    return 0;
}
