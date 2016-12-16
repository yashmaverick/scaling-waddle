#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    int i=0;

    for(i=0;i<t;i++)
    {
        long long int n,k,j;
        scanf("%lld %lld",&n ,&k);
        long long int arr[n];

        for(j=0;j<n;j++)
        {
            char s[10000];
            scanf(" %s %lld",s ,&arr[j]);
        }
        long long int a=0,b=0,c=0;
        int flag=0;
        for(a=0;a<n;a++)
        {
            if (arr[a]<k)
            {
                for(b=a+1;b<n;b++)
                {
                    long long int l=k-arr[a]-arr[b];
                    if (l>=0)
                    {
                        for(c=b+1;c<n;c++)
                            if (arr[c]==l)
                            {
                                printf("YES\n");
                                flag=1;
                                break;
                            }
                    }
                }
            }
            if(flag==1)
                break;
        }
        if (flag==0)
            printf("NO\n");
    }

    return 0;
}
