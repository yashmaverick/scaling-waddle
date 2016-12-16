#include<stdio.h>

char list[10001][101];

int N, in, re;

int next ( int i )
{
    return i < N-1 ? i+1 : 0;
}

int main()
{
    scanf("%d",&N);
    char com;
    int n, i, j, k, run = 1;
    in = re = -1;
    while ( run )
    {
        scanf(" %c",&com);
        
        switch ( com )
        {
            case 'A'    :
                scanf("%d",&n);
                for ( i = 0; i < n; i++ )
                {
                    in = next(in);
                    scanf(" %s",list[in]);
                    if ( in == re ) re = next(re);
                    if ( re == -1 ) re = 0;
                }
                break;
            case 'R'    :
                scanf("%d",&n);
                for ( i = 0; i < n; i++ )
                {
                    re = next(re);
                }
                if ( re == next(in) && n )
                {
                    in = re = -1;
                }
                break;
            case 'L'    :
                if ( re == -1 ) break;
                int trav = 1;
                for ( i = re; i != next(in) || trav; i = next(i) )
                {
                    printf("%s\n",list[i]);
                    trav = 0;
                }
                break;
            case 'Q'    :
                run = 0;
                break;
        }
        //printf("::%d %d\n",in,re);
    }

    return 0;
}
