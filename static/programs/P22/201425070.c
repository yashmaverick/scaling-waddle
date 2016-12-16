// #Authored : Jaipal Singh Goud
// Sem I-II

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define MOD 1000000007

typedef struct mn
{
    int size;
    int array[300000];
}heap;

heap *makeheap(int n)
{
    heap *new;
    new = (heap *)malloc(sizeof(heap));
    new->size = 0;

    int i;
    for(i=0;i<=n;i++)
        new->array[i] = 0;

    return new;
}

void insertmin(heap *new , int x , int pos)
{
    new->size = new->size + 1;
    int parent , temp;
    new->array[new->size] = x ;   // Size indexing is from 1
    pos = new->size;
    while( pos != 1)
    {
        parent = (pos)/2;
        if(new->array[parent] > new->array[pos] )
        {
            temp = new->array[parent];
            new->array[parent] = new->array[pos];
            new->array[pos] = temp;
            pos = parent;
        }
        else
            return;
    }
}

void insertmax(heap *new , int x , int pos)
{
    new->size = new->size + 1;
    int parent , temp;
    new->array[new->size] = x ;   // Size indexing is from 1
    pos = new->size;
    while( pos != 1)
    {
        parent = (pos)/2;
        if(new->array[parent] < new->array[pos] )
        {
            temp = new->array[parent];
            new->array[parent] = new->array[pos];
            new->array[pos] = temp;
            pos = parent;
        }
        else
            return;
    }
}

void shuffledown(heap *new , int pos)
{
    int i = pos;
    int min;
    int idx;
    int temp;
    while ( i <= (new->size)/2 && (new->array[i] > new->array[2*i] || new->array[i] > new->array[2*i +1])) 
    {
        if( new->array[2*i] < new->array[2*i+1])
        {
            min = new->array[2*i];
            idx = 2*i;
        }
        else
        {
            min = new->array[2*i + 1];
            idx = 2*i + 1;
        }
        temp = new->array[i];
        new->array[i] = min;
        new->array[idx] = temp;
        i = idx;
    }
}

void shuffleup(heap *new , int pos)
{
    int i = pos;
    int min;
    int idx;
    int temp;
    while ( i <= (new->size)/2 && (new->array[i] < new->array[2*i] || new->array[i] < new->array[2*i +1])) 
    {
        if( new->array[2*i] > new->array[2*i+1])
        {
            min = new->array[2*i];
            idx = 2*i;
        }
        else
        {
            min = new->array[2*i + 1];
            idx = 2*i + 1;
        }
        temp = new->array[i];
        new->array[i] = min;
        new->array[idx] = temp;
        i = idx;
    }
}

int deletemin(heap *new)
{
    int min;
    min = new->array[1];
    new->array[1] = new->array[new->size];
    new->size = new->size-1;
    shuffledown(new , 1);
    return min;
}

int deletemax(heap *new)
{
    int max;
    max = new->array[1];
    new->array[1] = new->array[new->size];
    new->size = new->size - 1;
    shuffleup(new , 1);
    return max;
}

void printheap(heap *new)
{
    int i;
    for(i=1;i<=new->size;i++)
        printf("%d , ",new->array[i]);
    printf("\n");
    return;
}

int median[200009];
int f[200009];

int function(long long int a ,long long int b ,long long int c , int i)
{
    return (a*median[i] + b*i + c) % MOD;
}

int main()
{
    int i , test , n , x;
    heap *minheap , *maxheap;
    int max , min;
    long long int a , b , c , sum;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%lld%lld%lld",&a,&b,&c);
        scanf("%d",&n);
        sum = 0;
        max = min = 1;
        f[1] = 1;
        median[2] = 1;
        median[1] = -1;
        minheap = makeheap(n);
        maxheap = makeheap(n);
        for(i=1;i<=n;i++)
        {
            if(i == 1)
                f[i] = 1;
            else
                f[i] = function(a , b , c , i);
            
            if( i == 1)
                insertmax(maxheap , f[i] ,i);
            else
            {
                if( f[i] > maxheap->array[1])    // Maxheap->array[1] = median
                {
                    insertmin(minheap , f[i] , minheap->size+1);
                    min++;
                }
                else
                {
                    insertmax(maxheap , f[i] , maxheap->size+1);
                    max++;
                }
            }
            if( maxheap->size - minheap->size > 1)
            {
                x = deletemax(maxheap);
                insertmin(minheap , x , minheap->size+1);
            }
            else if( maxheap->size - minheap->size < -1)
            {
                x = deletemin(minheap);
                insertmax(maxheap , x , maxheap->size+1);
            }
            if(maxheap->size == minheap->size)
                median[i+1] = maxheap->array[1];
            else
            {
                if(maxheap->size > minheap->size)
                    median[i+1] = maxheap->array[1];
                else
                    median[i+1] = minheap->array[1];
            }
            sum = sum + f[i];
        }
        printf("%lld\n",sum);
    }
    return 0;
}
