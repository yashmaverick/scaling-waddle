#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void * c, const void * d)
{
    return( *(long long int *)c - *(long long int *)d);
}
int check(long long num,long long int a[],int n)
{
    int f,l,m;
    f=0;
    l=n-1;
    m=(f+l)/2;
    while(f<=l)
    {
        if(num<a[m])
            l=m-1;
        if(num==a[m])
        {
            return 1;
        }
        if(num>a[m])
            f=m+1;
        m=(f+l)/2;
    }
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long a[100000],b[1000000];
        int i;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        int j=0;
	long long m;
        for(i=0;i<n;i++)
        {
            m=a[i]/10;
            while(m!=0)
            {
                b[j]=m;
                m=m/10;
                j++;
            }
        }
        m=j;
        int flag=0;
        qsort(a,n,sizeof(long long int),cmpfunc);
        for(i=1;i<n;i++)
        {
            if(a[i-1]==a[i])
            {
                printf("NO\n");
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            qsort(b,j,sizeof(long long int),cmpfunc);
            for(i=0;i<n;i++)
            {
                flag=check(a[i],b,j);
                if(flag==1)
                {
                    printf("NO\n");
                    break;
                }
            }
        }
        if(n>0)
        {
            if(flag==0)
                printf("YES\n");
        }
    }
    return 0;
}
