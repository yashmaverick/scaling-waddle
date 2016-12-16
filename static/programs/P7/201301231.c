#include <stdio.h>

int main()
{
        long int min,t,T,i,j,n,a[1000000],hash[1000000],count;

        scanf("%ld",&T);

        for(t=1;t<=T;t++)
        {
                scanf("%ld",&n);

                min=10000000;

                for(i=0;i<1000000;i++)
                        hash[i]=0;

                for(i=0;i<n;i++)
                {
                        scanf("%ld",&a[i]);

                        if(min>a[i])
                                min=a[i];
                }

                for(i=0;i<n;i++)
                {        
                        a[i]=a[i]-min;
                        hash[a[i]]++;
                }

                count=0;

                for(i=0;i<1000000;i++)
                {
                        count=count+(hash[i]*(hash[i]-1))/2;                                                
                }

                printf("%ld\n",count);

        }

        return 0;
}
