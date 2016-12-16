#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int N, A[1000000], n, i, j, k;

int Diff(int array[])
{
    int maxdiff = array[1] - array[0];
    int min_no = array[0];
    
    for (k = 1; k < n; k++)
    {       
        if(array[k] - min_no > maxdiff)                               
            maxdiff = array[k] - min_no;
        if(array[k] < min_no)
            min_no = array[k];                     
    }
    return maxdiff;
}
     
int main()
{
    scanf("%d", &N);
    
    for (i = 0; i < N; i++)
    {
        scanf("%d", &n);
        
        for (j = 0; j < n; j++)
        {
            scanf("%d", &A[j]);
        }
        
        if (Diff(A) > 0 )
        {
            printf("%d\n", Diff(A));
        }
        else
        {
            printf("%d\n", 0);
        }
    }
    return 0;
}
