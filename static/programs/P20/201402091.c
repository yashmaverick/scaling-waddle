#include<stdio.h>
#include<stdlib.h>
int h,temp;
typedef struct node
{
    int dest;
    struct node* next;
}node;
typedef struct vertex
{   
    int visited;
    struct node* head;
}vertex;
typedef struct graph
{
    int v;
    struct vertex* list;
}graph;
node* newnode(int dest)
{
    node* new=(node*)malloc(sizeof(node));
    new->dest=dest;
    new->next=NULL;
    return new;
}
graph* create(int v)
{   int i;
    graph* g=(graph*)malloc(sizeof(graph));
    g->v=v;
    g->list=(vertex*)malloc((v+1)*sizeof(vertex));
    for(i=1;i<=v;i++)
    {
        g->list[i].head=NULL;
        g->list[i].visited=0;
    }
    return g;
}
void addedge(graph* g,int s,int d)
{
    node* nv=newnode(d);
    nv->next=g->list[s].head;
    g->list[s].head=nv;
    nv=newnode(s);
    nv->next=g->list[d].head;
    g->list[d].head=nv;
}
/*void printgraph(graph* g)
{   int i;
    for(i=1;i<=g->v;i++)
    {
        node* temp=g->list[i].head;
        printf("Adjacent vertices of %d are\n",i);
        while(temp)
        {
            printf("%d ",temp->dest);
            temp=temp->next;
        }
        printf("\n");
    }
}*/
void dfs(graph* g,int v,int k)
{   
    if(k>h)
    {
        h=k;
        temp=v;
    }
    g->list[v].visited=1;
    node* temp=g->list[v].head;
    while(temp)
    {
        if(g->list[temp->dest].visited==0)
        {
            dfs(g,temp->dest,k+1);
        }
        temp=temp->next;
    }
}
int main()
{
    int t,v1,v2,ver,v;
    scanf("%d",&t);
    while(t--)
    {   
        h=1;
        int i;
        scanf("%d",&ver);
        graph* g=create(ver);
        for(i=1;i<ver;i++)
        {   
            scanf("%d%d",&v1,&v2);
            addedge(g,v1,v2);
        }
//    printgraph(g);
    dfs(g,1,1);
  //  printf("\n");
    for(i=1;i<=g->v;i++)
        g->list[i].visited=0;
    dfs(g,temp,1);
    //printf("\n");
    printf("%d\n",h);
    }
    return 0;
}

