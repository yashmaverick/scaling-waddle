#include<stdio.h>
int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int n,j;
        int tempj;
        scanf("%d",&n);
        int a[100010],min,max;
        max=-2147483648;
        min=2147483647;
        tempj=0;
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[j]);
            if(a[j]<min)
            {
                min=a[j];
                tempj=j;
            }
            if(a[j]>=min&&j>tempj)
                if(a[j]-a[tempj]>max)
                    max=a[j]-a[tempj];
        }
        if(max<=0)
            printf("0\n");
        else
            printf("%d\n",max);
    }
    return 0;
}
