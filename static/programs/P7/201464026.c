#include<stdio.h>
#include<stdlib.h>
int cmpfunc(const void *a,const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,n,temp;
        long long int count=1,sum=0;
        scanf("%d",&n);
        int *a = (int *)malloc(4*n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        qsort(a,n,4,cmpfunc);
        temp = a[0];
        for(i=1;i<n;i++)
        {
            if(temp == a[i])
                count++;
            else
            {
                sum += (count*(count-1))/2;
                temp = a[i];
                count = 1;
            }
        }
        sum += (count*(count-1))/2;
        printf("%lld\n",sum);
        free(a);
    }
    return 0;
}
