#include<stdio.h>
int compare(const void *p,const void *q)
{
    return ((*(long long int*)p-*(long long int*)q));
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int a[n];
        int i;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        qsort(a,n,sizeof(long long int),compare);
        long long int c=0,m=1;
        for(i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
                m++;
            else
            {
                c+=m*(m-1)/2;
                m=1;
            }
        }
        c+=m*(m-1)/2;
        printf("%lld\n",c);
    }
}



