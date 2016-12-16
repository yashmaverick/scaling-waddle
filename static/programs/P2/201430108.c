#include <stdio.h>
long long int  le( long long int  a[],  long long int  num,  long long int  l,  long long int  r);
long long int  re( long long int  c[],  long long int  num,  long long int  l,  long long int  r);
int  main() 
{
     long long int  t, p, q, r, i, count, temp1, temp2;
    scanf("%lld", &t);
    while (t--) {
        long long int  a[100001], b[100001], c[100001];
        scanf("%lld", &p);
        for (i = 0; i < p; i++)
            scanf("%lld", &a[i]);
        scanf("%lld", &q);
        for (i = 0; i < q; i++)
            scanf("%lld", &b[i]);
        scanf("%lld", &r);
        for (i = 0; i < r; i++)
            scanf("%lld", &c[i]);
        count = 0;
        long long int  limit;
        for (i = 0; i < q; i++) {
            if(i>(p-1))
                limit=p-1;
            else
                limit=i;
            temp1 = le(a, b[i], 0, limit);
            temp2 = re(c, b[i], i, r-1);
            count += temp1*temp2;
        }
        printf("%lld\n", count);
    }
    return 0;
}

 long long int  le( long long int  a[],  long long int  num,  long long int  l,  long long int  r)
{
    long long int  start = l, end = r, middle;
    long long int  ret;
    if (l > r||a[l] > num)
        return 0;
    if (a[r] <= num)
        return (r-l+1);
     
    while ((end-start) > 1) 
    {
        middle = (start+end)/2;
        if (a[middle] <= num)
            start = middle+1;
        else
            end = middle;
    }
    if (a[start] > num)
        ret=(start-l);
    else
        ret=(end-l);
    return ret;
}

 long long int  re( long long int  c[],  long long int  num,  long long int  l,  long long int  r)
{
    long long int  start = l, end = r, middle;
    long long int  ret;
    if (l > r||c[r] < num)
        return 0;
    if (c[l] >= num)
        return (r-l+1);
     while ((end-start) > 1) 
     {
        middle = (start+end)/2;
        if (c[middle] >= num)
            end = middle-1;
        else
            start = middle;
    }
    if (c[end] < num)
        ret= (r-end);
    else
        ret=(r-start);
    return ret;
}
 

