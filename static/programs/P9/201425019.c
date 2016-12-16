#include<stdio.h>
#include<stdlib.h>

typedef struct bags
{
    int s , length , e ;
    long long weight ;
}x;

int main()
{
    int start=0 , end , i , a , NUMBER , M ;
    long long MOD , W , itemweight[1000005];
    struct bags* b;
    scanf("%d" , &NUMBER);
    scanf("%lld" , &MOD);
    b = (struct bags*) malloc(sizeof(struct bags)*NUMBER);
    for(i=0 ; i<NUMBER ; i++)
    {
        scanf("%d" , &b[i].length);
        b[i].s = start;
        for(a=start ; a<(start+b[i].length) ; a++)
        {
            scanf("%lld" , &itemweight[a]);
            b[i].weight += itemweight[a];
            b[i].weight %= MOD;
        }
        b[i].e = a ;
        start = a ;
    }
    

        
        for (i = 1 ; i <= NUMBER - 1; i++) 
        {
            a = i;
    
            while ( a > 0 && b[a].weight < b[a-1].weight) 
            {
                struct bags t = b[a];
                b[a] = b[a-1];
                b[a-1] = t;
                a--;
            }
        }
        
    for(a=0 ; a<NUMBER ; a++)
    {
        printf("%lld\n" , b[a].weight);
        for(i=b[a].s ; i<b[a].e ; i++)
            printf("%lld\n" , itemweight[i]);
        printf("\n");
    }
    return 0;
}