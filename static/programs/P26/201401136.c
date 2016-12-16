#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
node *a[10000];
int arr[10000];
int prime[10000];
int temp[10000];
int visited[10000];
int j=0;
int k=0;
void multiples(int,int);
void sieve(int n)
{
    int i;
    if(n>=2)
    {
        temp[j]=2;
        j++;
        for(i=3;i<=n;i=i+2)
        {
            if(arr[i]==0)
            {
                temp[j]=i;
                j++;
                multiples(i,n);
            }
        }
    }
}
void multiples(int base,int n)
{
    int k=base;
    while(k*base<=n)
    {
        arr[k*base]=1;
        k++;
    }
}
void insert(node *c,int num)
{
    node *p=malloc(sizeof(node));
    p->val=num;
    p->next=c->next;
    c->next=p;
}
void creategraph(int num)
{
    int temp=num;
    int rem=temp%1000;
    temp=1000+rem;
    int i;
    for(i=0;i<9;i++)
    {
        if(arr[temp]==0&&temp!=num)
        {
            insert(a[num],temp);
        }
        temp=temp+1000;
    }
    temp=num;
    int quo;
    quo=temp/1000;
    rem=temp%100;
    temp=(quo*1000)+rem;
    for(i=0;i<=9;i++)
    {
        if(arr[temp]==0&&temp!=num)
        {
            insert(a[num],temp);
        }
        temp=temp+100;
    }
    temp=num;
    quo=temp/100;
    rem=temp%10;
    temp=quo*100+rem;
    for(i=0;i<=9;i++)
    {
        if(arr[temp]==0&&temp!=num)
        {
            insert(a[num],temp);
        }
        temp=temp+10;
    }
    temp=num;
    quo=temp/10;
    temp=quo*10;
    for(i=0;i<=9;i++)
    {
        if(arr[temp]==0&&temp!=num)
        {
            insert(a[num],temp);
        }
        temp=temp+1;
    }
}
int queue[100010];
int dist[100010];
int rear=-1;
int front=-1;
int bfs(int src,int dest)
{
    front++;
    int flag=0;
    rear++;
    queue[rear]=src;
    memset(dist,-1,sizeof(dist));
    dist[src]=0;
    memset(visited,0,sizeof(visited));
    visited[src]=1;
    while(front!=-1)
    {
        if(flag==1)
            break;
        int p=queue[front];
        if(front==rear)
            front=rear=-1;
        else
            front++;
        node *temp=a[p];
        temp=temp->next;
        while(temp!=NULL)
        {
            if(flag==1)
                break;
            if(dist[temp->val]==-1&&visited[temp->val]==0)
            {
                dist[temp->val]=dist[p]+1;
                if(front==-1)
                    front=0;
                rear++;
                queue[rear]=temp->val;
                visited[temp->val]=1;
                if(temp->val==dest)
                    flag=1;
            }
            temp=temp->next;
        }
    }
    return dist[dest];
}
int main()
{
    memset(arr,0,sizeof(arr));
    sieve(10000);
    int i;
    for(i=4;i<=10000;i=i+2)
        arr[i]=1;
    for(i=168;i<j;i++)
    {
        prime[k]=temp[i];
        k++;
    }
    for(i=0;i<10000;i++)
    {
        a[i]=malloc(sizeof(node));
        a[i]->next=NULL;

    }
    for(i=0;i<k;i++)
        creategraph(prime[i]);
    int t,tc;
    scanf("%d",&t);
    for(tc=0;tc<t;tc++)
    {
        rear=front=-1;
        int src,dest;
        scanf("%d%d",&src,&dest);
        int ans=bfs(src,dest);
        if(dist[dest]==-1)
            printf("Impossible\n");
        else
            printf("%d\n",dist[dest]);
    }
    return 0;
}
