#include<stdio.h>
#include<math.h>
int main()
{
    int t,h,q,mi,si;
    int x=0;
    float p;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&q);
        if(q!=1)
        {
            h=log2(q);
        si=pow(2,h);
        mi=si+(si/2);
        if(q>=si&&q<mi)
            printf("%d\n",(2*h)-1);
        else
            printf("%d\n",2*h);
        }
        if(q==1)
            printf("%d\n",x);

    }
    return 0;
}
