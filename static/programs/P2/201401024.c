#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        
        long long i,j,p,q,r,a[100003],b[100003],c[100003],e[100003],d[100003],sum=0;  
        scanf("%lld",&p);
        for(i=0;i<p;i++)
            scanf("%lld",&a[i]);

        scanf("%lld",&q);
        for(i=0;i<q;i++)
            scanf("%lld",&b[i]);

        scanf("%lld",&r);
        for(i=0;i<r;i++)
            scanf("%lld",&c[i]);
        j=0;
        for(i=0;i<p;i++)
        {
            {
                if(a[i]<=b[j] && i<=j)
                    d[j]=d[j-1]+1;
                else if(a[i]>b[j] && j!=0)
                    d[j]=d[j-1];
                if(j<q)
                    j++;
                if(j>=q && i<p)
                    break;
            }
        }
        j=0;
        for(i=0;i<q;i++)
        {
                if(b[i]<=c[j] && i<=j)
                    e[j]=e[j-1]+d[i];
                else if(b[i]>c[j] && j!=0)
                    e[j]=e[j-1]; 
                if(j<r)
                    j++;
                if(j>=r && i<p)
                    break;
        }
/*        for(i=0;i<q;i++)
            printf("%lld    %lld \n",d[i],e[i]); */
        for(i=0;i<r;i++)
            sum +=e[i];
        printf("%lld\n",sum);
        t--;
    }
    return 0;
}
