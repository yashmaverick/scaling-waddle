#include <stdio.h>

int maxHeap[200019], minHeap[200019];
int maxLast, minLast;

int mod = 1e9+7;
int a, b, c, n;

void swap(int* a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(int u)
{
    int s = u;
    
    if(u*2 < minLast)
        if(minHeap[s] > minHeap[u*2])
            s = u*2;
    if(u*2+1 < minLast)
        if(minHeap[s] > minHeap[u*2+1])
            s = u*2+1;
    
    if(s==u)
        return;
    
    swap(&minHeap[s], &minHeap[u]);
    minHeapify(s);
}
void minInsert(int val)
{
    int u = minLast;
    minHeap[minLast++] = val;
    
    while(u > 1)
    {
        if(minHeap[u] > minHeap[u/2])
            return;
        swap(&minHeap[u], &minHeap[u/2]);
        
        u /= 2;
    }
}
void extractMin()
{
    swap(&minHeap[1], &minHeap[minLast-1]);
    minLast--;
    minHeapify(1);
}
void maxHeapify(int u)
{
    int s = u;
    
    if(u*2 < maxLast)
        if(maxHeap[s] < maxHeap[u*2])
            s = u*2;
    if(u*2+1 < maxLast)
        if(maxHeap[s] < maxHeap[u*2+1])
            s = u*2+1;
    
    if(s==u)
        return;
    
    swap(&maxHeap[s], &maxHeap[u]);
    maxHeapify(s);
}
void maxInsert(int val)
{
    int u = maxLast;
    maxHeap[maxLast++] = val;
    
    
    while(u > 1)
    {
        if(maxHeap[u] < maxHeap[u/2])
            return;
        swap(&maxHeap[u], &maxHeap[u/2]);
        
        u /= 2;
    }
}
void extractMax()
{
    swap(&maxHeap[1], &maxHeap[maxLast-1]);
    maxLast--;
    maxHeapify(1);
}

int main()
{
    int t; scanf("%d",&t);
    
    while(t--)
    {
        int i, median = 1;
        long long sum = 1;
        scanf("%d %d %d %d", &a, &b, &c, &n);
        
        minLast = maxLast = 1;
        
        for(i=2; i<=n; ++i)
        {
            int f = (a*(long long)(median))%mod;
            f = (f+(b*(long long)(i)))%mod;
            f = (f+c)%mod;
            
//             printf("%d%c", f, (i==n)?('\n'):(' '));
            
            sum += f;
            
            if(f < median)
            {
                maxInsert(f);
                
                if(i%2 == 0)
                {
                    minInsert(median);
                    median = maxHeap[1];
                    extractMax();
                }
            }
            else
            {
                minInsert(f);
                
                if(i%2 == 1)
                {
                    maxInsert(median);
                    median = minHeap[1];
                    extractMin();
                }
            }
        }
        
        printf("%lld\n",sum);
    }
    
    return 0;
}