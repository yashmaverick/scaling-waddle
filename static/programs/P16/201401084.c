#include <stdio.h>

int main()
{
    long long int x,y;
    long long int t,m,n,i;
    scanf("%lld",&t);
    for(m=1;m<=t;m++)
    {
        scanf("%lld",&n);
        if(n==1)
        {
            printf("0\n");
        }
        else if(n==2)
        {
            printf("1\n");
        }
        else if(n==3)
        {
            printf("2\n");
        }
        else
        {
            x=4;
            y=3;
            for(i=2;x<=n;i++)
            {
                x=x*2;
                y=y*2;
            }
            if(n>=y)
            {
                printf("%lld\n",2*(i-1));
            }
            else
            {
                printf("%lld\n",(2*i-3));
            }
        }
    }
    return 0;
}
        

        

