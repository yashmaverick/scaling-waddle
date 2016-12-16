#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    long long int f=0,t=0;
    scanf(" %lld",&t);
    for(f=0;f<t;f++)
    {
        long long int P,Q,R;
        long long int i;

        scanf(" %lld",&P);               // Array A[] eith length P
        long long int A[P];
        for(i=0;i<P;i++)
            scanf(" %lld",&A[i]);

        scanf(" %lld",&Q);               // Array B[] with length Q
        long long int B[Q];
        for(i=0;i<Q;i++)
            scanf(" %lld",&B[i]);

        scanf(" %lld",&R);               // Array C[] with length R
        long long int C[R];
        for(i=0;i<R;i++)
            scanf(" %lld",&C[i]);

        long long int p=P-1,q=Q-1,r=R-1,ans=0;

        while(q>=0)
        {
            while(p>=0 && (p>q || A[p]>B[q]))
            {
                p--;
//            printf("P is %lld\n",p);
            }
            while(r>=q && C[r]>=B[q])
                r--;
            ans+=((p+1)*(R-(r+1)));
            q--;
        }
        if (ans<0)
            ans=0;
        printf("%lld\n", ans);
    }
    return 0;
}
