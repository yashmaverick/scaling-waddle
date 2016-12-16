#include <stdio.h>

#define MX 100000
#define din(x) scanf("%d", &x);

int S[MX];
int D[MX];
int A[MX];

int main(){
    int T, N, i, t, x, index;
    din(T);
    while(T--){
        din(N);
        for(i=0; i<N; i++){
            din(A[i]);
        }
        D[N-1] = 0;
        index = N-1;
        t = 0;
        S[t] = N-1; 
        for(i=N-2; i>=0; i--){
            x = S[t];
            while(t!=-1 && A[S[t]] > A[i]){
                x = S[t];
                t = t - 1;
            }
            D[i] = D[x] + 1;
            t = t + 1;
            S[t] = i;
            if(D[i] >= D[index]){
                index = i;
            }
        }
        printf("%d %d\n", A[index], D[index]);
    }
    return 0;
}
