#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf(" %s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

ll A[1000005];
char stri[100005];

void mergesort ( ll arr[], ll N )
{
    if ( N == 1 ) return;
    else
    {
        mergesort ( arr, N/2 );
        mergesort ( arr+(N/2), N-(N/2) );

        ll i = 0, j = N/2, k = 0, newarr[N];
        while ( k < N )
        {
            if ( i == N/2 ) newarr[k++] = arr[j++];
            else if ( j == N ) newarr[k++] = arr[i++];
            else
            {
                if ( arr[i] < arr[j] ) newarr[k++] = arr[i++];
                else newarr[k++] = arr[j++];
            }
        }

        for ( i = 0; i < N; i++ ) arr[i] = newarr[i];
    }
}

int main()
{
    ll N, tcases, i, j, k;
    llin(tcases);
    while ( tcases-- )
    {
        scanf(" %s",stri);
        N = strlen(stri);
        A[0] = 0;
        for ( i = 0; i < N; i++ )
        {
            switch ( stri[i] ) {
                case 'J'    :   A[i+1] = A[i] + 1; break;
                case 'M'    :   A[i+1] = A[i] + 100000; break;
                case 'R'    :   A[i+1] = A[i] - 100001; break;
            }
            //printf("%lld ",A[i+1]);
        }
        //printf("\n");

        mergesort(A,N+1); A[N+1] = 1; A[N+1] <<= 50;
        ll total = 0, curr = 0;
        //for ( i = 0; i <= N+1; i++ ) printf("%lld ",A[i]); printf("\n");
        for ( i = 1; i <= N+1; i++ )
        {
            if ( A[i] != A[i-1] )
            {
                total += ((i-curr)*(i-curr-1))/2;
                curr = i;
            }
        }
        printf("%lld\n",total);
    }


    return 0;
	
}
