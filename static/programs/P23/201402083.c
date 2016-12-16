
/*
   _____________________________________________
   PROBLEM STATEMENT: 
   TEST CASES:
COMMENTS:

SOLVED BY - YOGESH SHARMA
______________________________________________ 
*/
#include <stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define LL long long int 

typedef struct node node;
struct node
{
    int nodename;
    node * next;
};
int minheap[100001];
int size_minheap;
int pri[100001];
void swap(int arr[],int i ,int j);
int max(int a,int b);
int min(int a,int b);
void insert_minheap(int element)
{
    int i;
    minheap[size_minheap++]=element;
    for(i=size_minheap-1;i>0;)
    {   
        if(minheap[i/2]>minheap[i])
        {
            swap(minheap,i/2,i);
            i=i/2;
        }
        else break;
    }   
}

int delete_minheap()
{
    int i;
    swap(minheap,1,--size_minheap);
    for(i=1;2*i+1<size_minheap;)
    {
        int temp=minheap[2*i]<minheap[2*i+1]?2*i:2*i+1;
        if(minheap[i]>minheap[temp])
        {
            swap(minheap,i,temp);
            i=temp;
        }
        else break;
    }
    if(2*i+1==size_minheap) if(minheap[i]>minheap[2*i]) swap(minheap,i,2*i);
    return minheap[size_minheap];
}

node *insert(node *head,int nodename)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->nodename=nodename;
    temp->next=head;
    return temp;
}
void print(node *head)
{
    if (head==NULL) return ;
    printf("%d ",head->nodename);
    print(head->next);
}
int main()
{
    node *arr[100001];

    size_minheap=1;
    minheap[0]=-1;

    int pri[100001];
    int res[100001];
    int n,m,i,a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<100001;i++) {arr[i]=NULL;pri[i]=0;}
    for(i=0;i<m;i++)
    {
        scanf("%d %d",&a,&b);
        arr[a]=insert(arr[a],b);
        pri[b]++;
    }

    for(i=1;i<=n;i++)
    {
        if(pri[i]==0) insert_minheap(i);
    }
    int s=0;
    while(s<n)
    {
//        printf("minheap\n");
  //      for(i=1;i<size_minheap;i++) printf("%d ",minheap[i]);
    //    printf("\n");
        int k=delete_minheap();
        node *temp=arr[k];
        while(temp!=NULL)
        {
            pri[temp->nodename]--;
            if(pri[temp->nodename]==0) insert_minheap(temp->nodename);
            temp=temp->next;
        }
      //  for(i=0;i<=n;i++) printf("%d-%d  ",i,pri[i]);
       // printf("\n");
        res[s++]=k;
    }
    for(i=0;i<n-1;i++) printf("%d ",res[i]);
    printf("%d\n",res[n-1]);
    return 0;
}

void swap(int arr[],int i,int j)              // swaps value at index i and j in arr[]
{
    if(i==j) return ;
    arr[i]=arr[i]+arr[j];
    arr[j]=arr[i]-arr[j];
    arr[i]=arr[i]-arr[j];
}
int max(int a , int b)                    // returns max of two numbers
{
    int c=a>b?a:b;
    return c;
}

int min(int a,int b)                     //returns min of two numbers
{
    int c=a<b?a:b;
    return c;
}
