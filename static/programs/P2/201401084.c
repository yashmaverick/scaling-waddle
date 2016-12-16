#include <stdio.h>

long long int a[100000];
long long int b[100000];
long long int c[100000];
long long int p,q,r;
//int x[100000];
//int y[100000];
long long int s;

void merge1()
{
    long long int i;
    long long int j;
    long long int m,n;
    long long int k;
    for(i=0;i<q;i++)
    {
        long long int left=0;
        long long int right=i;
        k=b[i];
        if(right>p-1)
            right=p-1;
       // printf("right=%d ",right);
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
       // printf("m=%d\n",m);
        left=i;
        right=r-1;
        n=r;
     //   printf("left=%d right=%d\n",left,right);
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
       //   printf("left=%d right=%d mid=%d\n",left,right,mid);
        }
       // printf("n=%d\n",n);
        s=s+(m+1)*(r-n);
       // printf("s=%lld m=%d n=%d\n",s,m,n);
    }
}


int main()
{
    long long int t,m,i;
    scanf("%lld",&t);
    for(m=1;m<=t;m++)
    {    
        s=0;
        scanf("%lld",&p);
        for(i=0;i<p;i++)
            scanf("%lld",&a[i]);
        scanf("%lld",&q);
        for(i=0;i<q;i++)
        {
            scanf("%lld",&b[i]);
        }
        scanf("%lld",&r);
        for(i=0;i<r;i++)
        {
            //  printf("r=%d",r);
            scanf("%lld",&c[i]);
        }
        merge1();
        printf("%lld\n",s);
    }
    return 0;
}


