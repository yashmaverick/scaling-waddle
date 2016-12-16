#include<stdio.h>
#include<string.h>
#define maxN 1000005

long long int arr[maxN],stc[maxN],area[maxN];

int main()
{
    long long int n;
    scanf("%lld",&n);
    while(n)
    {
        memset(arr,0,sizeof(arr));
        memset(stc,0,sizeof(stc));
        memset(area,0,sizeof(area));
        long long int i,end=-1,t;
        long long int maxarea=0;
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        for(i=0;i<n;i++)
        {
            while(end!=-1)
            {
                if(arr[i]<=arr[stc[end]])
                    end--;
                else
                    break;
            }
            if(end==-1)
                t=-1;
            else
                t=stc[end];
            area[i]=i-t-1;
            end++;
            stc[end]=i;
        }
        end=-1;
        for(i=n-1;i>=0;i--)
        {
            while(end!=-1)
            {
                if(arr[i]<=arr[stc[end]])
                    end--;
                else
                    break;
            }
            if(end==-1)
                t=n;
            else
                t=stc[end];
            area[i]=area[i]+t-i-1;
            end++;
            stc[end]=i;
        } 
        for(i=0;i<n;i++)
        {
            area[i]=arr[i]*(area[i]+1);
            if(maxarea<area[i])
                maxarea=area[i];
        }
        printf("%lld\n",maxarea);
        scanf("%lld",&n);
    }
    return 0;
}
