#include<stdio.h>
#include<stdlib.h>

#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld\n" , lldeci)

typedef struct bag
{
    int s , len , e ;
    long long wt ;
}x;

int main()
{
    int start=0 , end , i , j , N , M ;
    long long MOD , W , itemwt[1000005];
    struct bag* b;
    ini(N);
    inll(MOD);
    b = (struct bag*) malloc(sizeof(struct bag)*N);
    for(i=0 ; i<N ; i++)
    {
        ini(b[i].len);
        b[i].s = start;
        for(j=start ; j<(start+b[i].len) ; j++)
        {
            inll(itemwt[j]);
            b[i].wt += itemwt[j];
            b[i].wt %= MOD;
        }
        b[i].e = j ;
        start = j ;
    }
    
    for(i=1 ; i<N ; i++)
        for(j=0 ; j<N-1 ; j++)
        {
            if(b[j].wt > b[j+1].wt)
            {
                struct bag t = b[j];
                b[j] = b[j+1];
                b[j+1] = t;
            }
        }
        
    for(j=0 ; j<N ; j++)
    {
        outll(b[j].wt);
        for(i=b[j].s ; i<b[j].e ; i++)
            outll(itemwt[i]);
        printf("\n");
    }
    return 0;
}