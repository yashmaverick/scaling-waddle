#include <stdio.h>

#include <stdlib.h>


typedef struct link1
{
    long long int weight;
    long long int d;
    struct link1 *next;
}node;


node *a[100005];
long long int n;
long long int count;
long long int rear;
node *begin;
long long int position[100005];
long long int visited1[100005];
long long int heap[1000005];
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
    for(i=1;i<=rear;i++)
    {
        printf("position[%lld]=%lld ",heap[i],position[heap[i]]);
    }
    printf("\n");
}

void minheapify();
void minheapify1();

void delheap()
{
    heap[1]=heap[rear];
    rear=rear-1;
    position[heap[1]]=1;
    minheapify1(1);
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
        position[heap[min]]=min;
        position[heap[i]]=i;
        minheapify1(min);
    }
}





void minheapify(long long int i)
{
    if(i<=1)
        return;
    long long int parent=i/2;
    if(distance[heap[parent]]>distance[heap[i]])
    {
        long long int temp=heap[parent];
        heap[parent]=heap[i];
        heap[i]=temp;
        position[heap[parent]]=parent;
        position[heap[i]]=i;
    }
    minheapify(parent);
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



void prim()
{
    while(rear>0)
    {
        node *v=a[heap[1]];
        delheap();
        node *p=v;
        visited1[v->d]=1;
        v=v->next;
        while(v!=NULL)
        {
            // printf("%d ",v->d);
            if(visited1[v->d]==0)
            {
                if((v->weight)<distance[v->d])
                {
                    distance[v->d]=v->weight;
                    if(position[v->d]==-1)
                    {
                        rear=rear+1;
                        heap[rear]=v->d;
                        position[v->d]=rear;
                        minheapify(rear);
                    }
                    else
                    {
                        minheapify(position[v->d]);
                    }
                }
            }
            // print();
            v=v->next;
        }
        //  printf("\n");
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
        position[i]=-1;
        distance[i]=10000000000000100;
    }
    for(i=0;i<m;i++)
    {
        scanf("%lld %lld %lld",&x,&y,&w);
        node *p=(node *)malloc(sizeof(node));
        node *q=(node *)malloc(sizeof(node));
        q->d=x;
        q->weight=w;
        q->next=a[y]->next;
        p->d=y;
        p->weight=w;
        p->next=a[x]->next;
        a[x]->next=p;
        a[y]->next=q;
    }
    //  print1();
    finaldistance=0;
    rear=1;
    count=0;
    //print();
    distance[1]=0;
    position[1]=1;
    heap[rear]=1;
    prim();
    for(i=1;i<=n;i++)
    {
        if(visited1[i]==1)
            count++;
    }
    if(count==n)
    {
        for(i=1;i<=n;i++)
            finaldistance=finaldistance+distance[i];
        printf("%lld\n",finaldistance);
    }
    else
        printf("-1\n");
    return 0;
}
