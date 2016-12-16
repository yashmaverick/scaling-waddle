#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

int neigh[10000][100], primes[10000], primec, ct[10000], first, vis[10000];

void primegen()
{
    int i, j, k, prime;
    primec = 1; primes[0] = 2;
    for ( i = 3; i < 10000; i++ )
    {
        prime = 1;
        for ( j = 0; primes[j] * primes[j] <= i; j++ )
        {
            if ( i % primes[j] == 0 )
            {
                prime = 0;
                break;
            }
        }
        if ( prime )
        {
            if ( !first && i >= 1000 )
            {
                first = primec;
            }
            primes[primec] = i;
            primec++;
        }
    }
    //for ( i = 0; i < 100; i++ ) printf("%d ",primes[i]);
}

int gen()
{
    primegen();
    int i, j, k;
    for ( i = first; i < primec; i++ )
    {
        for ( j = first; j < primec; j++ )
        {
            if ( i != j )
            {
                int count = 0, p1 = primes[i], p2 = primes[j];
                while ( p1 )
                {
                    if ( p1 % 10 == p2 % 10 )
                    {
                        count++;
                    }
                    p1 /= 10; p2 /= 10;
                }
                if ( count == 3 )
                {
                    //printf("%d %d\n",primes[i],primes[j]);
                    neigh[primes[i]][ct[primes[i]]] = primes[j]; ct[primes[i]]++;
                    neigh[primes[j]][ct[primes[j]]] = primes[i]; ct[primes[j]]++;
                    //if ( ct[primes[i]] > 100 || ct[primes[j]] > 100 ) printf("NOO");
                }
            }
        }
    }
}

int min, tar, cur, q[100005], qc[100005];
int dfs ( int num, int dep )
{
    q[0] = num; qc[0] = 0; int i, lef = 0, rig = 1, count = 0;
    while ( 1 )
    {
        if ( vis[q[lef]] == cur )
        {
            lef++;
            continue;
        }
        //printf("%d\n",q[lef]); //getchar();
        vis[q[lef]] = cur;
        if ( q[lef] == tar ) break;
        for ( i = 0; i < ct[q[lef]]; i++ )
        {
            if ( vis[ neigh[q[lef]][i] ] != cur )
            {
                q[rig] = neigh[q[lef]][i];
                qc[rig] = qc[lef]+1;
                rig++;
            }
        }
        lef++;
    }
    if ( q[lef] != tar ) count = -1;
    else count = qc[lef];
    return count;
}

  /*  
    
    printf("%d\n",num);
    vis[num] = cur;
    if ( num == tar )
    {
        if ( dep < min )
        {
            min = dep;
        }
    }
    int i, j;
    for ( i = 0; i < ct[num]; i++ )
    {
        if ( vis[ neigh[num][i] ] != cur )
        {
            dfs(neigh[num][i],dep+1);
        }
    }
}*/

int main()
{
    gen();
    int tcases;
    din(tcases);
    cur = 1; 
    while ( tcases-- )
    {
        int X, Y;
        din(X); din(Y);
        min = 1000; cur++;
        tar = Y;
        printf("%d\n",dfs(X,0));
        cur++;
    }


    return 0;
}
