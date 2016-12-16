#include<stdio.h>
#include<stdlib.h>
#define MAX 1000001

typedef struct b{
    int v;
    struct b* next;
}node;

node A[MAX];
int visit[MAX],max,no;

void insert(int i,int j)
{
    node*point,*new,*nxt;
    new=malloc(sizeof(node));
    new->v=j;
    new->next=NULL;
    point=&A[i];
    nxt=point->next;
    point->next=new;
    new->next=nxt;
}

void dfs(int root,int count)
{
    if(count>max)
    {
        max=count;
        no=root;
    }
    node *temp=&A[root];
    if(visit[root]==0)
    {
        visit[root]=1;
        temp=temp->next;
        while(temp!=NULL)
        {
            dfs(temp->v,count+1);
            temp=temp->next;
        }
    }
}
int main()
{
    int t,N,i,j,root,n;
    node *te;
    scanf("%d",&t);
    while(t--)
    {
        max=0;
        no=0;
        for(i=1;i<=MAX;i++)
        {
            te=&A[i];
            visit[i]=0;
            te->next=NULL;
        }
        scanf("%d",&N);
        n=N;
        if(N==1)
        {
            printf("1\n");
            continue;
        }
        scanf("%d%d",&i,&j);
        insert(i,j);
        insert(j,i);
        root=i;
        N-=2;
        while(N--)
        {
            scanf("%d%d",&i,&j);
            insert(i,j);
            insert(j,i);
        }
        dfs(root,0);
        for(i=0;i<MAX;i++)
        {
            visit[i]=0;
        }
        max=0;
        dfs(no,0);
        if(n>2)
        {
            max+=1;
        }
        printf("%d\n",max);
    } 
    return 0;
}
