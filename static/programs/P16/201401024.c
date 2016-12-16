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

int find(ll k)
{
    int b=0;
    while(k!=1)
    {
        k=k/2;
        b++;
    }
    return b;
}

//=========================================================================================================================================

int main()
{
    int n;
    si(n);
    while(n--)
    {
        ll ans;
        ll q;
        sll(q);
        if(q==1)
            ans=0;
        else if(q<(pow(2,find(q)+1)-pow(2,find(q)-1)) && q>=pow(2,find(q)))
            ans=2*find(q)-1;
        else
            ans=2*find(q);
        plln(ans);
    }
    return 0;
}
