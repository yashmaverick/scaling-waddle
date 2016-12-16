//DS Assignment 2, P16
#include<stdio.h>
int main()
{
    int nofQueries;
    long long query, powersOfTwo[31], pOT_value = 1, midpoint, i;
    for(i = 0; i < 31; i++) //initializing powers of two
    {
        powersOfTwo[i] = pOT_value;
        pOT_value *= 2;
    }
/*    printf("Powers of two: ");
    for(i = 0; i < 31; i++)
    {
        printf("%lld ", powersOfTwo[i]);
    }
    printf("\n");*/
    scanf("%d", &nofQueries);
    while(nofQueries--)
    {
        scanf("%lld", &query);
        for(i = 0; query >= powersOfTwo[i]; i++) //getting a val to get level of the query
        {
            continue;
        }
//        printf("got i = %lld\n", i);
        i--;
        midpoint = powersOfTwo[i]/2;
        midpoint += powersOfTwo[i];
        if(query < midpoint)
        {
            printf("%lld\n", (2*i)-1);
        }
        else
        {
            printf("%lld\n", 2*i);
        }
    }
    return 0;
}
