#include<stdio.h>
#define M 1000000007
long long int pm(long long int a,long long int b,long long int n)
{
        
        /*if(b==0)
                return 1;
        else 
        {
                if(b%2==0)

                        return pm((a*a)%m,b/2,m)%m;
                else
                        return (a*pm((a*a)%m,(b-1)/2,m))%m;
        }*/
        if(a==0)
        {
                if(b==0)
                        return 1;
                else
                        return 0;
        }
        a=a%n;
        long long int res=1;        
        while(b>0)
        {
                if(b%2==1)                
                        res=((res*a)%n);
                b=b/2;               
                a=((a*a)%n);
        }
        return res%n;

}
int main()
{

        long long int t,i,m,n,j,k,l,arr[41]={},jtotal,ktotal,ltotal,inc;
        long long int d,u,c;
        scanf("%lld",&t);
        for(i=0;i<t;i++)
        {
                
                c=0;
                scanf("%lld%lld%lld%lld",&u,&d,&m,&n);
                for(j=0;j<n;j++)                
                        arr[j]=pm(j,d,n);                             
                for(j=0;j<n;j++)
                {
                        for(k=0;k<n;k++)
                        {
                                for(l=0;l<n;l++)
                                {

                                        if(((arr[j]+arr[k]+arr[l])%n==m)&&j<=u&&k<=u&&l<=u)
                                        {
                                                jtotal=(((u-j)/n)+1)%M;
                                                ktotal=(((u-k)/n)+1)%M;
                                                ltotal=(((u-l)/n)+1)%M;
                                                inc=(((jtotal*ktotal)%M)*ltotal)%M;
                                                c=(c+inc)%M;
                                                //c=(c+((((((u-j)/n+1)%M)*(((u-k)/n+1)%M)%M)*((u-l)/n+1)%M)%M)%M);                                          
                                                
                                        }
                                }
                        }
                }
                printf("%lld\n",c);
        }
        return 0;
}
