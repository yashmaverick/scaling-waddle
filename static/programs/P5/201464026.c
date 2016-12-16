#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,i,j,h;
        char buffer[1000];
        scanf("%d %d",&n,&k);
        int *a = (int *)malloc(4*n);
        for(i=0;i<n;i++)
            scanf("%s %d",buffer,&a[i]);
        qsort(a,n,4,cmpfunc);
        for(i=0;i<n-2;i++)
        {
            j = i+1;
            h = n-1;
            while(h>j)
            {
                if(a[i]+a[j]+a[h]==k)
                {
                    n = -1;
                    break;
                }
                (a[i]+a[j]+a[h]>k)?h--:j++;
            }
            if(n+1==0)
                break;
        }
        if(n+1)
            printf("NO\n");
        else
            printf("YES\n");
        free(a);
    }
    return 0;
}
