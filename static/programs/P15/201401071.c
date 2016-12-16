#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000

int A[MAX], U[MAX];

void f(int *B, int N, int K){
    int h=0, t=-1, i, j;
    for(i=0; i<N; i++){
        while( t>=h && B[i] <= B[U[t]]){
            t--;
        }
        U[++t] = i;
        while(U[h] <= i-K)
            h++;
        if(i>=K-1)
            printf("%d%s", B[U[h]], (i==N-1)?"\n":" ");
    }
}

int main(){
    int T, N, K, i;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &K);
        for(i=0; i<N; i++){
            scanf("%d", &A[i]);
        }
        f(A, N, K);
    }
    return 0;
}
