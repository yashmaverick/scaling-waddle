#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 100000
int cmpfunc (const void * a, const void * b);
int func(int n,int k,int a[]);

int main()
{
    int i,j,k,l,n,x,t;
    scanf("%d",&t);
    for(x=0;x<t;x++)
    {
        scanf("%d %d",&n,&k);
        int arr[n+1];
        
        for(i=0;i<n;i++)
        {
            char a[MAXLINE];
            scanf("%s %d",a,&arr[i]);
        }
        qsort(arr, n, sizeof(int), cmpfunc);
        int c=func(n,k,arr);
        if(c>0)
            printf("YES\n");
        else
            printf("NO\n");
    
    }
    return 0;
}

int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int func(int n,int k,int arr[])
{
    int i,j,l,flag=0;
    for(i=0;i<=n-3;i++)
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

return flag;
}
