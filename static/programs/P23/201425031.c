#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
int count[100010],visited[100010];
long long int maxheap[200005],minheap[200005],maxheapend,minheapend;

node *arr[100010],*arr2[100010];
void adjlistrdf(int i,int j)
{
    node *temp;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=j;
    new_node->next=NULL;
    if(arr[i]==NULL)
    {
        arr[i]=new_node;
    }
    else
    {
        temp=arr[i];
        arr[i]=new_node;
        new_node->next=temp;
    }
}
void adjlistfdr(int i,int j)
{
    node *temp;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=j;
    new_node->next=NULL;
    if(arr2[i]==NULL)
    {
        arr2[i]=new_node;
    }
    else
    {
        temp=arr2[i];
        arr2[i]=new_node;
        new_node->next=temp;
    }
}

void minheapins(long long int element)
{
    long long int w,temp;
    minheapend++;
    minheap[minheapend]=element;
    w=minheapend;
    while(w/2>=1)
    {
        if(minheap[w]<minheap[w/2])
        {
            temp=minheap[w];
            minheap[w]=minheap[w/2];
            minheap[w/2]=temp;
            w=w/2;
        }
        else
            break;
    }
}

long long int minheapdel()
{
    long long int l=minheap[1],temp,min,left,right,index;
    minheap[1]=minheap[minheapend];
    minheapend--;
    long long int u=1;
    while(2*u<=minheapend)
    {
        left=2*u;
        right=left+1;
        min=minheap[left];
        index=left;
        if(right<=minheapend)
        {
            if(minheap[right]<min)
            {
                min=minheap[right];
                index=right;
            }
        }
        if(minheap[u]>minheap[index])
        {
            temp=minheap[u];
            minheap[u]=minheap[index];
            minheap[index]=temp;
            u=index;
        }
        else
            break;
    }
    return l;
}

int main()
{
    long long int N,M,i,j,k,u,v,x;
    node *temp2;
    scanf("%lld %lld",&N,&M);
    for(i=0;i<=N;i++)
    {
        count[i]=0;
        arr[i]=NULL;
        arr2[i]=NULL;
    }
    for(i=0;i<M;i++)
    {
        scanf("%lld %lld",&u,&v);
        adjlistrdf(v,u);
        count[v]++;
        adjlistfdr(u,v);
    }

    minheapend=0;
//    for(k=0;k<=N;k++)
  //      minheap[k]=500005;
  //  while(N--)
   // {
   for(i=0;i<=N;i++)
       visited[i]=0;
   int p=0;
//   for(i=1;i<=N;i++)
  //     printf("%d\n",count[i]);
        for(i=1;i<=N;i++)
        {
            if(count[i]==0 && visited[i]!=1)
            {    minheapins(i);
                visited[i]=1;
            }
            }
   while(1)
   {
       
     //       if(minheapend>=1)
       //     {
                x=minheapdel();
                p++;
         //   }
            temp2=arr2[x];
            while(temp2!=NULL)
            {
                count[temp2->data]--;
                if(count[temp2->data]==0)
                {
                    minheapins(temp2->data);
                    visited[temp2->data]=1;
                }
                temp2=temp2->next;
            }
            printf("%lld",x);
     //       if(N>0)
       //         printf(" ");
        
            if(p==N)
            {
                printf("\n");
                break;
            }
            printf(" ");
    }
    return 0;
}
