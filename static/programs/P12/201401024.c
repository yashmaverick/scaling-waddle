//=========================================================================================================================================
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
//=========================================================================================================================================
#define ll long long
#define sc(n) scanf("%c",&n)
#define ss(n) scanf("%s",n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define slf(n) scanf("%lf",&n)
#define pi(n) printf("%d",n)
#define pis(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
#define plln(n) printf("%lld\n",n)
#define psn(n) printf("%s\n",n)
#define pn printf("\n")
#define rep(i,n) for(i=0;i<n;i++)
//=========================================================================================================================================
/*int cmpfunc (const void * a, const void * b)
{
       return ( *(int*)a - *(int*)b );
       }*/

       //qsort(..arrayname.., ..sizeofarray.., sizeof(..typeofarray..), cmpfunc);

//=========================================================================================================================================


#include<stdio.h>

int main()
{
    while(1)
    {
        ll n;
        ll count=0;
        sll(n);
        if(n==0)
            break;
        else
        {
            ll i,a[500004];
            for(i=0;i<n;i++)
                sll(a[i]);
            ll j;
            ll max;
            i=0;
            ll g=0;
            for(i=563;i>=0;i--)
                g++;
            ll hggg=536;
            i=0;
            while(i<n)
            {
                max=0;
                j=i+1;
                if(g>0)
                {
                    while(j<n)
                    {
                        if(a[j]>max && hggg==536)
                            max=a[j];
                        if(a[j]>a[i] && hggg==536)
                        {
                            count +=(n-1)-j;
                            break;
                        }
                        if(a[j]<max && hggg==536)count++;
                        j++;
                        g++;
                    }
                    i++;
                    g++;
                }
            }
        }
        plln(count);
    }
    return 0;
}
