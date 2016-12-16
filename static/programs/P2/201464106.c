#include<stdio.h>
long long int smallSearch(long long int a[],long long int n,long long int x,long long int p,long long int q)
{
    long long int mid;
    mid=(p+q)/2;
    if(p>q)
        return -1;
    if(a[q]<=x)
        return q;
    if(p==q)
        if(a[p]<=x)
            return p;
        else
            return -1;
    if(p==q-1)
        if(a[q]<=x)
            return q;
        else if(a[p]<=x)
            return p;
        else
            return -1;
    else 
    {
        if(a[mid]<=x && a[mid+1]>x)
            return mid;
        else if(a[mid]>x)
            smallSearch(a,n,x,p,mid-1);
        else
            smallSearch(a,n,x,mid+1,q);
    }
}





long long int bigSearch(long long int a[],long long int n, long long int x,long long int p,long long int q)
{
    long long int mid;
    mid=(p+q)/2;
    if(p>q)
        return -1;
    if(a[p]>=x)
        return p;
    if(p==q)
        if(a[p]>=x)
            return p;
        else
            return -1;
    if(p==q-1)
        if(a[p]>=x)
            return p;
        else if(a[q]>=x)
            return q;
        else
            return -1;
    else
    {
        if(mid==0)
        {
            if(a[mid]>=x)
                return mid;
        }
        else if(a[mid]>=x && a[mid-1]<x)
            return mid;
        else if(a[mid]<x)
            bigSearch(a,n,x,mid+1,q);
        else
            bigSearch(a,n,x,p,mid-1);
    }
}



int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        long long int i,j,k;
        long long int p,q,r;

        scanf("%lld",&p);
        long long int a[p];
        for(i=0;i<p;i++)
            scanf("%lld",&a[i]);

        scanf("%lld",&q);
        long long int b[q];
        for(j=0;j<q;j++)
            scanf("%lld",&b[j]);

        scanf("%lld",&r);
        long long int c[r];
        for(k=0;k<r;k++)
            scanf("%lld",&c[k]);

        long long int s=0,m,n;


        for(j=0;j<q && j<r;j++)
        {
            if(j>p-1)
                m=smallSearch(a,p,b[j],0,p-1);
            else
            {

                m=smallSearch(a,p,b[j],0,j);
            }
            if(m!=-1)
            {

                n=bigSearch(c,r,b[j],j,r-1);

//                printf("m-%lld n-%lld\n",m,n);
                if(n==-1)
                    break;

                s+=(m+1)*(r-n);
            }
        }
        printf("%lld\n",s);
    }
    return 0;
}
