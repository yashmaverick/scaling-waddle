    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
#define mod 1000000007
    long long int n;
    int powe(long long int x, long long int y);
void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*));
int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
int binarysearch(int a[],int m,int n,int j)
{
 int l,u,mid;
l=j,u=n-1;
    while(l<=u)
        {
         mid=(l+u)/2;
         if(m==a[mid])
            {
             int c=1;
             break;
         }
         else if(m<a[mid])
            {
             u=mid-1;
         }
         else
             l=mid+1;
    }
    return mid;
}
    
    int main(){
    int t;
    scanf("%d",&t);
    while(t--)
    {
    long long int ans=0,left;
    long long int i,j,k;
    long long int x,y,z;
    long long int right,right1,right2;
    long long int d,m;
    long long int count1=0;
    scanf("%lld %lld %lld %lld",&right,&d,&m,&n);
    long long int a[100],count[100];
    for(i=0;i<n;i++)
    count[i]=1;
    for(i=0;i<n;i++)
    a[i]=powe(i,d);
    for(i=0;i<n;i++)
    {
    right1=right/n;
    count[i]=(count[i]*right1);
    }
    right2=right%n;
    for(i=0;i<=right2;i++)
    count[i]=(count[i]+1);
    if(right<n)
    left=right+1;
    else
    left=n;
    for(i=0;i<left;i++)
    {
    for(j=0;j<left;j++)
    {
    for(k=0;k<left;k++)
    {
    if((a[i]+a[j]+a[k])%n==m)
    count1=count1+(((count[i]*count[j])%mod)*count[k])%mod;
    }
    }
    }
    printf("%lld\n",count1%mod);
    }
    return 0;
    } 
    int powe(long long int x, long long int y)
    {
    long long int swap;
    if( y == 0)
    return 1;
    int r;
    swap = (powe(x, y/2));
    if (y%2 == 0)
    r= (swap*swap)%n;
    else
    r=(((x*swap)%n)*swap)%n;
return r;
    }