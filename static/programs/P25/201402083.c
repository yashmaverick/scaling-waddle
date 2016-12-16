#include<stdio.h>
#include<stdlib.h>
typedef struct input input;
struct input
{
    int u;
    int v;
    long long int weight;
};

input edge[1000001];
int p[1000001];

void merge(input edge[],int start1,int end1,int start2,int end2)
{
    int i=start1,j=start2,k=end1,l=end2;
    int index=0;
    input result[end2-start1+1];
    while(i<=end1 && j<=end2)
    {
        if(edge[i].weight > edge[j].weight) 
        {
            result[index].weight=edge[j].weight;
            result[index].u=edge[j].u;
            result[index].v=edge[j].v;
            index++;
            j++;
        }
        else
        {
            result[index].weight=edge[i].weight;
            result[index].u=edge[i].u;
            result[index].v=edge[i].v;
            index++;
            i++;
        }
    }
    while(i<=end1)
    {
        result[index].weight=edge[i].weight;
        result[index].u=edge[i].u;
        result[index].v=edge[i].v;
        index++;
        i++;
    }
    while(j<=end2)
    {
        result[index].weight=edge[j].weight;
        result[index].u=edge[j].u;
        result[index].v=edge[j].v;
        index++;
        j++;
    }
    int z;
    for(z=0;z<index;z++)
    {
        edge[start1].weight=result[z].weight;
        edge[start1].u=result[z].u;
        edge[start1].v=result[z].v;
        start1++;
    }
    return;
}
void mergesort(input edge[],int start,int end)
{
    if(end<=start) return ;
    int mid=(start+end)/2;
    mergesort(edge,start,mid);
    mergesort(edge,mid+1,end);
    merge(edge,start,mid,mid+1,end);
    return;
}


int root(int x)
{
    if(p[x]==x) return x;
    p[x]=root(p[x]);
    return p[x];
}

int cmp(const void* a,const void *b)
{
    return ((((input*)a)->weight) - (((input *)b)->weight));
}
int main()
{
    int i,count=0;
    long long int result=0;
    int vertex,edges;
    scanf("%d %d\n",&vertex,&edges);
    for(i=0;i<edges;i++)  scanf("%d %d %lld",&edge[i].u,&edge[i].v,&edge[i].weight);
//    mergesort(edge,0,edges-1);
    qsort(edge,edges,sizeof(input) ,cmp);
    for(i=1;i<=vertex;i++)  p[i]=i;
    for(i=0;i<edges;i++)
    {
        int x=root(edge[i].u);
        int y=root(edge[i].v);
        if(x!=y)
        {
            count++;
            p[x]=y;
            result+=edge[i].weight;
        }
    }
    if(count==vertex-1)
        printf("%lld\n",result);
    else printf("-1\n");
    return 0;
}

