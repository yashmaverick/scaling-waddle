#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
int visited[1000010],maxnode1,max;
node *arr[1000010];
void adjlist(int i,int j)
{
    node *temp;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=j;
    new_node->next=NULL;
    if(arr[i]==NULL)
    {
        arr[i]=new_node;
    }
    else
    {
        temp=arr[i];
        arr[i]=new_node;
        new_node->next=temp;
    }
}
void dfs(int vertex,int height)
{
       // int count;
   // count++;
    if(height>max)
    {
        max=height;
        maxnode1=vertex;
    }
    visited[vertex]=1;
    node *tempa;
    tempa=arr[vertex];
    while(tempa!=NULL)
    {
        if(visited[tempa->data]!=1)
        {
            dfs(tempa->data,height+1);
        }
        tempa=tempa->next;
    }
}

int main()
{
    int T,N,u,v,i,j,k,p1,p2;
    scanf("%d",&T);
    while(T--)
    {
        max=0;
        scanf("%d",&N);
        for(i=0;i<=N;i++)
            arr[i]=NULL;
        for(i=1;i<=N-1;i++)
        {
            scanf("%d %d",&u,&v);
            adjlist(u,v);
            adjlist(v,u);
        }
        for(i=0;i<=N;i++)
            visited[i]=0;
      //  count=0;
      max=0;
        dfs(1,0);
        for(i=0;i<=N;i++)
            visited[i]=0;
        max=0;
    //    count=0;
        dfs(maxnode1,0);
        printf("%d\n",max+1);
    }




    return 0;
}
