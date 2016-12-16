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
#define pn printf("\n")
#define rep(i,n) for(i=0;i<n;i++)
//=========================================================================================================================================
/*int cmpfunc (const void * a, const void * b)
  {
  return ( *(int*)a - *(int*)b );
  }*/

//qsort(..arrayname.., ..sizeofarray.., sizeof(..typeofarray..), cmpfunc);

typedef struct bhg
{
    ll val;
    ll index;
}fuck;

//=========================================================================================================================================

int main()
{
    while(1)
    {
        ll max=0;
        int n;
        si(n);
        if(n==0)
            break;
        else
        {   
            int i;
            fuck a[100003],b[100003];
            int front[100003],back[100004];
            rep(i,n)
            {
                sll(a[i].val);
                a[i].index=i;
            }
            ll j=0;
            b[0]=a[0];
            front[0]=0;
            a[n].val=0;
            a[n].index=n;
            for(i=1;i<=n;i++)
            {
                while(1)
                {
                    if(a[i].val<b[j].val)
                    {
                        front[b[j].index]=i-b[j].index-1;
                        if(j)
                            j--;
                        else
                        {
                            b[j]=a[i];
                            break;
                        }
                    }
                    else
                    {
                        j++;
                        b[j]=a[i];
                        break;
                    }
                }
            }
            j=n;
            for(i=n-1;i>=-1;i--)
            {
                while(1)
                {
      //              printf("i=%d j=%lld\n",i,j);
                    ll x;
                    if(i==-1)
                        x=0;
                    else
                        x=a[i].val;
                    if(x<b[j].val)
                    {
                        back[b[j].index]=b[j].index-i-1;
                        if(j!=n)
                            j++;
                        else if(i!=-1)
                        {
                            b[j]=a[i];
                            break;
                        }
                        else
                            break;
                    }
                    else
                    {
                        if(j)
                             j--;
                        b[j]=a[i];
                        break;
                    }
                }
            }
            rep(i,n)
            {
    //            printf("for %lld  front = %d   back = %d\n",a[i].val,front[i],back[i]);
                if(a[i].val*(front[i]+back[i]+1)>max)
                    max=a[i].val*(front[i]+back[i]+1);
            }
            plln(max);
        }
    }
    return 0;
}
