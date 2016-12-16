#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n>0)
    {
        int i,k;
        long long diff,min,a[100003];
        scanf("%d",&k);
        for(i=0;i<k;i++)
            scanf("%lld",&a[i]);
        min=a[0];
        diff=a[1]-a[0];
        for(i=1;i<k;i++)
        {
            if((a[i]-min)>diff)
                diff=a[i]-min;
            if(a[i]<min)
                min=a[i];
        }
        if(diff<0)
            diff=0;
        printf("%lld\n",diff);
        n--;
    }
    return 0;
}
