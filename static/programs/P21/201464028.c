#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#define s(s) scanf("%s",s)
typedef struct info
{
    int d;
    int v;
}info;
info heap[100001];
typedef struct node
{
    int v;
    int d;
    struct node *next;
}node;
int num,visit[100001];
long long int dis[1000001];
node *head[100001];
node *insert(node *head,int p,int t)
{
    if(head==NULL)
    {
        node *q;
        q=malloc(sizeof(node));
        q->next=NULL;
        q->v=p;
        q->d=t;
        head=q;
    }
    else
    {
        node *q;
        q=malloc(sizeof(node));
        q->v=p;
        q->d=t;
        q->next=head;
        head=q;
    }
    return head;
}
void insert1(int ver,int dist)
{num++;
    int temp=num;
    heap[num].d=dist;
    heap[num].v=ver;
    info q;
    while(heap[temp/2].d>heap[temp].d && temp>1)
    {
        q=heap[temp/2];
        heap[temp/2]=heap[temp];
        heap[temp]=q;
        temp/=2;
    }
}
info delete()
{
    info q=heap[1],r;
    heap[1]=heap[num];
    num--;
    int temp=1;
    while(temp*2<=num)
    {
        if(2*temp==num)
        {
            if(heap[temp].d>heap[2*temp].d)
            {
                r=heap[temp];
                heap[temp]=heap[2*temp];
                heap[2*temp]=r;
            }
            break;
        }
        if(heap[temp].d>heap[2*temp].d || heap[temp].d>heap[2*temp].d)
        {
            if(heap[2*temp].d>heap[2*temp+1].d)
            {
                r=heap[temp];
                heap[temp]=heap[2*temp+1];
                heap[2*temp+1]=r;
                temp=temp*2+1;
            }
            else
            {
                r=heap[temp];
                heap[temp]=heap[2*temp];
                heap[2*temp]=r;
                temp=temp*2;
            }
        }
        else
            break;
    }
    return q;
}
void dijstra(node *p,int current)
{
    dis[current]=0;
    insert1(current,0);
    info z;
    node *e,*y;
    int a,b,c,d;
    while(num!=0)
    {
        z=delete();
        a=z.v;
        b=z.d;
        e=head[a];
        y=head[a];
        if(visit[a]==0)
        {visit[a]=1;
            while(e!=NULL)
            {
                if(visit[e->v]==0)
                {if(dis[e->v]>(long long int)(dis[z.v]+e->d))
                    {
                        dis[e->v]=(long long int)dis[z.v]+e->d;
                        insert1(e->v,dis[e->v]);
                    }}
                e=e->next;
            }
        }
    }
}
int main()
{
    int i,j,k,l,t,b,c,n,nm,nmp,a,m;
    num=0;
    scanf("%d%d",&t,&n);
        for(i=1;i<=t;i++)
            head[i]=NULL;
        for(i=0;i<=t;i++)
            dis[i]=INT_MAX;
        memset(visit,0,sizeof(visit));

        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            head[a]=insert(head[a],b,c);
//            head[b]=insert(head[b],a,c);
        }
        scanf("%d%d",&nm,&m);
        dijstra(head[nm],nm);
       // printf("%d%d\n",nm,m);
        if(dis[m]<INT_MAX)
        {//printf("%d ",m);
            printf("%lld\n",dis[m]);}
        else
            printf("NO\n");
       // for(i=1;i<=120;i++)
           // printf("%d ",INT_MAX);
   //
    
    return 0;
}

