#include <stdio.h>
#include <stdlib.h>
 
int visited[100001] = {0};
int in[100001], arr[100001];

typedef struct linklist{

    int value;
    struct linklist * next;
}linklist;

linklist* insert(int v, linklist* root)
{
    linklist *temp = (linklist *)malloc(sizeof(linklist));
    temp->value = v;
    temp->next = root;
    return temp;
}

linklist *graph1[100001], *graph2[100001];
int stack[1000001], end = 0;

void dfs1(int source)
{
    visited[source] = 1;
    linklist *temp = graph1[source];
    
    while(temp != NULL)
    {
        if(visited[temp->value] == 0)
            dfs1(temp->value);

        temp = temp->next;
    }

    stack[end] = source;
	end++;
}

void dfs2(int source, int count)
{
    visited[source] = 0;
    arr[source] = count;
    linklist *temp = graph2[source];
    
    while(temp != NULL)
    {
        if(visited[temp->value])
            dfs2(temp->value, count);
        temp = temp->next;
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        
        for(i = 0;i <= n;i++)
        {
            visited[i] = 0;
            in[i] = 0;
            graph1[i] = graph2[i] = NULL;
        }

        for(i = 1;i <= n;i++)
        {
            int m,u;
            scanf("%d",&m);
            int j;
            for(j = 0;j < m;j++)
            {
                scanf("%d", &u);
                graph1[u] = insert(i, graph1[u]);
                graph2[i] = insert(u, graph2[i]);
            }
        }
        
        end = 0;
        for(i = 1;i <= n;i++)
        {
            if(visited[i] == 0)
                dfs1(i);
        }
        
        int count = 0, final_count;
    
        for(i = end;i >= 0;i--)
        {
            if(visited[stack[i]] == 1)
                dfs2(stack[i], count++);
        }

        for(i = 1;i <= n;i++)
        {
            linklist *temp = graph1[i];
            while(temp)
            {
                if(arr[i] != arr[temp->value])
                    in[arr[temp->value]] += 1;
                temp = temp->next;
            }
        }

        final_count = 0;
        for(i = 0;i <= count-1; i++)
        {
            if(in[i] == 0)
                final_count++;
        }

        if(final_count > 1)
            printf("0\n");
        else{
            final_count = 0;
            for(i = 1;i <= n;i++)
            {
                if(in[arr[i]]==0)
                    final_count++;
            }
            printf("%d\n", final_count);
        }
    }
    return 0;
} 