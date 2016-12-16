#include<stdio.h>
typedef long long ll;

ll data[1000100];
ll datait;

ll N, MOD;

struct bag {
    ll size;
    ll datapoint;
    ll weight;
} bags[1001];

ll sorted[1001];

int smallerbag( ll m, ll n )
{
    if ( bags[m].weight <= bags[n].weight ) return 1;
    return 0;
}

void mergesort ( ll arr[], ll M )
{
    if ( M <= 1 ) return; int p;
    //printf("> "); for ( p = 0; p < M; p++ ) printf("%lld ",arr[p]); printf("\n");
    mergesort(arr,M/2);
    mergesort(arr+M/2, M-(M/2));
    //printf("< "); for ( p = 0; p < M; p++ ) printf("%lld ",arr[p]); printf("\n");

    ll i, left = 0, righ = M/2, newarr[M];
    for ( i = 0; i < M; i++ )
    {
        if ( left == M/2 )
        {
            newarr[i] = arr[righ];
            righ++;
        }
        else if ( righ == M )
        {
            newarr[i] = arr[left];
            left++;
        }
        else if ( smallerbag(arr[left],arr[righ]) )
        {
            newarr[i] = arr[left];
            left++;
        }
        else
        {
            newarr[i] = arr[righ];
            righ++;
        }
    }
    for ( i = 0; i < M; i++ ) arr[i] = newarr[i];
    //printf("# "); for ( i = 0; i < M; i++ ) printf("%lld ",arr[i]); printf("\n");
}


int main()
{
    scanf("%lld",&N);
    scanf("%lld",&MOD);
    datait = 0;
    ll i, j, k;
    for ( i = 0; i < N; i++ )
    {
        sorted[i] = i;
        bags[i].datapoint = datait;
        bags[i].weight = 0;
        scanf("%lld",&bags[i].size);
        for ( j = 0; j < bags[i].size; j++ )
        {
            scanf("%lld",&data[datait]);
            bags[i].weight += data[datait];
            bags[i].weight %= MOD;
            datait++;
        }
    }

    mergesort(sorted,N);

    for ( i = 0; i < N; i++ )
    {
        ll id = sorted[i];
        printf("%lld\n",bags[id].weight);
        for ( j = bags[id].datapoint; j < bags[id].datapoint + bags[id].size; j++ )
        {
            printf("%lld\n",data[j]);
        }
        printf("\n");
    }
    return 0;
}
