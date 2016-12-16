#include <stdio.h>

int main()
{
    long long int a[100005];
    //int b[4];
    int n,t,m,i;
    long long int d=0;
    scanf("%d",&t);
    for(m=1;m<=t;m++)
    {
        d=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        long long int max=a[0];
        long long int min=a[0];
        int maxp=1;
        int minp=0;
        for(i=1;i<n;i++)
        {
            if(a[i]<min)
            {
                minp=i;
                maxp=i;
                min=a[i];
                max=a[i];
            }
            else if(a[i]>max && i>=maxp)
            {
                max=a[i];
                if((max-min)>d)
                {
                    d=max-min;
                }                
            }
          //  printf("max=%lld min=%lld d=%lld\n",max,min,d);
        }
      //  d=max-min;
        if(d<0)
            d=0;
        printf("%lld\n",d);
    }
    return 0;
}

                

