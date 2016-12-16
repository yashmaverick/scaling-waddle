#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct link
{
    long long int num;
    struct link * next;
};
typedef struct link link;
struct node
{
    long long int count;
    link * connect;
};
typedef struct node node;
node map[1000010];
long long int heap[1000010];
long long int top=1;
void push(long long int k)
{
    if(top==1)
    {       
        heap[1]=k;
        top++;
    }
    else
    {
        long long int i=top;
        long long int temp;
        heap[top]=k;
        while(heap[i]<heap[i/2]&&i!=1)
        {
            temp=heap[i/2];
            heap[i/2]=heap[i];
            heap[i]=temp;
            i=i/2;
        }
        top++;
    }
    return;
}
void pop()
{
    top--;
    long long int i=1,j=2;
    while(j<top)
    {
        if(heap[j]>heap[j+1])
            j++;
        if(heap[j]>=heap[top])
        {
            heap[i]=heap[top];
            j=top;
            return;
        }
        heap[i]=heap[j];
        i=j;
        j=j*2;
    }

    heap[i]=heap[top];

    return;
}

void insert(long long int e1,long long int e2)
{
    link *temp;
    temp=(link*)malloc(sizeof(link));
    temp->next=map[e1].connect;
    map[e1].connect=temp;
    temp->num=e2;
    map[e2].count++;
}
int main()
{   
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    long long int i;
    for(i=1;i<n+1;i++)
    {
        map[i].count=0;
        map[i].connect=NULL;
    }
    for(i=0;i<m;i++)
    {
        long long int e1,e2;
        scanf("%lld%lld",&e1,&e2);
        insert(e1,e2);
    }
    for(i=1;i<=n;i++)
    {
        if(map[i].count==0)
            push(i);
    } 
    if(top!=1)
    {
        printf("%lld",heap[1]);
        link* t;
        t=map[heap[1]].connect;
        pop();
        while(t!=NULL)
        {
            map[t->num].count--;
            if(map[t->num].count==0)
                push(t->num);
            t=t->next;
        }
    }
    while(top!=1)
    {
        printf(" %lld",heap[1]);
        link* t;
        t=map[heap[1]].connect;
        pop();
        while(t!=NULL)
        {
            map[t->num].count--;
            if(map[t->num].count==0)
                push(t->num);
            t=t->next;
        }
    }
    printf("\n");
    return 0;
}