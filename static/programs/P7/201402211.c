#include<stdio.h>
#include<math.h>
#include<string.h>

#define din(N) scanf("%d",&N)
#define llin(N) scanf("%lld",&N)
#define sin(N) scanf("%s",&N)
#define fin(N) scanf("%lf",&N)
#define chin(N) scanf(" %c",&N)

typedef long long ll;

int A[1000005];

void mergesort ( int arr[], int N )
{
    if ( N == 1 ) return;
    else
    {
        mergesort ( arr, N/2 );
        mergesort ( arr+(N/2), N-(N/2) );

        int i = 0, j = N/2, k = 0, newarr[N];
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
    int N, tcases, i, j, k;
    din(tcases);
    while ( tcases-- )
    {
        din(N);
        for ( i = 0; i < N; i++ )
        {
            din(A[i]);
        }

        mergesort(A,N); A[N] = (1 << 30);
        ll total = 0, curr = 0;
        //for ( i = 0; i < N; i++ ) printf("%d ",A[i]); printf("\n");
        for ( i = 1; i <= N; i++ )
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
