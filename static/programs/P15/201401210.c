#include<stdio.h>

#define ini(deci) scanf("%d" , &deci)
#define inll(lldeci) scanf("%lld" , &lldeci)
#define instr(str) scanf(" %s" , str)
#define outi(deci) printf("%d\n" , deci)
#define outll(lldeci) printf("%lld" , lldeci)
#define outstr(str) printf("%s" , str)
 
void printKMin(long long arr[], long long n, long long k)
{
    long long i , j , pos = 0;
    long long min = arr[0];
 
    for (i = 0; i <= n-k; i++)
    {
        
        if(min <= arr[i+k-1] && pos > i-1 && pos < i+k && i != 0)
        {
            outll(min);
        }
        else
        {
//             outstr("true ");
            min = arr[i];
            for (j = 0; j < k; j++)
            {
                if (arr[i+j] < min)
                {
                    pos = i+j;
                    min = arr[i+j];
                }
            }
            outll(min);
        }
        if(i != n-k)
            outstr(" ");
    }
}

int main()
{
    long long i , t , N , k;
    long long A[10005];
    inll(t);
    while(t--)
    {
        inll(N);
//         outi(N);
        inll(k);
//         outi(k);
        for(i=0 ; i<N ; i++)
            inll(A[i]);
//         for(i=0 ; i<N ; i++)
//             outll(A[i]);
        printKMin(A , N , k);
        outstr("\n");
    }
}