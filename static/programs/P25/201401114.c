#include<stdio.h>
#include<stdlib.h>
typedef struct heap
{
    int src, dest;
    long long int wt;
}block;
typedef struct sp
{
    int val;
    int count;
}superparent;
block heap[1000101];
long long int heapsize;
superparent sparent[100101];

int compareUser(const void *v1, const void *v2)
{
    const block *u1 = v1;
    const block *u2 = v2;
    return (u1->wt - u2->wt);
}
int find(int x)
{
    int sp=sparent[x].val;
    while(sp!=sparent[sp].val)
    {
        sp=sparent[sp].val;
    }
    sparent[x].val=sp;
    return sp;
}
int main()
{
    int N, i, x, y;
    long long int w, M;
    int rank[100001];
    scanf("%d %lld", &N, &M);
    heapsize=0;
    for(i=1; i<=N; i++)
    {
        sparent[i].val=i;
        sparent[i].count=1;
        rank[i]=0;
    }
    for(i=0; i<M;i++)
        //    {
        scanf("%d %d %lld", &heap[i].src, &heap[i].dest,&heap[i].wt);
//        scanf("%d %d %lld", &x, &y,&w);
    //        heapinsert(x,y,w);
    //    }
    //sort here
    qsort(heap, M, sizeof(block), compareUser);
//    for(i=0; i<M;i++)
//        printf("%d %d %lld\n", &x, &y,&w);
    int spx,spy,cnt=0;
    long long int sum=0;
    //    while(heapsize>0)
    for(i=0;i<M;i++)
    {
//        block min=heapdelete();
//        spx=find(min.src);
//        spy=find(min.dest);
        spx=find(heap[i].src);
        spy=find(heap[i].dest);
        if(spx==spy && (sparent[spx].count==N  || sparent[spy].count==N))
            break;

        if(spx==spy)
            continue;
        else
        {
            cnt++;
//                sum=sum+min.wt;
                sum=sum+heap[i].wt;
            if(rank[spx]>=rank[spy])
            {
                sparent[spy].val=spx;
                sparent[spx].count+=sparent[spy].count;
            }
            else if(rank[spy]>rank[spx])
            {
                sparent[spx].val=spy;
                sparent[spy].count+=sparent[spx].count;
//                sum=sum+(long long int)min.wt;
            }
            else
            {
                rank[spx]++;
                sparent[spy].val=spx;
                sparent[spx].count+=sparent[spy].count;
            }
        }
    }
    if(cnt==N-1)
        printf("%lld\n", sum);
    else
        printf("-1\n");

    return 0;
}
