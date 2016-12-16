#include<stdio.h>
int main()
{
    int t=0,n;
    scanf("%d",&n);
    while(t<n)
    {
        long long int m;
             int count=0;
        scanf("%lld",&m);
        while(m>3)
        {
            m=m/2;
            count++;
        }
        if(m==2)
            printf("%d\n",count+count+1);
        else if(m==3)
            printf("%d\n",count+count+2);
        else
            printf("0\n");
        t++;
    }
    return 0;
}
