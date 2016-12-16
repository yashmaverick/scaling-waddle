#include<stdio.h>
#include<stdlib.h>

struct node{
    int vertex;
    struct node *next;
};

int natural[10005],prime[2000],p=0,cost=999999;
struct node *graph[100000];
int matrix[2000][2000]={0};
int prime_to_index[10000]={0};

struct node* insert(struct node *root, int prime)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->vertex=prime;

    if(root==NULL)
        temp->next=NULL;
    else
        temp->next=root;
    return temp;
}


void check_and_insert(int prime)
{
    int d1,d2,d3,d4,NEW,i,j;
    d4=prime%10;
    d3=(prime/10)%10;
    d2=(prime/100)%10;
    d1=(prime/1000)%10;

    // 'd1' + 'd2' + 'd3' + 'd4'

    for(i=0;i<4;i++)
    {
        int test[]={d1,d2,d3,d4};
        for(j=0;j<=9;j++)
        {
            test[i]=j;
            NEW = test[3] + 10*test[2] + 100*test[1] + 1000*test[0];
            if(NEW>1000 && NEW<=9999 && natural[NEW]!=0 && NEW!=prime && matrix[prime_to_index[prime]][prime_to_index[NEW]]!=1)
            {
                graph[prime]=insert(graph[prime],NEW);
                matrix[prime_to_index[prime]][prime_to_index[NEW]]=1;
                //graph[NEW]=insert(graph[NEW],prime);
            }
        }

    }
}

void dfs(int vertex, int visited[], int dest, int depth)
{
    if(vertex==dest)
    {
//        printf("############# Cost = %d\n",depth);
        if(cost>depth)
            cost=depth;
        return;
    }
    printf("Vertex = %d\n",vertex);
    visited[prime_to_index[vertex]]=1;
    struct node *temp=graph[vertex];
    while(temp!=NULL)
    {
        if(visited[prime_to_index[temp->vertex]]!=1)
            dfs(temp->vertex,visited, dest, depth+1);
        temp=temp->next;
    }
}



int bfs_array[1000005];
int end=0,start=0;

int check[1000005]={0};
int depth=0;

void bfs(struct node* graph[], int dest, int visited[])
{
    if (start==end)
        return;

    int elem,flag=0;

    //print_que();
    while(bfs_array[start]!=-1 && start!=end)
    {
        elem=bfs_array[start];
        if(elem==dest)
        {
            cost=depth;
  //          printf("Depth = %d\n",cost);
            return;
        }
        start++;
        struct node *temp=graph[elem];
        while(temp!=NULL) 
        {
            if (visited[prime_to_index[temp->vertex]]==0)
            {
                flag=1;
                bfs_array[end++]=temp->vertex;
                visited[prime_to_index[temp->vertex]]=1;
            }
            temp=temp->next;
        }
        //      print_que();
    }

    start++;
    if (flag==1)
        bfs_array[end++]=-1;
    depth++;
    //print_que();
    bfs(graph, dest, visited);
}


void print_ad_list()
{
    int g=0;
    struct node *temp;
    for(g=0;g<p;g++)
    {
        temp=graph[prime[g]];
        printf("%d -> ",prime[g]);
        while(temp!=NULL)
        {
            printf("%d, ",temp->vertex);
            temp=temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int i=0,j=0;
    for(i=0;i<=10003;i++)
        natural[i]=i;

    natural[1]=0;
    for(i=2;i<10000;i=i+1)
    {
        if(natural[i]!=0)
        {
            if(natural[i]>1000 && natural[i]<=9999)
            {
                prime[p++]=natural[i];
                prime_to_index[natural[i]]=p-1;
            }
            for(j=i*i;j<10000;j=j+i)
                natural[j]=0;
        }
    }

    for(i=0;i<p;i++)
        check_and_insert(prime[i]);
//    print_ad_list();

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int A,B;
        int visited[2000]={0};
        scanf("%d %d",&A ,&B);
        //dfs(A,visited,B,0);

        bfs_array[0]=A;
        bfs_array[1]=-1;
        visited[prime_to_index[A]]=1;
        depth=0;start=0;end=2;
        cost=999999;
        bfs(graph, B, visited);
        if(cost == 999999)
            printf("Impossible\n");
        else
            printf("%d\n",cost);
    }
    return 0;
}
