#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct adj
{
    int val;
    struct adj *link;
}adj;

adj *list[1000001];

int n,m,visited[1000001];
int max_dist;
int farthest_node;

void dfs(adj *node,int dist,int m)
{
    //int start=node->val;
    adj *temp;
    //printf("%d-> ",node->val);
    visited[node->val]=1; // setting visited value to 'TRUE'
    //intime[node->val]=time;
    // //printf("%d-> ",v);

    temp=list[node->val];

    while(temp!=NULL)
    {
        if(visited[temp->val]==0 && m!=n) // if the node is unvisted then perform dfs on it and its adjadcent nodes/vertices
        {
            //time++;
            if(dist>max_dist)
            {
                farthest_node=temp->val;
                max_dist=dist;
            }
            dfs(temp,dist+1,m+1);
        }

        //outtime[temp->val]=time;
        // //time++;
        temp=temp->link;
    }

    //outtime[start]=time; // to set final outtime for starting/root node
    /*
    if(dist>=max_dist)
    {
        farthest_node=node->val;
        //max_dist=dist;
    }
    */

}


int main()
{
    int t,n,v1,v2,i;

    scanf("%d",&t);

    while(t-->0)
    {
        max_dist=0;
        //farthest_node=1;

        scanf("%d",&n);

        memset(visited,0,1000000);

        for(i=1;i<=n;i++)
        {
            list[i]=(adj *)malloc(sizeof(adj));
            list[i]->link=NULL;
        }
        adj *temp;

        //adj *list;
        //list=(adj *)malloc(sizeof(adj));


        for(i=1;i<n;i++)
        {
            scanf("%d %d",&v1,&v2);

            list[v1]->val=v1;
            temp=list[v1];
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=(adj *)malloc(sizeof(adj));
            temp->link->val=v2;
            temp->link->link=NULL;

            list[v2]->val=v2;
            temp=list[v2];
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=(adj *)malloc(sizeof(adj));
            temp->link->val=v1;
            temp->link->link=NULL;
        }

        //dfs(list[1],0,1);
        //printf("farthest node = %d\n",farthest_node);
        //memset(visited,0,1000000);
        //dfs(list[farthest_node],0);

        // printing adjacency list
        /*
        for(i=1;i<=n;i++)
        {   
            temp=list[i];
            while(temp!=NULL)
            {
                printf("%d ",temp->val);
                temp=temp->link;
            }
            printf("\n");

        }
        */

        if(n>=3)
        {
            dfs(list[1],0,1);
            //printf("\nfarthest node = %d\n",farthest_node);
            memset(visited,0,1000000);
            dfs(list[farthest_node],2,1);

            //printf("Longest path = %d\n",max_dist+1);
            printf("%d\n",max_dist);
        }
        else if(n==2)
        {
            printf("2\n");
        }
        else if(n==1)
        {
            printf("1\n");
        }
    }

    return 0;
}
