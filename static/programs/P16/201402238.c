#include<stdio.h>
#include<math.h>
int main()
{       long long int n,a,x,y,z;
        scanf("%lld",&n);
        while(n--)
        {       scanf("%lld",&a);
                x=log2(a);
                y=pow(2,x)-1+pow(2,x-1);
                z=2*x;
                if(a>y)
                printf("%lld\n",z);
                else
                printf("%lld\n",z-1);
        }

return 0;
}
