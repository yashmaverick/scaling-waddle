#include<stdio.h>
#include<stdlib.h>

int A[1000005];
int compare(const void *a , const void *b)
{
    return ( *(int*)a - *(int*)b );
}
inline long long calc(long long n)
{
    return ((n*(n-1))/2);
}

int main()
{
    int t , i ;
    long long n;
    scanf("%d",&t);
    while(t--)
    {
        long long cp = 1;
        long long ct = 0;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%d",&A[i]);
        qsort(A,n,sizeof(int),compare);
        int x;
//         for(i=0;i<n;i++)
//             printf("%d ",A[i]);
//         printf("\n");
        x = A[0];
        for(i=1;i<n;i++)
        {
            if(A[i] == x)
            {
                cp++;
            }
            else if(A[i] != x)
            {
                ct += calc(cp);
                cp = 1;
                x = A[i];
            }
        }
        ct += calc(cp);
        printf("%lld\n",ct);
    }
    return 0;
}