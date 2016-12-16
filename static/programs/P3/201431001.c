#include<stdio.h>
#define MAX 100001

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int na;
        scanf("%lld",&na);
        long long int i,arr[MAX];

        for(i=0;i<na;i++)
        {    
            scanf("%lld",&arr[i]);
        }

        long long int prevmin=arr[0],max=-1;
        for(i=0;i<na;i++)
        {
            if(max<(arr[i]-prevmin))
                max=arr[i]-prevmin;
            if(arr[i]<prevmin)
                prevmin=arr[i];
        }
        if(max>0)
            printf("%lld\n",max);
        else
            printf("0\n");
    }
    return 0;
}
