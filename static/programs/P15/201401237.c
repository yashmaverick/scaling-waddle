#include<stdio.h>

int main()
{
    long long int i,n,k,t,rmin,lmin;
    scanf("%lld",&t);
    while(t--)
    {
    scanf("%lld %lld",&n,&k);
    long long int arr[n],right[n],left[n];
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    //go right side
    for(i=0;i<n;i++)
    {
        //if i mod k then make count 0;
        if(i%k ==0)
            rmin=arr[i];
        else if(arr[i]<rmin)
            rmin=arr[i];
        right[i]=rmin;
    }
    //go left side
    long long int x=n%k;
    lmin=arr[n-1];
    for(i=n-1;i>=0;i--)
    {
         
        if(x>0)
        {
           if(arr[i]<lmin)
               lmin=arr[i];
           left[i]=lmin;
            x--;
            continue;
        }
        //after fixing var end
        if((i+1)%k==0)
            lmin=arr[i];
        else if(arr[i]<lmin)
            lmin=arr[i];
        left[i]=lmin;
    }
    /*for(i=0;i<n;i++)
        printf("%d ",right[i]);
    printf("\n");
    for(i=0;i<n;i++)
            printf("%d ",left[i]);*/
    //printf("%d %d",n,k);
    for(i=0;i<(n-k+1);i++)
    {
        //printf("\n%d %d %d\n",i,right[i+k-1],left[i]);
        long long int x=right[i+k-1]<left[i] ? right[i+k-1] : left[i];
        if(i!=(n-k))
        {
            printf("%lld ",x);
        }
        else
        {
            printf("%lld",x);
        }
    }
    printf("\n");
    }  
    
    return 0;
}
