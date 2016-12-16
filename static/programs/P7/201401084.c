#include <stdio.h>

long long int n;
long long int a[1000005];
long long int b[1000005];

void merge(long long int left,long long int mid,long long int right)
{
    long long int i=left;
    long long int j=mid+1;
    long long int k=left;
    long long int r,c;
    while(i<=mid && j<=right)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            i++;
            k++;
        }
        else
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        for(c=j;c<=right;c++)
        {
            b[k]=a[c];
            k++;
        }
    }
    else
    {
        for(c=i;c<=mid;c++)
        {
            b[k]=a[c];
            k++;
        }
    }
    for(r=left;r<k;r++)
    {
        a[r]=b[r];
    }
}



void msort(long long int left,long long int right)
{
    long long int i;
    if(left<right)
    {
        long long int mid=(left+right)/2;
        msort(left,mid);
        msort(mid+1,right);
        merge(left,mid,right);
     /*   for(i=left;i<=right;i++)
            printf("%d ",b[i]);
        printf("\n");*/
    }
}

  
int main()
{
    long long int i,t,m;
    scanf("%lld",&t);
    for(m=1;m<=t;m++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }        
        msort(0,n-1);
      //for(i=0;i<n;i++)
        //   printf("%lld ",a[i]);
        long long int min=a[0];
        long long int minp=0;
        long long int maxp;
        long long int d,c;
        c=0;
        long long int v=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==0)
                c++;
            if(a[i]==min)
            {
                maxp=i;
                if(i==n-1)
                {
                    d=(maxp-minp+1);
                    v=v+(d*(d-1))/2;
                }
            }
            else
            {
                d=(maxp-minp+1);
                v=v+(d*(d-1))/2;
                maxp=i;
                minp=i;
                min=a[i];
            }
        }
        printf("%lld\n",v);
    }
    return 0;
}

    
      
