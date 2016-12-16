#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

int indeg[10000001];

void insert(node *list[],int u,int v)
{
    node *temp=malloc(sizeof(node));
    temp->data=v;
    temp->next=NULL;
    if(list[u]==NULL)
    {
        list[u]=malloc(sizeof(node));
        list[u]=temp;
        indeg[temp->data]++;
    //    if(indeg[temp->data] < min_indeg)
      //      min_indeg=indeg[temp->data];
    }
    else
    {
        temp->next=list[u]->next;
        list[u]->next=temp;
        indeg[temp->data]++;
        //if(indeg[temp->data] < min_indeg)
          //  min_indeg=indeg[temp->data];
    }
}

void swap(int *p,int *q)
{
    int hold=*p;
    *p=*q;
    *q=hold;
}

int min_heap[10000001],sz_min=0;
void ins_minheap(int x)
{
    sz_min++;
    int i=sz_min;
    min_heap[i]=x;
    while(min_heap[i]<min_heap[i/2] && i/2!=0)
    {
        swap(&min_heap[i],&min_heap[i/2]);
        i=i/2;
    }
}


int del_minheap()
{
    int ret=min_heap[1];
    min_heap[1]=min_heap[sz_min];
    min_heap[sz_min]='\0';
    sz_min--;
    int sz=sz_min;
    int i=1;
    while(i<=sz/2)
    {
        if((min_heap[i]>min_heap[2*i]) && (min_heap[i]>min_heap[2*i+1]) && (min_heap[2*i]!='\0') && (min_heap[2*i+1]!='\0'))
            if(min_heap[2*i]>min_heap[2*i+1])
            {
                swap(&min_heap[i],&min_heap[2*i+1]);
                i=2*i+1;
            }
            else
            {
                swap(&min_heap[i],&min_heap[2*i]);
                i=2*i;
            }
        else if(min_heap[i]>min_heap[2*i+1] && min_heap[2*i+1]!='\0')
        {
            swap(&min_heap[i],&min_heap[2*i+1]);
            i=2*i+1;
        }
        else if(min_heap[i]>min_heap[2*i] && min_heap[2*i]!='\0')
        {
            swap(&min_heap[i],&min_heap[2*i]);
            i=2*i;
        }
        else
            break;
    }
    return ret;
}

void task(node *list[],int n)
{
    int i,a[n+1];
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
            ins_minheap(i);
    }
    i=1;
    while(sz_min!=0)
    {
        int v=del_minheap();
        a[i]=v;
        node *temp=list[v];
        while(temp!=NULL)
        {
            indeg[temp->data]--;
            if(indeg[temp->data]==0)
                ins_minheap(temp->data);
            temp=temp->next;
        }
        i++;
    }
    for(i=1;i<=n-1;i++)
        printf("%d ",a[i]);
    printf("%d\n",a[n]);
}

int main()
{
    int n,m,i,u,v;
    scanf("%d%d",&n,&m);
    node *list[n+1];
    for(i=1;i<=n;i++)
    {
        list[i]=NULL;
        indeg[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&u,&v);
        insert(list,u,v);
    }
    task(list,n);
    return 0;
}
