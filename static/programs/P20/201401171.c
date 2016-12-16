#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define maxN 1234567

int arr[maxN],arr1[maxN][2],arr2[maxN][2],visit[maxN],mdist,mnode,adj[maxN];

dfs(int u, int dist)
{
    //printf("%d %d",u,dist);
    int i;
    visit[u]=1;
    if(mdist<dist)
    {
        mdist=dist;
        mnode=u;
    }

    for(i=arr2[u][0]; i<arr2[u][1]; i++)
    {
        int v = adj[i];
        if(visit[v]==0)
        {
            //printf("yo: %d %d %d\n",u,v,dist);
            dfs(v,dist+1);
        }
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
        memset(arr,0,sizeof(arr));
        memset(arr2,0,sizeof(arr2));
        memset(visit,0,sizeof(visit));
        mdist=0;
        for(i=0;i<n-1;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            arr[a]++;
            arr[b]++;
            arr1[i][0]=a;
            arr1[i][1]=b;
        }
        arr2[1][0]=0;
        arr2[1][1]=arr[1];
        arr[1]=0;
        for(i=2;i<=n;i++)
        {
            arr2[i][0]=arr2[i-1][1];
            arr2[i][1]=arr2[i][0]+arr[i];
            //printf("%d %d %d %d\n", i ,arr[i], arr2[i][0], arr2[i][1]);
            arr[i]=0;
        }
        for(i=0;i<n-1;i++)
        {
            int u = arr1[i][0] , v = arr1[i][1];
            adj[arr2[u][0]+arr[u]]=v;
            adj[arr2[v][0]+arr[v]]=u;
            arr[u]++;
            arr[v]++;
        }
        for(i=0;i<2*n;i++)
        {
            //printf("%d\n",adj[i]);
        }
        dfs(1,0);
        memset(visit,0,sizeof(visit));
        mdist=0;
        dfs(mnode,0);
        printf("%d\n",mdist+1);
        
    }
    return 0;
}
