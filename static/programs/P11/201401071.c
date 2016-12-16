#include <stdio.h>
#include <stdlib.h>

#define INF (int)1e9

#define MAX 100010
#define max(a,b) (a)>(b)?(a):(b)

int S[MAX], top=-1;
int L[MAX], R[MAX], A[MAX];

void print_stack(){
    int i;
    printf("Stack: ");
    for(i=0; i<=top; i++)
        printf("%d ", A[S[i]]);
    printf("\n");
}

long long f(int *A, int n){
    int i, x;
    long long area = 0;
    A[0] = -INF;
    S[0] = 0;
    top = 0;
    for(i=1; i<=n;){
        if(A[i] >= A[S[top]])
            S[++top] = i++;
        else{
            x = S[top--];
            //printf("%d: %d, %d, %d\n", A[x], S[top], x, i);
            L[x] = x-S[top]-1;
            R[x] = i-x-1;
        }
        //print_stack();
    }
    while(S[top] != 0){
        x = S[top--];
        //printf("%d: %d, %d, %d\n", A[x], S[top], x, i);
        L[x] = x-S[top]-1;
        R[x] = i-x-1;
    }
    /*
    for(i=1; i<=n; i++)
        printf("%d ", A[i]);
    printf("\n");
    */
    for(i=1; i<=n; i++)
        area = max(area, (long long)A[i]*(long long)(L[i]+R[i]+1));
    return area;
    /*
    for(i=1; i<=n; i++)
        printf("%d (%d, %d)\n", A[i], L[i], R[i]);
    */
}

int main(){
    int N, i;
    scanf("%d", &N);
    while(N){
        for(i=1; i<=N; i++){
            scanf("%d", &A[i]);
        }
        printf("%lld\n", f(A, N));
        scanf("%d", &N);
    }
    return 0;
}
