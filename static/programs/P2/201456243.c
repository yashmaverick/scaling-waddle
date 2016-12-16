#include <stdio.h>
#include <string.h>

int V[3][100000];
long long C[3][100000], P[3][100000];
int L[3];

void compute(int d)
{
    int i, j;
    
    i = j = 0;
    while(1)
    {
        if(j==L[d+1])
            break;
        if(i==L[d])
            break;
        if(i>j)
        {
            j++;
            continue;
        }
        if(V[d][i]<=V[d+1][j])
        {
            C[d][i] = P[d+1][j];
            i++;
        }
        else
        {
            j++;
        }
    }
    
    P[d][L[d]-1] = C[d][L[d]-1];
    for(i=L[d]-2;i>=0;--i)
        P[d][i] = P[d][i+1] + C[d][i];
}

int main()
{
    int i, j, k, t, d;
    
    int T;
    scanf("%d",&T);
    
    for(t=0;t<T;++t)
    {
        memset(V,0,sizeof V);
        memset(C,0,sizeof C);
        memset(P,0,sizeof P);
        
        for(d=0;d<3;++d)
        {
            scanf("%d",&L[d]);
            for(i=0;i<L[d];++i)
                scanf("%d",&V[d][i]);
        }
        
        for(i=0;i<L[2];++i)
        {
            C[2][i] = 1;
            P[2][i] = L[2]-i;
        }
        
        for(d=1;d>=0;--d)
            compute(d);
        
        printf("%lld\n",P[0][0]);
    }
    
    return 0;
}