#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max 1000000001
#define maxN 1234567

int thrown,arr[maxN],arr1[maxN][2],arr2[maxN][2],n,m,adj[maxN],dist[maxN],visit[maxN],dist1[maxN],heapSize=0,count[maxN],sorted[maxN],sortedsize;

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
        if(num>heap[parentnode])
        {
            heap[location]=num;
            return;
        }
        heap[location]=heap[parentnode];
        location=parentnode;
    }
    heap[1]=num;
    thrown++;
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
        if (child!=heapSize && heap[child+1]<heap[child])
        {
            child++;
        }
        if (lastElement>heap[child])
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

void push(int i)
{
    sorted[sortedsize++]=i;
}

void func()
{
    while(sortedsize!=n)
    {
        //getchar();
        int i,u = delete();
        push(u);
        //printf("%d %d %d\n",sortedsize,arr2[u][0],arr2[u][1]);
        for(i=arr2[u][0];i<arr2[u][1];i++)
        {
            int v=adj[i];
            count[v]--;
            if (count[v]==0)
                insert(v);
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
        memset(visit,0,sizeof(visit));
        memset(adj,0,sizeof(adj));
        heapSize=0;

        int i;
        scanf("%d %d",&n,&m);
        heapSize=0;
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            arr[a]++;
            count[b]++;
            arr1[i][0]=a;
            arr1[i][1]=b;
        }
        arr2[1][0]=0;
        arr2[1][1]=arr[1];
        arr[1]=0;
        if(count[1]==0)insert(1);
        for(i=2;i<=n;i++)
        {
            arr2[i][0]=arr2[i-1][1];
            arr2[i][1]=arr2[i][0]+arr[i];
            arr[i]=0;
            if(count[i]==0)insert(i);
        }
        for(i=0;i<m;i++)
        {
            int u = arr1[i][0] , v = arr1[i][1];
            adj[arr2[u][0]+arr[u]]=v;
            arr[u]++;
        }
        func();
        for(i=0;i<n;i++)
        {
            if(i!=n-1)
                printf("%d ",sorted[i]);
            else
                printf("%d",sorted[i]);
        }
        printf("\n");
    }

    return 0;
}
