#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 1000000001
#define maxN 1234567

int arr[maxN],arr1[maxN][3],arr2[maxN][3],n,m,adj[maxN],dist[maxN],visit[maxN],dist1[maxN],src,dest,heapSize=0;

int heap[maxN];

void insert(int num)
{
    if (heapSize==0)
    {
        heapSize=1;
        heap[1]=num;
        return;
    }
    int location=++heapSize;
    int parentnode;
    while(location>1)
    {
        parentnode = (location)/2;
        if(dist1[num]>dist1[heap[parentnode]])
        {
            heap[location]=num;
            return;
        }
        heap[location]=heap[parentnode];
        location=parentnode;
    }
    heap[1]=num;
}

int delete()
{
    int minElement,lastElement,child,now;
    minElement=heap[1];
    if (heapSize==1)
    {
        heapSize--;
        return heap[1];
    }
    lastElement= heap[heapSize--];
    for(now=1;now*2<=heapSize;now=child)
    {
        child=now*2;
        if (child!=heapSize && dist1[heap[child+1]]<dist1[heap[child]])
        {
            child++;
        }
        if (dist1[lastElement]>dist1[heap[child]])
            heap[now]=heap[child];
        else
            break;
    }        
    heap[now]=lastElement;
    return minElement;
}

void print()
{
    int i=0;
    for(i=1;i<=heapSize;i++)
    {
        printf("%d ",heap[i]);
    }
    printf("\n");
}

void dijkstra()
{
    int i;
    for(i=1;i<=n;i++)
    {
        dist1[i]=max;
        if(i==src)dist1[i]=0;
    }
    insert(src);
    while (heapSize!=0 )
    {
        int u = delete();
        //printf("%d %d %d\n",u,arr2[u][0],arr2[u][1]);
            for (i = arr2[u][0]; i<arr2[u][1];i++)
            {
                int v = adj[i],w=dist[i];
                //printf("%d %d %d %d\n",u,v,w,dist[u]);
                int alt = dist1[u]+w;
                if (alt< dist1[v])
                {
                    dist1[v]=alt;
                    insert(v);
                }
                //print();
            }
    }
}


int main()
{
    int t=1;
    while(t--){
        memset(arr,0,sizeof(arr));
        memset(arr1,0,sizeof(arr1));
        memset(arr2,0,sizeof(arr2));
        memset(dist,0,sizeof(dist));
        memset(dist1,0,sizeof(dist1));
        memset(visit,0,sizeof(visit));
        memset(adj,0,sizeof(adj));
        heapSize=0;

        int i;
        scanf("%d %d",&n,&m);
        heapSize=0;
        for(i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            arr[a]++;
            arr1[i][0]=a;
            arr1[i][1]=b;
            arr1[i][2]=c;
        }
        arr2[1][0]=0;
        arr2[1][1]=arr[1];
        arr[1]=0;
        for(i=2;i<=n;i++)
        {
            arr2[i][0]=arr2[i-1][1];
            arr2[i][1]=arr2[i][0]+arr[i];
            arr[i]=0;
        }
        for(i=0;i<m;i++)
        {
            int u = arr1[i][0] , v = arr1[i][1];
            adj[arr2[u][0]+arr[u]]=v;
            dist[arr2[u][0]+arr[u]]=arr1[i][2];
            arr[u]++;
        }
        scanf("%d %d",&src,&dest);
        dijkstra();
        if(dist1[dest]!=max)
            printf("%d\n",dist1[dest]);
        else
            printf("NO\n");
    }

    return 0;
}
