#include <stdio.h>
#include <stdlib.h>

typedef struct link1
{
    int d;
    struct link1 *next;
}node;

node *a[100005];
int n,s,d;
int top=-1;
int front,rear;
int visited[100005];
int q[100000][2];
int prime[1000001];


void primesieve()
{
    int i,j;
    for(i=0;i<=10002;i++)
        prime[i]=1;
    prime[0]=1;
    prime[1]=0;
    prime[2]=1;
    for(i=4;i<=10002;i=i+2)
        prime[i]=0;
    for(i=3;i<=10002;i=i+2)
        for(j=i*i;j<=10002;j=j+i)
            if(prime[j])
                prime[j]=0;
}



void print()
{
    int i;
    node *v;
    for(i=1000;i<=10000;i++)
    {
        if(prime[i])
        {
            printf("%d ",i);
            v=a[i];
            v=v->next;
            while(v!=NULL)
            {
                printf("%d ",v->d);
                v=v->next;
            }
            printf("\n");
        }
    }
}


int k;
long long int maxdepth;

/*void dfs(node *v,int depth)
{
    //  flag1=0;
    visited[v->d]=1;
    printf("%d  ",v->d);
    if(v->next==NULL)
        return;
    else
    {
        v=v->next;
        while(v!=NULL)
        {
            int r=v->d;
            if(r==d)
            {
                printf("depth=%d ",depth);
                if(maxdepth>depth)
                    maxdepth=depth;
            }
            if(visited[r]==0)
            {
                visited[r]=1;
                dfs(a[r],depth+1);
            }
            v=v->next;
            // dfs(v->next->next,depth+1);
        }
    }
}*/


void bfs()
{
    front=0;
    rear=0;
    q[front][0]=s;
    q[front][1]=0;
    visited[s]=1;
    rear++;
    while(front!=rear)
    {
        node *v=a[q[front][0]]->next;
        while(v!=NULL)
        {
            int r=v->d;
            if(visited[r]==0)
            {
                if(v->d==d)
                {
                    maxdepth=q[front][1]+1;
                   // printf("maxdepth=%lld ",maxdepth);
                }
                q[rear][0]=v->d;
                q[rear][1]=q[front][1]+1;
                rear++;
                visited[r]=1;
            }
            v=v->next;
        }
        front++;
    }
}

int main()
{
    int m,i,x,y,j;
    //    a=(node *)malloc(n*sizeof(node));
    for(i=1000;i<=10000;i++)
    {
        a[i]=(node *)malloc(sizeof(node));
        a[i]->d=i;
        a[i]->next=NULL;
        visited[i]=0;
    }
    primesieve();
    for(i=1000;i<=10000;i++)
    {
        if(prime[i]==1)
        {
            int r1=i/1000;
            int r4=i%10;
            int r2=(i/100)%10;
            int r3=(i/10)%10;
            for(j=1000;j<=10000;j++)
            {
                if(prime[j]==1)
                {
                    int d1=j/1000;
                    int d4=j%10;
                    int d2=(j/100)%10;
                    int d3=(j/10)%10;
                    if(d1==r1 && d2==r2 && d3==r3 && d4!=r4)
                    {
                       // node *p=(node *)malloc(sizeof(node));
                        node *q=(node *)malloc(sizeof(node));
                        q->d=j;
                        q->next=a[i]->next;
                       // p->d=i;
                       // p->next=a[j]->next;
                       // a[j]->next=p;
                        a[i]->next=q;

                    }
                    else if(d1!=r1 && d2==r2 && d3==r3 && d4==r4)
                    {
                      //  node *p=(node *)malloc(sizeof(node));
                        node *q=(node *)malloc(sizeof(node));
                        q->d=j;
                        q->next=a[i]->next;
                       // p->d=i;
                        //p->next=a[j]->next;
                       // a[j]->next=p;
                        a[i]->next=q;
                    }
                    else if(d1==r1 && d2!=r2 && d3==r3 && d4==r4)
                    {
                       // node *p=(node *)malloc(sizeof(node));
                        node *q=(node *)malloc(sizeof(node));
                        q->d=j;
                        q->next=a[i]->next;
                       // p->d=i;
                       // p->next=a[j]->next;
                       // a[j]->next=p;
                        a[i]->next=q;
                    }
                    else if(d1==r1 && d2==r2 && d3!=r3 && d4==r4)
                    {
                       // node *p=(node *)malloc(sizeof(node));
                        node *q=(node *)malloc(sizeof(node));
                        q->d=j;
                        q->next=a[i]->next;
                       // p->d=i;
                       // p->next=a[j]->next;
                       // a[j]->next=p;
                        a[i]->next=q;
                    }
                }
            }
        }
    }
   // print();
    int t;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        maxdepth=0;
        scanf("%d %d",&s,&d);
        for(i=1000;i<=10000;i++)
            visited[i]=0;
        bfs();
        printf("%lld\n",maxdepth);
    }
    return 0;
}
