#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

int S[MAX], A[MAX], d[MAX];

void print_stack(int top){
    int i;
    fprintf(stderr, "Stack: ");
    for(i=0; i<=top; i++)
        fprintf(stderr, "%d ", S[i]);
    fprintf(stderr, "\n");
}

void f(int N){
    int st=-1;
    int x, maxd=0, e, i;
    S[++st] = A[N-1];
    d[A[N-1]] = 0;
    e = A[N-1];
    for(i=N-2; i>=0; i--){
        if(A[i]>S[st]){
            d[A[i]] = d[S[st]]+1;
            S[++st] = A[i];
        }
        else{
            while(S[st] > A[i])
                x = S[st--];
            d[A[i]] = d[x]+1;
            S[++st] = A[i];
        }
        if(d[A[i]] > maxd){
            e = A[i];
            maxd = d[A[i]];
        }
        else if(d[A[i]] == maxd){
            if(A[i] < e) e = A[i];
        }
    }
    printf("%d %d\n", e, maxd);
}

int main(){
    int N, T, i;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(i=0; i<N; i++){
            scanf("%d", &A[i]);
        }
        f(N);
    }
    return 0;
}
