#include<stdio.h>
#include<string.h>
int main()
{
    int n, t, i, max;
    int A[100000];
    scanf("%d", &t);
    while ( t-- )
    {
        int max =0;
        int result = 0;
        scanf("%d", &n);
        for( i=0; i<n; i++)
        {
            scanf("%d", &A[i]);
        }
        for( i=n-1; i>=0; i--)
        {
            if ( A[i] > max)
                max = A[i];

            int temp;
            temp = max - A[i];
            if ( temp>result)
                result  = temp;
        }
      printf("%d\n", result);
    }
    return 0;
}
