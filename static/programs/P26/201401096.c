#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define primenos 1000000

#define inf  1000000007


int q[primenos];

int dist[primenos];

int front,rear;
int prime[primenos];

typedef struct element
{
    int ver,weight;
    struct element *next;
}element;
element *adj[primenos];


void insert(int src,int dest,int weight)
{
    element *p = (element*)malloc(sizeof(element));
    p->ver=dest;
    p->weight=weight;
    p->next=NULL;
    if(adj[src]==NULL)
        adj[src]=p;
    else
    {
        p->next=adj[src];
        adj[src]=p;
    }

    return;


}


void sieve()
{
    int i,j;
    //0->true
    //1->false
    prime[0]=prime[1]=1;
    for (i=2;i<=10000;++i)
        if(prime[i]==0)
            for(j=i*i;j<=10000;j+=i)
                prime[j]=1;

}

void bfs(int src,int dest)
{
    int front=0,rear=0,f=0;

    dist[src]=0;

    q[rear++]=src;

    if(src==dest)
        return;

    while(front!=rear&&f==0)
    {
        int top=q[front];
        front++;
        element* tmp=adj[top];
        while(tmp!=NULL){
            if(dist[tmp->ver]==-1)
            {
                q[rear++]=tmp->ver;
                dist[tmp->ver]=dist[top]+1;
                if(tmp->ver==dest)
                {f=1;break;}
            }
            tmp=tmp->next;
        }
    }

}
int main()
{
    int src,dest,w;
    int s,t,i;
    int test,j,num,a,b,c,d;

    scanf("%d",&test);

    for(i=0;i<100000;++i)
        adj[i]=NULL;
    sieve();

    for(i=1000;i<=10000;++i)
    {
        num=i;
        a=(num/10)*10;
        b=(num/100)*100+num%10;
        c=(num/1000)*1000+num%100;
        d=num%1000;
        for(j=0;j<=9;++j)
        {
            if(prime[a+j]==0&&(a+j)!=num&&(a+j)>1000)
                insert(num,a+j,1);
            if(prime[b+10*j]==0&&(b+10*j)!=num&&(b+10*j)>1000)
                insert(num,b+10*j,1);
            if(prime[c+100*j]==0&&(c+100*j)!=num&&(c+100*j)>1000)
                insert(num,c+100*j,1);
            if(prime[1000*j+d]==0&&(1000*j+d)!=num&&(1000*j+d)>1000)
                insert(num,1000*j+d,1);

        }


    }

    element *ptr;

    while(test--)
    { 
        scanf("%d%d",&s,&t);      
        memset(dist,-1,1000000);
        bfs(s,t);
        if(dist[t]==-1)
            printf("Impossible\n");
        else
            printf("%d\n",dist[t]);

    }

    return 0;
}
