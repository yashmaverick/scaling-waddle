#include <stdio.h>

long long int a[100005],b[100005],c[100005],p,q,r,ans;
void func(void)
{
    long long int i,j,m,n,k;
    for(i=0;i<q;i++)
    {
        long long int left=0;
        long long int right=i;
        k=b[i];
        if(right>p-1)
            right=p-1;
	m=-1;
        while(left<=right)
        {
            if(a[right]<=k)
            {
                m=right;
                break;
            }
            long long int mid=(left+right)/2;
            if(a[mid]==k)
            {
                m=mid;
                left=mid+1;
            }
            if(a[mid]>k)
            {
                right=mid-1;
                if(a[mid]<=k && a[mid+1]>k)
                {
                    m=mid;
                    break;
                }
            }
            else if(a[mid]<k)
            {
                left=mid+1;
                if(a[mid+1]>k)
                {
                    m=mid;
                    break;
                }
            }    
        }
        left=i;
        right=r-1;
        n=r;
        while(left<=right)
        {
            if(c[r-1]<k)
            {
                n=r;
                break;
            }
            long long int mid=(left+right)/2;
            if(c[mid]>=k)
            {
                n=mid;
                right=mid-1;
            }
            else if(c[mid]<k)
            {
                left=mid+1;
            }
        }
        ans+= (m+1)*(r-n);
    }
}

int main()
{
    int i,t;
    scanf("%d",&t);
   while(t--)
    {    
        ans=0;
        scanf("%lld",&p);
        for(i=0;i<p;i++)
            scanf("%lld",a+i);
        scanf("%lld",&q);
        for(i=0;i<q;i++)
            scanf("%lld",b+i);
        scanf("%lld",&r);
        for(i=0;i<r;i++)
            scanf("%lld",c+i);
        func();
        printf("%lld\n",ans);
    }
    return 0;
}


