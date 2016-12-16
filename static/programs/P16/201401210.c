#include<stdio.h>
#include<stdlib.h>

#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld" , lldeci)
#define outstr(str) printf("%s" , str)
#define max( a , b ) return ((a > b) ? a : b)

long long A[61];
void make()
{
    int i;
    long long N = 2;
    for(i=0 ; i<61 ; i++)
    {
        A[i] = N;
        N *= 2;
    }
}

int findlev(int in)
{
    int i = 0;
    while(in >= A[i])
        i++;
    return i;
}

int findd(int in)
{
    int lev = findlev(in);
//     outi(lev);
    int n = ((A[lev] - A[lev-1])/2) + A[lev-1];
//     outi(n);
    if(in < n)
        return (lev*2-1);
    else
        return (lev*2);
}

int main()
{
    make();
    int t , N;
    ini(t);
    while(t--)
    {
        ini(N);
        int ans = findd(N);
        outi(ans);
    }
}