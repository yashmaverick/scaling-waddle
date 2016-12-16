#include<stdio.h>
#include<math.h>
int main()
{
        long long int N,i,Q,l,ans;
        scanf("%lld",&N);
        for(i=0;i<N;i++)
        {
                scanf("%lld",&Q);
                l=(long long int)log2(Q);
                long long int x=2*pow(2,l)-pow(2,l-1);
                if(Q>=x)
                        ans=2*l;
                else
                        ans=2*l-1;
                printf("%d\n",(int)ans);
        }
        return 0;
}
