#include<stdio.h>
int A[10000000], B[10000000];
long long sadas(int x)
{
    int i = 2;
    long long r = 1;
    while(i <= x)
    {
        r *= i;
        i++;
    }
    return r;
}
void merge(int beg, int mid, int end)
{
    int i, j, k, l = 2e6;
    
    for(i=0;i+beg<=mid;++i)
        B[i] = A[i+beg];
    B[i] = 1e9;
    for(j=l;j-l+mid+1<=end;++j)
        B[j] = A[j-l+mid+1];
    B[j] = 1e9;
    
    i = 0, j = l, k = beg;
    
    while(k<=end)
    {
        if(B[i]<B[j])
        {
            A[k++] = B[i++];
        }
        else
        {
            A[k++] = B[j++];
        }
    }
}
void mergeSort(int beg, int end)
{
    int mid;
    if(beg < end)
    {
        mid = (beg+end)/2;
        mergeSort(beg, mid);
        mergeSort(mid+1, end);
        merge(beg, mid, end);
    }
}
int main()
{
    int t, n, i;
    long long r, dupes;
    scanf("%d", &t);
    while(t--)
    {
        dupes = 0;
        r = 0;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
        {
            scanf("%d", &A[i]);
        }
        mergeSort(0, n-1);
        
        int val = A[0];
        dupes++;
        for(i = 1; i < n; i++)
        {
//             if(A[i] == A[i-1])
//             {
//                 if(dupes==0)
//                 {
//                     dupes+=2;
//                 }
//                 else
//                 {
//                     dupes++;
//                 }
//             }
//             else
//             {
//                 if(dupes!=0)
//                 {
//                     r += sadas(dupes)/(2*(sadas(dupes-2)));
//                 }
//                 dupes = 0;
//             }
            
            if(A[i] == val)
            {
                dupes++;
            }
            else
            {
                r += (dupes*(dupes-1))/2;
                
                dupes = 1;
                val = A[i];
            }
        }
        /*
        if(dupes!=0)
        {
            r += sadas(dupes)/(2*(sadas(dupes-2)));
        }*/
        r += (dupes*(dupes-1)/2);
        printf("%lld\n", r);
    }
    return 0;
}
