#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,k,l,n,j;
        scanf("%d %d",&n,&k);
        int arr[n+1],flag=0;
        for(i=0;i<n;i++)
        {
            char a[10000];
            scanf("%s %d",&a,&arr[i]);
        }
        qsort(arr, n, sizeof(int), cmpfunc);
        for(i=0;i<n-2;i++)
        {
            j=i+1;
            l=n-1;
            while(j<l)
            {
                if(arr[i]+arr[j]+arr[l]==k)
                {
                    flag=1;
                    break;
                }
                else if(arr[i]+arr[j]+arr[l]<k)
                    j++;
                else
                    l--;
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            printf("NO\n");
        if(flag==1)
            printf("YES\n");
    }
    return(0);
}
