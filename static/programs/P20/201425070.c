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

typedef struct q
{
    int head;
    int tail;
    int var[1000009];
}Queue;

void enqueue(Queue *queue , int x)
{
    queue->head = queue->head + 1;
    queue->var[queue->head] = x;
}

int dequeue(Queue *queue)
{
    if(queue->head < queue->tail)
        return 0;
    if(queue->head == -1)
        return 0;
    else
        return queue->var[queue->tail++];
}

Queue *makeQ()
{
    Queue *new;
    new = (Queue *)malloc(sizeof(Queue));
    new->head = -1;
    new->tail = 0;
    return new;
}

node *makeNode(int data)
{
    node *new;
    new = (node *)malloc(sizeof(node));
    new->data = data;
    new->next = NULL;
    return new;
}

Graph *makeGraph(int v)
{
    Graph *graph;
    graph = (Graph *)malloc(sizeof(Graph));
    graph->size = v;
    graph->array = (list *)malloc(sizeof(list)*v);

    int i;
    for(i=0;i<v;i++)
        graph->array[i].head = NULL;

    return graph;
}

void insert(Graph *graph , int src , int dest)
{
    node *new = makeNode(dest);
    new->next = graph->array[src].head;
    graph->array[src].head = new;

    new = makeNode(src);
    new->next = graph->array[dest].head;
    graph->array[dest].head = new;
}

int stack[1000005];
int top = 0;
int visited[1000056];

void push(int val)
{
    top = top + 1;
    stack[top] = val;
}

int pop()
{
    if(top == -1) 
        return 0;
    return stack[top--];
}

void printAdjList(Graph *graph , int n)
{
    int i;
    node *temp;
    for(i = 0;i < n;i++)
    {   
        temp = graph->array[i].head;
        printf("%d :",i+1);
        while(temp != NULL)
        {
            printf("%d - ",temp->data+1);
            temp = temp->next;
        }
        printf("\n");
    }  
    printf("Leaving\n");
}

int deepestNode(Graph *graph , int choice ,int vv){
    int v;
    int visited[1000055];
    int i;
    int max , height;
    max = height = 0;

    for(i=0;i<1000052;i++)
        visited[i] = 0;
    node *temp;

    Queue *q;
    q = makeQ();

    enqueue(q,vv);
    visited[vv] = 1;

    while(q->head >= q->tail)
    {
        v = dequeue(q);
        temp = graph->array[v].head;
        while(temp != NULL)
        {
            if(visited[temp->data] == 0)
            {
                visited[temp->data] = 1;
                enqueue(q , temp->data);
            }
            temp = temp->next;
        }
    }
    if(choice == 1)
        return q->var[q->head];
    return height;
}

int iter_def(Graph *graph , int v)
{
    int visited[1000055];
    int i;
    int height , max;
    height = max = 0;
    height = 1;
    node *temp;

    for(i=0;i<1000052;i++)
        visited[i] = 0;

    top = -1;
    push(v);
    while( top != -1)
    {
        v = pop();
        printf("%d",v);
        if (visited[v] == 0)
        {
            visited[v] = 1;
            height++;
            temp = graph->array[v].head;
            while(temp != NULL)
            {
                push(temp->data);
            }
        }
        if(height > max)
            max = height;
        temp = temp->next;
    }
    return max;
}

int maxl ;

void recur_dfs(Graph *graph , int v , int level)
{

    node *new;
    visited[v] = 1;
    if(level > maxl)
        maxl = level;
    new = graph->array[v].head;

    while(new != NULL)
    {
        if(visited[new->data] == 0)
        {
            recur_dfs(graph , new->data ,level+1);
        //    printf("Data :%d Level : %d\n",new->data+1,level);
        }
        new = new->next;
    
    }
}

int main() // Z + O
{
    int i,j,k,m,n,test;
    int x , y , max;
    Graph *graph;
    int far;
    scanf("%d",&test);
    while(test--)
    {
        maxl = 0;
        scanf("%d",&n);
        graph = makeGraph(n+1);
        for(i=0;i<n-1;i++)
        {
            scanf("%d%d",&x,&y);
            insert(graph , x-1 , y-1);        // All nodes inserted are node - 1
        }
        int v = deepestNode(graph,1,0);
        for(i=0;i<=n;i++)
            visited[i] = 0;
        recur_dfs(graph , v , 1);
        if( n == 0 )
            printf("0\n");
        //else if( n == 2)
          //  printf("1\n");
        else
            printf("%d\n",maxl);
    }
    return 0;
}
