#include<stdio.h>
int main()
{
    int N , n , head , tail , occu , i ;
    head = 0;
    tail = -1;
    occu = 0;
    scanf("%d",&N);
    char c = getchar();
    char a[1000][110];
    while( c != 'Q' )
    {
        if( c == 'A' )
        {
            scanf("%d",&n);
            while( n-- )
            {
                tail = ( ++tail ) % N;
                if( tail == head && occu == N)
                {
                    head = ( ++head ) % N;
                }
                if( occu < N)
                {
                    occu++;
                }
                scanf("%s",a[tail]);
            }
        }
        if( c == 'R' )
        {
            scanf("%d",&n);
            if( occu == n )
            {
                head = 0;
                tail = -1;
                occu = 0;
            }
            else
                while( n-- )
                {
                    head = ( ++head ) % N;
                    if( occu > 0 )
                        occu--;
                }
        }
        if( c == 'L' )
        {
            if( tail >= head )
            {
                for( i = head ; i <=  tail ; i++ )
                    printf("%s\n",a[i]);
            }
            else if( tail < head && tail != -1 )
            {
                for( i = head ; i < N ; i++ )
                    printf("%s\n",a[i]);
                for( i = 0 ; i <= tail ; i++ )
                    printf("%s\n",a[i]);
            }
        }
        c=getchar();
    }
    return 0;
}
