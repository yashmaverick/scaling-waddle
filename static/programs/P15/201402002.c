#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,j,i;
        scanf("%d %d",&n ,&k);
        int arr[n];
        int inc=0,dec=0;

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        int min;
        int old_min=99999999;


        for (i = 0; i <= n-k; i++)
        {
            if (i==0)
            {
                min = arr[i];
                for (j = 1; j < k; j++)
                {
                    if (arr[i+j] < min)
                        min = arr[i+j];
                }
            }
            else if (arr[i+k-1] < old_min)
                min=arr[i+k-1];
            else if (arr[i-1]==old_min)
            {
                min = arr[i];
                for (j = 1; j < k; j++)
                {
                    if (arr[i+j] < min)
                        min = arr[i+j];
                }
            }

            if (i!=(n-k))
                printf("%d ", min);
            else
                printf("%d\n",min);
            old_min=min;
        }
    }
    return 0;
}
