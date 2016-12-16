#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node* next;
}node;
int visited[1010],count;
node *arr[1010],*arr2[1010];
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
void adjlist2(int i,int j)
{
    node *temp;
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=j;
    new_node->next=NULL;
    if(arr2[i]==NULL)
    {
        arr2[i]=new_node;
    }
    else
    {
        temp=arr2[i];
        arr2[i]=new_node;
        new_node->next=temp;
    }
}
void dfs(int vertex)
{
    count++;
    visited[vertex]=1;
    node *tempa;                 //=(node*)malloc(sizeof(node));
    tempa=arr[vertex];
//    temp=temp->next;
    while(tempa!=NULL)
    {
//        printf("td-%d\n",tempa->data);
       // printf("gferger");
        if(visited[tempa->data]!=1)
        {
   // printf("%d\n",tempa->data);
            dfs(tempa->data);
        }
        tempa=tempa->next;
    }
    //return;
}
void dfs2(int vertex)
{
    count++;
    visited[vertex]=1;
    node *tempa;                 //=(node*)malloc(sizeof(node));
    tempa=arr2[vertex];
//    temp=temp->next;
    while(tempa!=NULL)
    {
//        printf("td-%d\n",tempa->data);
       // printf("gferger");
        if(visited[tempa->data]!=1)
        {
   // printf("%d\n",tempa->data);
            dfs2(tempa->data);
        }
        tempa=tempa->next;
    }
    //return;
}
int main()
{
    int T,n,nofwar,a,b,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        int p=0;
        count=0;
        node *temp=(node*)malloc(sizeof(node));
        temp->next=NULL;
        scanf("%d",&n);

        for(i=0;i<=n;i++)
        {
            arr[i]=NULL;
            arr2[i]=NULL;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&nofwar);
            for(j=0;j<nofwar;j++)
            {
                scanf("%d",&a);
                adjlist(a,i);
                adjlist2(i,a);
            }
        }
        for(i=1;i<=n;i++)
        {
            count=0;
        for(j=0;j<=n;j++)
            visited[j]=0;
            dfs(i);
            //printf("%d\n",count);
            if(count==n)
            {
                count=0;
        for(j=0;j<=n;j++)
            visited[j]=0;
                dfs2(i);
            
                break; 
               
            }
        }
/*        for(i=1;i<=n;i++)    //printing the adjacency list
        {
            temp->next=arr[i];
//            printf("%d-->",i);
            while(temp->next!=NULL)
            {
                printf("%d ",temp->next->data);
                temp=temp->next;
            }
            printf("\n");
        }*/
        if(i>n)
            printf("0\n");
        else
            printf("%d\n",count);
    }
    return 0;
}
