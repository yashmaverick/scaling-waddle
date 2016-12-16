#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return ( *(int*)a-*(int*)b);
}
int main()
{
    int t,i,j,l;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
       
    int len,j,l;
    long long int ans;
    int arr[1000010];
    long long int count;
        ans=0;
        scanf("%d",&len);
        for(j=0;j<len;j++)
            scanf("%d",&arr[j]);
        qsort(arr,len,4,cmpfunc);
        int k=0;
        int temp=arr[0];
        count=1;
        for(j=1;j<len;j++)
        {
            if(arr[j]==temp)
            {
                temp=arr[j];
                count++;
            }
            else
            {
                ans=ans+((count)*(count-1))/2;
                count=1;
                temp=arr[j];
            }
        }
        ans=ans+((count)*(count-1))/2;
        printf("%lld\n",ans);
    }
    return 0;
}
