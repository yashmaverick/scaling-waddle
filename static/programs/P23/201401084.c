#include <stdio.h>

#include <stdlib.h>


typedef struct link1
{
    int d;
    struct link1 *next;
}node;


node *a[100005];
int n;
int rear;
int visited[100005];
int degree[100005];
int minheap[100005];


void print()
{
    int i;
    for(i=1;i<=n;i++)
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
    for(i=1;i<=rear;i++)
    {
        printf("minheap[%d]=%d ",i,minheap[i]);
    }
    printf("\n");
}


void shuffledownminheapify();

void minheapify();


void delheap()
{
    node *v=a[minheap[1]];
    v=v->next;
    minheap[1]=minheap[rear];
    rear=rear-1;
    shuffledownminheapify(1);
    while(v!=NULL)
    {
        degree[v->d]--;
        if(degree[v->d]==0)
        {
            rear++;
            minheap[rear]=v->d;
            minheapify(rear);
            visited[v->d]=1;
        }
        v=v->next;
    }
}



void shuffledownminheapify(int i)
{
    int left=2*i;
    int right=2*i+1;
    int min=i;
    if(left<=rear && minheap[min]>minheap[left])
        min=left;
    if(right<=rear && minheap[min]>minheap[right])
        min=right;
    if(min!=i)
    {
        int temp=minheap[min];
        minheap[min]=minheap[i];
        minheap[i]=temp;
        shuffledownminheapify(min);
    }
}


void minheapify(int i)
{
    if(i==1)
        return;
    int parent=i/2;
    if(minheap[parent]>minheap[i])
    {
        int temp=minheap[parent];
        minheap[parent]=minheap[i];
        minheap[i]=temp;
        minheapify(parent);
    }
    //  minheapify(parent);
    // print1();
}



int main()
{
    int m,i,x,y;
    scanf("%d %d",&n,&m);
    //    a=(node *)malloc(n*sizeof(node));
    for(i=1;i<=n;i++)
    {
        a[i]=(node *)malloc(sizeof(node));
        a[i]->d=(i);
        a[i]->next=NULL;
        visited[i]=0;
        degree[i]=0;
    }
    rear=0;
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&x,&y);
        degree[y]++;
        node *p=(node *)malloc(sizeof(node));
        p->d=y;
        p->next=a[x]->next;
        a[x]->next=p;
    }
    //print();
    for(i=1;i<=n;i++)
    {
     //   printf("degree[%d]=%d ",i,degree[i]);
        if(degree[i]==0)
        {
            rear++;
            minheap[rear]=i;
            visited[i]=1;
            minheapify(rear);
        }
    }
   // print1();
    int flag=0;
    while(rear>0)
    {
        int x=minheap[1];
        delheap();
        if(rear==0)
            printf("%d\n",x);
        else
            printf("%d ",x);
      //  print1();
    }
    return 0;
}


