#include<stdio.h>
int main()
{

    int i,no,n;
    scanf("%d",&no);
    while(no--)
    {

        scanf("%d",&n);
        long long int array[n];
        for(i=0;i<n;i++)
            scanf("%lld",&array[i]);
        long long int min=1000000000;
        long long int max=0;
        for(i=0;i<n;i++)
        {
            if(array[i]<min)
                min=array[i];
            if((array[i]-min)>max)
                max=array[i]-min;
        }
        printf("%lld\n",max);

    }
    return 0;
}
