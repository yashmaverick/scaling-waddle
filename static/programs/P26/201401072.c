#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int prime[10000];
int vis[10000];
typedef struct node
{
    short a,b,c,d;
}node;

typedef struct pnode
{
    int val;
    struct pnode*next;
}pnode;

int conv(node*a,int pos,int v)
{
    int val;
    if(pos==-1)
        val=(a->a*1000+a->b*100+a->c*10+a->d);
    else if(pos==0)
        val=(a->a*1000+a->b*100+a->c*10+v);
    else if(pos==1)
        val=(a->a*1000+a->b*100+a->d+10*v);
    else if(pos==2)
        val=(a->a*1000+a->c*10+a->d+100*v);
    else if(pos==3)
        val=(a->b*100+a->c*10+a->d+1000*v);

    return val;
}

node *newnode(int a)
{
    node*new=(node*)malloc(sizeof(node));
    new->a=a/1000;new->b=a/100%10;new->c=a/10%10;new->d=a%10;
    return new;
}



void seive()
{
    prime[0]=prime[1]=0;
    int i;
    for(i=2;i<10000;i++)
    {
        int j;
        for(j=2*i;j<10000;j+=i)
        {
            prime[j]=0;
        }

    }
}
pnode *parr[100000];

pnode* newpnode(int v)
{
    pnode *a=(pnode*)malloc(sizeof(pnode));
    a->val=v;
    a->next=NULL;
    return a;
}

void insert(pnode *a[],int  x,int y)
{
    pnode*head=a[x];
    pnode *old=head->next;
    head->next=newpnode(y);
    head->next->next=old;
}


int graph()
{
    int i;
    for(i=1000;i<10000;i++)
        if(prime[i])
    {
        node *k=newnode(i);
        parr[i]=newpnode(i);
        int j,l;
        for(j=0;j<4;j++)
            for(l=0;l<10;l++)
            {
                if(j<3||l!=0)
                {
                    int check=conv(k,j,l);
                    if(prime[check])
                    {
                        insert(parr,i,check);
                    }
                }
            }
    }
}

int bfs(int a,int b)
{
    if(a==b)
        return 0;
    int q[100000][2];
    int head=0,tail=0;
    q[tail][0]=a;
    q[tail][1]=0;
    while(head<=tail)
    {
        int n=q[head][0];
        int lev=q[head++][1];
        pnode *top=parr[n];
        while(top->next!=NULL)
        {
            top=top->next;
            if(!vis[top->val])
            {
                if(top->val==b)
                    return lev+1;
                vis[top->val]=1;
                q[++tail][0]=top->val;
                q[tail][1]=lev+1;
            }
        }

    }
    return -1;
}

int print()
{
    int i;
    for(i=1000;i<10000;i++)
    {
        if(prime[i])
        {
            pnode *head=parr[i];
            while(head->next!=NULL)
            {
                head=head->next;
                printf("%d ",head->val);
            }
            printf("\n");
        }
    }
}

int main()
{
    memset(prime,1,sizeof(prime));
    seive();
    graph();
    //print();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        memset(vis,0,sizeof(vis));
        int res=bfs(m,n);
        if(res>=0)
            printf("%d\n",res);
        else {
            printf("Impossible\n");
        }
    }
    return 0;
}
