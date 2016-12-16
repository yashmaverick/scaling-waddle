#include<stdlib.h>
#include<stdio.h>

#define si(x) scanf("%d",&x)
#define ss(x) scanf("%s",x)

int cmp(const void * p1, const void * p2)
{
    return ((int)(*((int*)p1))) - ((int)*((int*)p2));
}
char S[10000];
int A[1000];
int main()
{
    int t; si(t); while(t--)
    {
        int i,j,k,n,K; si(n); si(K);
        for(i=0; i<n;i++)
        {
            ss(S); si(A[i]);
        }
        qsort(A,n,sizeof(int),cmp);
        int ans = 0;
        for(i=0; i<n && ans==0;i++)
        {
            k = n-1;
            for( j=i+1; j<n && ans==0;j++)
            {
                while(k>j && A[i]+A[j]+A[k] > K)k--;
                if(k>j &&  (A[i]+A[j]+A[k]==K))ans=1;
            }
        }
        if(ans)printf("YES\n"); else printf("NO\n");
    }
}
