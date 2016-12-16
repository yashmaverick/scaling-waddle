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
typedef struct new
{
    ll w;
    int start;
    int end;
}bag;

/*int cmpfunc (const void * a, const void * b)
  {
         return ( *(bag*)a - *(bag*)b );
         }*/


//qsort(..arrayname.., ..sizeofarray.., sizeof(..typeofarray..), cmpfunc);


void merge(bag a[],int l,int mid, int r)
{
    int b=mid-l+1,v=r-mid,i=0,j=0,k=l;
    bag temp[1004];
    while(b>0 && v>0)
    {
        if(a[l+i].w > a[mid+1+j].w)
        {
            temp[k]=a[mid+1+j];
            j++;
            v--;
        }   
        else
        {
            temp[k]=a[l+i];
            i++;
            b--;
        }
        k++;
    }
    if(b<=0)
    {   
        while(v>0)
        {
            temp[k]=a[mid+1+j];
            j++;
            k++;
            v--;
        }
    }
    else
    {   
        while(b>0)
        {
            temp[k]=a[l+i];
            i++;
            k++;
            b--;
        }
    }
    for(i=l;i<=r;i++)
        a[i]=temp[i];
}

void mergesort(bag a[],int l,int r)
{
    int mid=l+(r-l)/2;

    if(r==l)
        return;

    mergesort(a,l,mid);
    mergesort(a,mid+1,r);

    merge(a,l,mid,r);
}
//=========================================================================================================================================

int main()
{
    int n;
    ll mod;
    si(n);
    sll(mod);
    bag a[1002];
    ll b[1000003];
    int i,ind=0,j;
    rep(i,n)
    {
        int m;
        si(m);
        a[i].start=ind;
        ll total=0;
        int j;
        rep(j,m)
        {
            sll(b[ind]);
            total=(total+b[ind])%mod;
            ind++;
        }
        a[i].w=total;
        a[i].end=ind-1;
    }
    mergesort(a,0,n-1);
    rep(i,n)
    {
        plln(a[i].w);
        j=a[i].start;        
        while(j<=a[i].end)
        {
            plln(b[j]);
            j++;
        }
        pn;
    }
    return 0;
}
