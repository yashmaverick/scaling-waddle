#include<stdio.h>
#define max(a,b) ((a>b)? a:b)
#define min(a,b) ((a<b)? a:b )
#define ll long long int
ll findindexleft(ll a[],ll low,ll high,ll key,ll n)
{
        if(key<a[0])
                return 0;
        if(key>=a[n-1])
                return n;
        while(low<=high)
        {
                ll mid=(low+high)/2;
                
                if(a[mid]<=key&&a[mid+1]>key)
                        return mid+1;
                else if(a[mid]>key)
                        return findindexleft(a,low,mid-1,key,n);
                else
                        return findindexleft(a,mid+1,high,key,n);
        }

}
ll findindexright(ll c[],ll low,ll high,ll key,ll n)
{
        if(key<=c[0])
                return n; 
        if(key>c[n-1])
                return 0;
        while(low<=high)
        {
                ll mid=(low+high)/2;
                
                if(c[mid]<key&&c[mid+1]>=key)
                        return n-mid-1;
                else if(c[mid]>=key)
                        return findindexright(c,low,mid-1,key,n);
                else 
                        return findindexright(c,mid+1,high,key,n);
        }

}

int main()
{
        ll t,i,j,k,l,p,q,r,count,a[100000],b[100000],c[100000],left,right;
        scanf("%lld",&t);
        for(i=0;i<t;i++)
        {
                count=0;
                scanf("%lld",&p);
                for(j=0;j<p;j++)
                        scanf("%lld",&a[j]);
                scanf("%lld",&q);
                for(j=0;j<q;j++)
                        scanf("%lld",&b[j]);
                scanf("%lld",&r);
                for(j=0;j<r;j++)
                        scanf("%lld",&c[j]);
                //printf("%d %d\n",q,r);
                //printf("%d\n",min(q,r));

                for(j=0;j<min(q,r);j++)
                {
                        left=findindexleft(a,0,p-1,b[j],p);
                        right=findindexright(c,0,r-1,b[j],r);
                       //printf("%d %d %d\n",left,right,count);
                        count+=(min(left,j+1)*min(right,r-j));

      //printf("%d ", count);
                }
                printf("%lld\n",count);
        }
        return 0;
}
