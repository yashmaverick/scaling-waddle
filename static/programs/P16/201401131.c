#include<stdio.h>
typedef long long int ll;
int main()
{
        ll t,n,i,j,l,flag;
        scanf("%lld",&t);
        for(i=0;i<t;i++)
        {
                j=0;
                scanf("%lld",&n);
                l=n;
                        while(l!=0)
                        {
                                j=j+1;
                                if(l==2)
                                        flag=1;
                                else if(l==3 | n==1)
                                        flag=0;
                                l=l/2;
                        }
                        if(flag==0)
                                printf("%lld\n",2*j-2);
                        else if(flag==1)
                                printf("%lld\n",2*j-3);
        }
        return 0;
}
