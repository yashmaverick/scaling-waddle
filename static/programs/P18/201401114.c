#include<stdlib.h>
#include<string.h>
#include<stdio.h>
typedef int ll;
typedef struct node
{
        ll val;
        struct node*next;
}node;
node* graph[1001], *revgraph[1001];
ll visited[1001], count,check, stack[1001], top;
node* insert(int v, node*root)
{
        node*temp=malloc(sizeof(node));
        temp->val=v;
        temp->next=root;
        return temp;
}
void gdfs(ll u)
{
        count++;
        check++;
        visited[u]=1;
        node*ptr=graph[u];
        while(ptr!=NULL)
        {
                if(visited[ptr->val]==0)
                        gdfs(ptr->val);
                ptr=ptr->next;
        }
        return;
}
void explore(ll u)
{
        visited[u]=1;
        node*ptr=revgraph[u];
        while(ptr!=NULL)
        {
                if(visited[ptr->val]==0)
                        explore(ptr->val);
                ptr=ptr->next;
        }
        stack[++top]=u;
        return;
}
void revdfs(ll N)
{
        ll i;
        memset(visited, 0, sizeof(visited));
        for(i=1; i<=N; i++)
        {
                if(visited[i]==0)
                        explore(i);
        }

}
int main()
{
        ll N, T,i, M, j, x;
        scanf("%d", &T);
        while(T--)
        {
                top=-1;
                scanf("%d", &N);
                memset(stack, 0, sizeof(stack));
                for(i=1; i<=N; i++)
                {
                       // printf("Player %d: ", i);
                        scanf("%d", &M);
                        for(j=0; j<M;j++)
                        {
                                scanf("%d", &x);
                                revgraph[i]=insert(x, revgraph[i]);
                                graph[x]=insert(i, graph[x]);
                        }
                }
                revdfs(N);
                memset(visited, 0, sizeof(visited));
                int insource;
                while(top>=0)
                {
                        if(visited[stack[top]]==0)
                        {
                                count=0;
                                gdfs(stack[top]);
                                insource=stack[top];
                        }
                        top--;
                }
                //printf("insource : %d\n",insource);
                memset(visited, 0, sizeof(visited));
                int ans=count;
                check=0;
                count=0;
                gdfs(insource);
                //printf("check : %d\n",check);
                //printf("N : %d\n",N);
                if(check!=N)
                        printf("0\n");
                else
                        printf("%d\n", ans);
                for(i=0; i<=N; i++)
                {
                        revgraph[i]=NULL;
                        graph[i]=NULL;
                }

        }
        return 0;
}




        


