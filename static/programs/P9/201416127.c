#include<stdio.h>
# define MAX 1001000
int main()
{
    long long int n,mod;
    long long int i,j,k,l;
        long long int temp;
    i=j=k=0;
    l=1;
        i=j=k=0;
        l=1;
        scanf("%lld",&n);
        long long int a[n],b[n],c[MAX];
        for(i=0;i<n;i++)
            a[i]=0;
        scanf("%lld",&mod);
        for(i=0;i<n;i++)
        {
            b[i]=k;
            scanf("%lld",&c[k]);
            l=k+1;
            j=0;
            while(j!=c[k])
            {
                scanf("%lld",&c[l]);
                a[i]=((a[i])%mod+(c[l])%mod)%mod;
                l++;
                j++;
            }
            a[i]=a[i]%mod;
            k=l;
        }
        for(i=0;i<(n-1);i++)
            for(j=0;j<(n-i-1);j++)
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    temp=b[j];
                    b[j]=b[j+1];
                    b[j+1]=temp;
                }
        for(i=0;i<n;i++)
        {
            printf("%lld\n",a[i]);
            k=b[i];
            for(j=b[i]+1;j<b[i]+c[k]+1;j++)
            {
                printf("%lld\n",c[j]);
            }
            printf("\n");
       // }
    }
    return 0;
}
