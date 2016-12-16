#include<stdio.h>
#define INT_MAX 1000000000
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,sum=0,i=0,a;
        int min=INT_MAX;
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
            if(min>a)
                min=a;
            if(a-min>sum)
                sum=a-min;

    //        printf("current sum is %lld and current posible is %lld and indexes are %d & %d\n",sum,max[0]-min[0],max[1],min[1]);


        }
printf("%lld\n",sum);
    }
return 0;
}

