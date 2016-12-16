#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*concepts covered:
 * Kosaraju's algorithm to find ssc's
 * implementation of directed graph
 */


#define size 5000
//1000 vertices at max

int adj[size][size],graph2[size][size];
int visited[size];
int stack[size];
int in[size];
int top;
int v,e;
int compon;
int comp[size];
void addedge(int src,int dest,int graph[][size])
{
    graph[src][dest]=1;
}
void transpose( int orig[][size],int transposed[][size])
{
    
    int i,j;
    for(i=1;i<=v;++i)
    {
        for(j=1;j<=v;++j)
            if(orig[i][j]!=0)
            {
//                printf("%d--%d, ",i+1,j+1);
                transposed[j][i]=orig[i][j];
            }
  //      printf("\n");
    }

    // printf("---------\n");
    /*for(i=0;i<v;++i)
    {
        for(j=0;j<v;++j)
            if(transposed[i][j]!=0)
            {
                printf("%d--%d, ",i+1,j+1);
            }
        printf("\n");
    }*/
}
void dfs(int i,int adjy[][size],int c)
{
    int j;
    visited[i]=1;
    comp[i]=c;

    for(j=1;j<=v;++j)
    {
        if(adjy[i][j]!=0&&visited[j]==0)
        {
//            printf("%d ",j);
            dfs(j,adjy,c);
        }

  //  printf("\n");
    
    }



}
void fill(int i,int visited[size],int adjy[][size],int stack[size])
{
    int j;
    visited[i]=1;
//    printf("%d ",i);
    for(j=1;j<=v;++j)
    {
        if(adjy[i][j]!=0&&visited[j]==0)
        fill(j,visited,adjy,stack);
    }
    stack[++top]=i;

}
void getSC()
{
    int i,bp;
    
    memset(visited,0,size);

    top=-1;

    for(i=1;i<=v;++i)
        if(visited[i]==0)//vertex with non zero degree
        {
            //printf("%d ",i);
            fill(i,visited,graph2,stack);
        }

    //printf("top:%d\n",top);


    compon=0;
    memset(visited,0,size);//for second dfs
    // Do DFS for reversed graph starting from first vertex.
    // Staring Vertex must be same starting point of first DFS
    while(top!=-1) 
    {
        int vertex=stack[top--];
        if(visited[vertex]==0)
        {
            //printf("top:%d\n",vertex);
            dfs(vertex,adj,compon++);
           // printf("\n");
        }

    }

//    for(i=1;i<=v;++i)
  //   printf("%d\n",comp[i]);
    
    int lim=compon;
    int j;
    for(i=1;i<=v;++i)
    {
        for(j=1;j<=v;++j)
        {
            if(graph2[i][j]!=0&&comp[i]!=comp[j])
            { 
                in[comp[j]]+=1;
            }
        }
    }
    int count=0;
    for(i=0;i<lim;++i)
        if(in[i]==0)
            ++count;
    if(count>1)
    {  printf( "0\n" );
    }
    else
    {
        count=0;
        for(i=1;i<=v;++i)
        if(in[comp[i]]==0)
            ++count;

           printf( "%d\n",count);
    

    }

}
int main()
{
    int i,src,dest,j;
    int n,test,m;
    
    scanf("%d",&test);
    while(test--)
    {
    scanf("%d",&n);
    memset(adj,0,size*size);
    memset(graph2,0,size*size);
    memset(visited,0,size);
    memset(stack,0,size);
    v=n;
    e=0;
    top=-1;
    for(i=1;i<=n;++i)
    {
        scanf("%d",&m);
        for(j=1;j<=m;++j)
        {
            scanf("%d",&dest);
            addedge(i,dest,adj);
            addedge(dest,i,graph2);
            e++;
        }
    }
    memset(in,0,size);
    getSC();
    //printf("-------\n");
    }
    return 0;
}
