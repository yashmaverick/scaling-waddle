#include<stdio.h>
typedef long long lint; 
lint lower_limit(lint key,lint l,lint r,lint * arr)
{
    lint i;
    while(l<r)
    {
        lint mid=l+(r-l)/2;
        if(arr[mid]>key)
            r=mid-1;
        else if(arr[mid]==key)
            return mid;
        else
            l=mid;
        if(r-l<=2)
            break;
//        printf("%d %d\n",l,r);
    }
    for(i=r;i>=l;i--)
        if(arr[i]<=key)
            return i;
    return 0;
}
lint upper_limit(lint key,lint l,lint r,lint *arr)
{
    lint i;
    while(l<r)
    {
        lint mid=l+(r-l)/2;
        if(arr[mid]>key)
            r=mid;
        else if(arr[mid]==key)
            return mid;
        else
            l=mid+1;
        if(r-l<=2)
            break;
    }
    for(i=l;i<=r;i++)
        if(arr[i]>=key)
            return i;
    return r+1;
}
int main()
{
    lint p,q,r,t,i;
    lint A[100010],B[100010],C[100010],smaller_on_left[100010],larger_on_right[100010];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&p);
        for(i=1;i<=p;i++)
            scanf("%lld",&A[i]);

        scanf("%lld",&q);
        for(i=1;i<=q;i++)
            scanf("%lld",&B[i]);

        scanf("%lld",&r);
        for(i=1;i<=r;i++)
            scanf("%lld",&C[i]);

        for(i=1;i<=q;i++)
        {
                if(i<=p && A[i]<=B[i])
                    smaller_on_left[i]=i;
                else
                    smaller_on_left[i]=lower_limit(B[i],1,i-1,A);
        }
        for(i=1;i<=q;i++)
        {
                if(i<=r && B[i]<=C[i])
                    larger_on_right[i]=r-i+1;
                else
                    larger_on_right[i]=r-upper_limit(B[i],i+1,r,C)+1;
        }
        long long int ans=0;
        for(i=1;i<=q;i++)
        {
//            printf("#smaller on left: %d    ",smaller_on_left[i]);
//            printf("#larger on right: %d\n",larger_on_right[i]);
            ans+=((long long)smaller_on_left[i]*larger_on_right[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
