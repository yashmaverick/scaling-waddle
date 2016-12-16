#include <stdio.h>

int main()
{
    long long int t,x,n,i,m,s,d,p1,p2;
    scanf("%lld",&n);
    long long int a[n];
    long long int b[n];
    long long int k;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        //    printf("a[%d]=%d",x,a[x]);
    }
    //printf("\n");
    for(i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
        //  printf("b[%d]=%d",i,b[i]);
    }
    // printf("\n");
    scanf("%lld",&t);
    for(m=1;m<=t;m++)
    {
        long long int min=100000000;
        p1=100000000;
        long long int lca;
        long long int flag=0;
        k=0;
        scanf("%lld %lld",&s,&d);
        for(i=0;i<n;i++)
        {
            if(b[i]==s||b[i]==d)
            {
                if(i<p1)
                    p1=i;
                p2=i;
            }
        }
        //  printf("p1=%d p2=%d\n",p1,p2);
        for(i=0;i<n;i++)
        {
            for(k=p1;k<=p2;k++)
            {
                if(a[i]==b[k])
                {
                    lca=a[i];
                    flag=1;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        printf("%lld\n",lca);
    }
    return 0;
}



