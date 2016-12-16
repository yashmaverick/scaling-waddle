#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,i;
        scanf("%d",&n);
        int *a = (int *)malloc(4*n);
        int min=INT_MAX;
        int diff,maxdiff=INT_MIN;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<min)
                min = a[i];
            diff = a[i] - min;
            maxdiff = maxdiff>diff?maxdiff:diff;
        }
        free(a);
        printf("%d\n",maxdiff);
    }
    return 0;
}
