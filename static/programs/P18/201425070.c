// #Authored : Jaipal Singh Goud
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct AdjListNode
{
    int data;
    struct AdjListNode *next;
}node;

typedef struct AdjList
{
    node *head;
}list;

typedef struct GG
{
    int size;
    list *array;
}Graph;

node *makeNode(int x)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = x;
    new->next = NULL;
    return new;
}

Graph *makeGraph(int vertices)
{
    Graph *graph;
    graph = (Graph *)malloc(sizeof(Graph)); 
    graph->size = vertices;
    graph->array = (list *)malloc(sizeof(list)*(vertices+10));

    int i;
    for(i=0;i<=vertices;i++)
        graph->array[i].head = NULL;

    return graph;
}

void addEdge(Graph *graph , int a , int b)
{
    node *new = makeNode(b);
    new->next = graph->array[a].head;
    graph->array[a].head = new;
}

list *create_Adj_List(int size)
{
    list *new;
    new = (list *)malloc(sizeof(list)*size);
    return new;
}

int visited[100000];
int stack[100000];
int head;
int realms;
int viewcount = 0;

void recur_dfs(Graph *graph , int v)
{
    viewcount++;
    node *new;
    visited[v] = 1;
    new = graph->array[v].head;

    while(new != NULL)
    {
        if(visited[new->data] == 0)
            recur_dfs(graph , new->data);
        new = new->next;
    }
}
void printAdjList(Graph *graph , int n)
{
    int i;
    node *temp;
    for(i = 1;i <= n;i++)
    {
        temp = graph->array[i].head;
        while(temp != NULL)
        {
            printf("%d - ",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void initializeVisited(int n)
{
    int i;
    for(i = 0;i <= n;i++)
        visited[i] = 0;
}

int main()
{
    int n , x , m , i , j , k , test , counter;
    scanf("%d",&test);

    while(test--)
    {
        scanf("%d",&n);
        Graph *graph = makeGraph(n+1);
        Graph *revgraph = makeGraph(n+1);
        for(i = 1;i <= n;i++)
        {
            scanf("%d",&m);
            for(j = 0;j < m;j++)
            {
                scanf("%d",&x);
                addEdge(graph , x , i);
                addEdge(revgraph , i , x);
            }
        }

        //printAdjList(graph , n);

        for(i = 1 ;i <= n;i++)
        {
            viewcount = 0;
            initializeVisited(n);
            recur_dfs(graph , i);
            if(viewcount == n)
                break;
        }
        //printf("I:%d\n",i);

        initializeVisited(n);
        viewcount = 0;
        if(i<=n)
        {
          recur_dfs(revgraph , i);
          printf("%d\n",viewcount);
        }
        else
            printf("%d\n",0);
    }   
    return 0;
}
