
/*
   _____________________________________________

PURPOSE : 

created by -ABHINAV AGGARWAL
_____________________________________________ 

*/

#include <stdio.h>

#define MOD 1000000007

long long int mod(long long int a,long long int b,int m)
{
    if(b==0)
        return 1;
    long long int x=mod(a,b/2,m);
    if(b%2==0)
    {
        return (x*x)%m;
    }
    else
    {
        return (a*((x*x)%m))%m;
    }
}

long long int modulus[100];
long long int occurence[100];

int main()
{

    int i,j,k,t,u,d,m,n,Q,R,ans;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d%d%d%d",&u,&d,&m,&n);

        ans=0;

        for(i=0;i<n;i++)
        {
            modulus[i]=mod(i,d,n);
        }

        Q=u/n;
        R=u%n;

        for(i=0;i<n;i++)
        { 
          if(i<=R)
              occurence[i]=Q+1;
          else
              occurence[i]=Q;
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                for(k=0;k<n;k++)
                {
                    if((modulus[i]+modulus[j]+modulus[k])%n==m%n)
                        ans=(ans+(((occurence[i]*occurence[j])%MOD)*occurence[k])%MOD)%MOD;
                }
            }
        }

        printf("%d\n",ans);
    }


    return 0;
}
