#include<stdio.h>
long long int binaryleft(long long int a[], long long int l,long long int r,long long int size,long long int el)
{//long long int left=l;
 long long int mid,flag=0;


    if (el<a[0])
        return 0;
    if(el>=a[size-1])
        return size;


    while(l<=r)
    {   mid=(l+r)/2;
            if(a[mid]<=el &&a[mid+1]>el)
                return mid+1;

            else if(el<a[mid])
                return binaryleft(a,l,mid-1,size,el);
            else 
                return binaryleft(a,mid+1,r,size,el);
    }



}
long long int binaryright(long long int a[],long long int l,long long int r,long long int size,long long int el) 
{
    //printf("el %dr=%d",el,r);
    //long long int size=r+1;
    long long int mid,flag=0;

    if(el>a[size-1])
        return 0;
    if(el<=a[0])
        return size;

    while(l<=r)
    {   mid=(l+r)/2;

        if(el>a[mid]&&a[mid+1]>=el)
            return size-mid-1;
        else if(el<=a[mid])
            return binaryright(a,l,mid-1,size,el);
        else
            return binaryright(a,mid+1,r,size,el);

    }   

    // if(a[mid]<el)
    // {
    //   if(mid==r&&a[mid]<el)
    //     return 0;
    //if(mid==l&&a[mid]<el)
    //  return 0;
    //
    // }

}


int main()
{int test;
    scanf("%d",&test);
    long long int a[100000],b[100000],c[100000];
    long long int i;
    long long int p,q,r,p1,p2;
    // long long int prefix1[1000000],prefix2[1000000];
    while(test--)
    {long long int ans=0;
        scanf("%lld ",&p);

        for(i=0;i<p;++i)
        {
            scanf("%lld",&a[i]);
        }
        scanf("%lld ",&q);
        for(i=0;i<q;++i)
        {
            scanf("%lld",&b[i]);
        }
        scanf("%lld",&r);
        for(i=0;i<r;++i)
        {
            scanf("%lld",&c[i]);
        }
        long long int l1,l2;
        

        for(i=0;i<(q>r?r:q);++i)
        {
            p1=binaryleft(a,0,p-1,p,b[i]);
//            printf("\n%lld ",p1); 
            p2=binaryright(c,0,r-1,r,b[i]);
  //          printf("\n%lld ",p2); 
            ans+=(p1<(i+1)?p1:(i+1))*(p2<(r-i)?p2:(r-i));
        }

        /*    for(i=0;i<p;++i)
              printf("%d ",prefix1[i]);
              printf("\n");
              for(i=0;i<q;++i)
              printf("%d ",prefix2[i]);*/

        printf("%lld\n",ans);

    }
    return 0;
}
