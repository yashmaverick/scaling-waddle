//DS Assignment 2, P9
#include<stdio.h>
#define MAXBAGS 1000
long long input[1000000], sum[MAXBAGS];
int size[MAXBAGS], start[MAXBAGS];
void swapLL(long long *op1, long long *op2)
{
    long long temp;
    temp = *op1;
    *op1 = *op2;
    *op2 = temp;
    return;
}
void swapInt(int *op1, int *op2)
{
    int temp;
    temp = *op1;
    *op1 = *op2;
    *op2 = temp;
    return;
}
int main()
{
    int nofBags, i, nofItems, arrayEnd, j;
    long long weight, totWt, temp, mod;
    scanf("%d %lld", &nofBags, &mod);
    arrayEnd = 0;
    for(i = 0; i < nofBags; i++) //input loop
    {
        totWt = 0;
        start[i] = arrayEnd;
        scanf("%d", &nofItems);
        size[i] = nofItems;
        for(j = arrayEnd; j < arrayEnd+nofItems; j++)
        {
            scanf("%lld", &input[j]);
            totWt += input[j];
            totWt %= mod;
        }
        sum[i] = totWt;
        arrayEnd += nofItems;
    }
/*    printf("Before sort:\n");
    printf("SIZES: ");
    for(i = 0; i < nofBags; i++)
    {
        printf("%d ", size[i]);
    }
    printf("\n");
    printf("SUMS: ");
    for(i = 0; i < nofBags; i++)
    {
        printf("%lld ", sum[i]);
    }
    printf("\n");
    printf("STARTS: ");
    for(i = 0; i < nofBags; i++)
    {
        printf("%d ", start[i]);
    }
    printf("\n");*/
    for(i = 0; i < nofBags-1; i++) //sorting the bags
    {
        for(j = 0; j < nofBags-1-i; j++)
        {
            if(sum[j] > sum[j+1])
            {
                swapLL(&sum[j], &sum[j+1]);
                swapInt(&size[j], &size[j+1]);
                swapInt(&start[j], &start[j+1]);
            }
        }
    }
/*    printf("After sort:\n");
    printf("SIZES: ");
    for(i = 0; i < nofBags; i++)
    {
        printf("%d ", size[i]);
    }
    printf("\n");
    printf("SUMS: ");
    for(i = 0; i < nofBags; i++)
    {
        printf("%lld ", sum[i]);
    }
    printf("\n");
    printf("STARTS: ");
    for(i = 0; i < nofBags; i++)
    {
        printf("%d ", start[i]);
    }*/
    //printf("\n");
    for(i = 0; i < nofBags; i++) //output loop
    {
        printf("%lld\n", sum[i]);
        for(j = start[i]; j < start[i]+size[i]; j++)
        {
            printf("%lld\n", input[j]);
        }
        printf("\n");
    }
    return 0;
}
