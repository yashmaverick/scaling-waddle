#include<stdio.h>
int main()
{
        long long int max,min,i,j,N,A,a[100000],pi=0,pa=0,diff;
        scanf("%lld",&N);
        for(i=0;i<N;i++)
        {
                diff=0;
                scanf("%lld",&A);
                for(j=0;j<A;j++)
                        scanf("%lld",&a[j]);
                max=a[0];
                min=a[0];
                for(j=0;j<A;j++)
                {
                        if(diff<a[j]-min)
                                diff=a[j]-min;
                        if(min>a[j])
                                min=a[j];
                }
                printf("%lld\n",diff);
        }
        return 0;
}
