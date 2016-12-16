#include<stdio.h>


int max_nodes_reached=0;
void dfs(int ver, int pointer[], int visited[], int arr[][1008])
{
    visited[ver]=1;
    //max_nodes_reached = (max_nodes_reached < no_of_vertices_reached)?no_of_vertices_reached:max_nodes_reached;
    max_nodes_reached++;
    int l=0;
    for(l=0;l<pointer[ver];l++)
        if(!visited[arr[ver][l]])
            dfs(arr[ver][l],pointer,visited,arr);
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i,temp,selected_node=-1,j;
        scanf("%d",&n);
        int visited[1008]={0};
        int arr[1008][1008]={0};
        int arr_transpose[1008][1008]={0};
        int pointer[1008]={0};
        int pointer_transpose[1008]={0};

        // pointer[i] = where to store new value
        for(i=1;i<=n;i++)
        {
            int sc;
            scanf("%d",&sc);
            for (j=0;j<sc;j++)
            {
                scanf("%d",&temp);
                arr[i][pointer[i]++]=temp;
                arr_transpose[temp][pointer_transpose[temp]++]=i;
            }
        }

        int f=1;
        for(f=1;f<=n;f++)
        {
            max_nodes_reached=0,selected_node=-1;
            int dd;
            for(dd=0;dd<=n+2;dd++)
                visited[dd]=0;

            dfs(f,pointer_transpose, visited, arr_transpose);

            if (max_nodes_reached==n)
            {
                selected_node=f;
                break;
            }
        }
        if (selected_node==-1)
        {
            // No realm is acceptable
            printf("0\n");
        }
        else
        {
            int d=0;
            for(d=0;d<=n+2;d++)
                visited[d]=0;

            max_nodes_reached=0;
            // Now find SCC of that node
            dfs(selected_node,pointer,visited,arr);
            printf("%d\n",max_nodes_reached);
        }
    }
    return 0;
}
