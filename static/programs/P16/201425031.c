#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long int efficientpow(long long base, long long exp)
{
    int result = 1;
    while (exp)
    {
        if (exp & 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

int main()
{
    long long int N,Q,i,j,k,l,p,answer,m;
    scanf("%lld",&N);
    while(N--)
    {
        scanf("%lld",&Q);
        if(Q==1)
        {
            answer=0;
            
        }
        else
        {
        for(i=1;i<=30;i++)
        {
            k=efficientpow(2,i);
            l=efficientpow(2,i-1);
            m=efficientpow(2,i+1);
            if(Q>=k && Q<k+l)
            {
                answer=2*i-1;
                break;
            }
            else if(Q>=k+l && Q<m)
            {
                answer=2*i;
                break;
            }
        }}
        printf("%lld\n",answer);
    }


    return 0;
}
