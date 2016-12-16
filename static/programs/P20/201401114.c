#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long int lint;
typedef struct node
{
        lint val;
        struct node*next;
}node;
node*arr[1000009];
lint visited[1000009], distance[1000009];
node* max_node;
lint max=0;

node*insert(lint x, node*root)
{
        node*temp=malloc(sizeof(node));
        temp->val=x;
        temp->next=root;
        return temp;
}

void dfs(lint parent)
{
        node*ptr=arr[parent];
        //printf("For parent %d\n", parent);
        lint dist=distance[parent];
        visited[parent]=1;
        while(ptr!=NULL)
        {
                if(visited[ptr->val]==0)
                {
                        distance[ptr->val]=distance[parent]+1;
                        //printf("Visted child %d \n", ptr->val);
                        if(distance[ptr->val]>max)
                        {
                                max=distance[ptr->val];
                                max_node=ptr;
                        }                        
                        visited[ptr->val]=1;
                        dfs(ptr->val);
                }
                        ptr=ptr->next;
                
        }
       // printf("Exiting parent %d\n", parent);
}
void adjlist(lint N)
{
        lint i;
        for(i=1; i<=N; i++)
        {
                printf("For %lld: ", i);
                if(visited[i]==1)
                {
                        node*ptr=arr[i];
                        while(ptr!=NULL)
                        {
                                printf("%lld ", ptr->val);
                                ptr=ptr->next;
                        }
                        printf("\n");
                }
        }
}


int main()
{
        lint T, N, u,v,i;
        scanf("%lld", &T);
        while(T--)
        {
                max=0;
                
                scanf("%lld", &N);
                for(i=1; i<=N-1; i++)
                {
                        scanf("%lld %lld", &u, &v);
                        arr[u]=insert(v, arr[u]);
                        arr[v]=insert(u, arr[v]);
                }
               
                memset(visited, 0, sizeof(visited));
                memset(distance, 0, sizeof(distance));
                
                dfs(u);
                memset(distance, 0, sizeof(distance));
                memset(visited, 0, sizeof(visited));
                max=0;

                dfs(max_node->val);
                printf("%lld\n", max+1);
                if(T>=1)
                {
                        for(i=1; i<=N; i++)
                                arr[i]=NULL;
                }
        }
        return 0;
}



