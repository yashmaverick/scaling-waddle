#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

int N, strongerThan[1005][1005], weakerThan[1005][1005], wct[1005], sct[1005], defct, defeated[1005], n, victors[1005], count;

void defeat ( int node )
{
    defeated[node] = n;
    defct++;
    int i, j;
    for ( i = 0; i < sct[node]; i++ )
    {
        if ( defeated[strongerThan[node][i]] != n )
        {
            defeat(strongerThan[node][i]);
        }
    }
}

void reverse ( int node )
{
    defeated[node] = n;
    defct++;
    int i, j;
    for ( i = 0; i < wct[node]; i++ )
    {
        if ( defeated[weakerThan[node][i]] != n )
        {
            reverse(weakerThan[node][i]);
        }
    }
}

int main()
{
    int tcases, i, j, k, m;
    din(tcases);
    while ( tcases-- )
    {
        memset(sct,0,sizeof(sct));
        memset(wct,0,sizeof(wct));
        din(N);
        for ( i = 1; i <= N; i++ )
        {
            din(m);
            for ( j = 0; j < m; j++ )
            {
                din(k);
                weakerThan[i][wct[i]] = k;
                wct[i]++;
                strongerThan[k][sct[k]] = i;
                sct[k]++;
            }
        }

        for ( n = 1; n <= N; n++ )
        {
            defct = 0;
            defeat(n);
            if ( defct == N )
            {
                victors[0] = 1;
                defct = 0;
                memset(defeated,0,sizeof(defeated));
                reverse(n);
                break;
            }
        }
        if ( !victors[0] ) defct = 0;
        printf("%d\n",defct);
    }

    return 0;
}
