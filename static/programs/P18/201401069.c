#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000001

typedef struct b{
    int v;
    struct b* next;
}node;

node A1[MAX],A2[MAX];
long long int visit[MAX],adj[MAX],visited,ans;

void push();
long long int pop();
void adj_list(long long int n,long long int tu);

void insert(long long int i,long long int j, long long int a)
{
    node*point,*new,*nxt;
    new=malloc(sizeof(node));
    new->v=j;
    new->next=NULL;
    if(a==1)
        point=&A1[i];
    else
        point=&A2[i];
    nxt=point->next;
    point->next=new;
    new->next=nxt;
}

void dfs1(long long int root)
{ 
//    printf("%d v %d\n",root,visited);
    node *temp=&A1[root];
    if(visit[root]==0)
    {
        visit[root]=1;
        temp=temp->next;
        visited++;
        while(temp!=NULL)
        {
            dfs1(temp->v);
            temp=temp->next;
        }
    }
}

void dfs2(long long int root)
{ 
 //   printf("%d ",root);
    node *temp=&A2[root];
//    printf("visit[root]=%d",visit[root]);
    if(visit[root]==0)
    {
        ans++;
        visit[root]=1;
        temp=temp->next;
        visited++;
        while(temp!=NULL)
        {
            dfs2(temp->v);
            temp=temp->next;
        }
    }
 //   printf("\n");
}

int main()
{
    long long int t,N,i,M,j,loop;
    scanf("%lld",&t);
    while(t--)
    {
        for(i=0;i<MAX;i++)
        {
            visit[i]=0;
            adj[i]=0;
            A1[i].next=NULL;      
            A2[i].next=NULL;      
            visited=0;
        }
        scanf("%lld",&N);
        for(loop=1;loop<=N;loop++)
        {
            scanf("%lld",&M);
            while(M--)
            {
                scanf("%lld",&j);
                insert(j,loop,1);
                insert(loop,j,2);
            }
        }

        for(i=1;i<=N;i++)
        {
            node *temp=&A1[i];
            temp=temp->next;
            /*  printf("i=%d\n",i);
                while(temp!=NULL)
                {
                printf("A1-%d",temp->v);
                temp=temp->next;
                }
                printf("\n");
                */
        }
        for(loop=1;loop<=N;loop++)
        {
            for(i=0;i<=N;i++)
                visit[i]=0;
            visited=0;
            //printf("dfs1\n");
            dfs1(loop);
            for(i=0;i<=N;i++)
                visit[i]=0;
            if(visited==N)
            {
                visited=0;
                ans=0;
                for(i=0;i<=N;i++)
                {
                    visit[i]=0;
             //       printf("%d",visit[i]);
                }
               // printf("dfs2\n");
                dfs2(loop);
                printf("%lld\n",ans);
                break;
            }
        }
    }
    return 0;
}
