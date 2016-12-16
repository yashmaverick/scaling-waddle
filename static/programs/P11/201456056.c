#include <stdio.h>

#define INF 1000000000
#define MAX 1000000
int S[MAX], A[MAX];

int main(){
    int N, i, t, x, j; 
    long long max_area, cur_area;
    scanf("%d", &N);
    while(N!=0){
        cur_area = 0;
        max_area = 0;
        S[0] = 0;
        A[0] = -INF;
        t = 0;
        for(i=1; i<=N; i++){
            scanf("%d", &x);
            A[i] = x;
            while(x < A[S[t]]){
                j = S[t];
                t = t - 1;
                cur_area = (long long)A[j]*(i-S[t]-1);
                if(cur_area > max_area)
                    max_area = cur_area;
            }
            t = t + 1;
            S[t] = i;
        }
        while(t>0){
            j = S[t];
            t = t - 1;
            cur_area = (long long)A[j]*(i-S[t]-1);
            if(cur_area > max_area)
                max_area = cur_area;

        }
        printf("%lld\n", max_area);
        scanf("%d", &N);
    }
    return 0;
}
