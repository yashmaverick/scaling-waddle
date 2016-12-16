#include<stdio.h>
#include<stdlib.h>

long long int *p[1010],mod,n;//m
//int n;
long long int m[1023];

int main()
{
    long long int sum[1010],t;
    
    scanf("%lld %lld",&n,&mod);

    long long int i,j,*temp;

    for(i=0;i<n;i++)
    {
        scanf("%lld",&m[i]);
        p[i]=(long long int *)malloc(m[i]*sizeof(long long int ));
        long long int x=0;
        sum[i]=0;

        for(j=0;j<m[i];j++)
        {
            scanf("%lld",&p[i][j]);
           // sum[i]+=p[i][j];
            x=((x%mod)+(p[i][j]%mod))%mod;
            //sum[i]=x;
        }
        sum[i]=x;
    }

    /*
    temp=p[0];
    p[0]=p[1];
    p[1]=temp;
    */

    
    for(i=0;i<(n-1);i++)
    {
        for(j=0;j<(n-1-i);j++)
        {
            if(sum[j]>sum[j+1])
            {
                /*
                sum[j]=sum[j]+sum[j+1];
                sum[j+1]=sum[i]-sum[j+1];
                sum[j]=sum[j]-sum[j+1];
                */
                t=sum[j];
                sum[j]=sum[j+1];
                sum[j+1]=t;

                t=m[j];
                m[j]=m[j+1];
                m[j+1]=t;

                //to swap weights
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

    
    //printf("\n\n");

    /*
    for(i=0;i<n;i++)
    {
        printf("%lld\n",m[i]);
        //p[i]=(long long int *)malloc(m*sizeof(long long int ));

        for(j=0;j<m[i];j++)
        {
            printf("%lld ",p[i][j]);
        }
        
        printf("\n\n");
    }
    */


    for(i=0;i<n;i++)
    {
        printf("%lld\n",sum[i]);

        for(j=0;j<m[i];j++)
        {
            printf("%lld\n",p[i][j]);
        }
        printf("\n");
    }
    

    return 0;
}
