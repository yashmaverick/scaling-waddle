#include<stdio.h>
int main()
{while(1)
    {
    int n;
    scanf("%d",&n);
    if(n==0)
        break;
    if(n>1 && n<=5000000)
    {
        long long int a[n];
        long long int i,j,k;
        long long int count=0;
        for(i=0;i<n;i++)
            scanf("%lld",&a[i]);
        for(i=0;i<n-2;i++)
            for(j=i+2;j<n;j++)
                for(k=i+1;k<j;k++)
                    if(a[k]>a[i] || a[k]>a[j])
                    {
                        count++;
                        break;
                    }
        printf("%lld\n",count);
    }
    }
    return 0;
}
