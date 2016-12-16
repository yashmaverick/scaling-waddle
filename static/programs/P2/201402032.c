#include <stdio.h>

long long int  bin_less( long long int  arr[],  long long int  num,  long long int  left,  long long int  right)
{
    long long int  start = left, end = right, middle;
    long long int  index;
    if (left > right||arr[left] > num)
        return 0;
    if (arr[right] <= num)
        return (right-left+1);

    while ((end-start) > 1) 
    {
        middle = (start+end)/2;
        if (arr[middle] <= num)
            start = middle+1;
        else
            end = middle;
    }
    if (arr[start] > num)
        index=(start-left);
    else
        index=(end-left);
    return index;
}

long long int  bin_more( long long int  arr[],  long long int  num,  long long int  left,  long long int  right)
{
    long long int  start = left, end = right, middle;
    long long int  index;
    if (left > right||arr[right] < num)
        return 0;
    if (arr[left] >= num)
        return (right-left+1);
    while ((end-start) > 1) 
    {
        middle = (start+end)/2;
        if (arr[middle] >= num)
            end = middle-1;
        else
            start = middle;
    }
    if (arr[end] < num)
        index= (right-end);
    else
        index=(right-start);
    return index;
}


void inp (long long int arr[], long long int size)
{
    long long int i;
    for(i=0;i<size;i++)
        scanf("%lld", &arr[i]);
}

int  main() 
{
    int t;
    long long int p, q, r, i, count, above, below, a[100007], b[100007], c[100007];
    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &p);
        inp(a,p);
        scanf("%lld", &q);
        inp(b,q);
        scanf("%lld", &r);
        inp(c,r);
        count = 0;
        long long int  limit;
        for (i = 0; i < q; i++)
        {
            if(i>(p-1))
                limit=p-1;
            else
                limit=i;
            above = bin_less(a, b[i], 0, limit);
            below = bin_more(c, b[i], i, r-1);
            count += above*below;
        }
        printf("%lld\n", count);
    }
    return 0;
}

