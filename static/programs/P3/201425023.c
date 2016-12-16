#include<stdio.h>
int main()
{
    int t,n,a[100000],i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
        }
        int max=0;
        int min=a[0];
        int diff=0;
        for(j=1;j<n;j++)
        {
        if(a[j]<min)
            min=a[j];
        else if(a[j]>min && (a[j]-min)>diff)
            diff=a[j]-min;
        }
        printf("%d\n",diff);
    }
    return 0;
}





