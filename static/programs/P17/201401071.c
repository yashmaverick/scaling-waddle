#include <stdio.h>

#define MAX ((int)1e6)

int P[MAX], L[MAX];
int PRE[MAX], IN[MAX];

void debug_stack(int *S, int top){
    int i;
    for(i=0; i<=top; i++){
        fprintf(stderr, "%d ", S[i]);
    }
    fprintf(stderr, "\n");
}

void print_parent(int N){
    int i;
    for(i=1; i<=N; i++){
        fprintf(stderr, "i, %d  Pi, %d Li, %d\n", i, P[i], L[i]);
    }
}


void build_tree(int *PRE, int *IN, int N){
    if(N==0) return;
    int i=0, top=-1, j=0, x;
    int S[MAX];
    //Root, self loop
    S[++top] = PRE[i];
    P[PRE[i]] = PRE[i];
    L[PRE[i]] = 0;
    i++;
    while(i<N){
        //debug_stack(S, top);
        x = S[top];
        while(top!=-1 && S[top]==IN[j]){
            x = S[top--];
            j++;
        }

        P[PRE[i]] = x;
        L[PRE[i]] = L[x]+1;
        S[++top] = PRE[i];
        i++;
    }
}

int LCA(int x, int y){
    while(x!=y){
        if(L[x]>L[y]){
            x = P[x];
        }
        else{
            y = P[y];
        }
    }
    return y;
}

int main(){
    int N, x, y, i, T;
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d", &PRE[i]);
    for(i=0; i<N; i++)
        scanf("%d", &IN[i]);
    build_tree(PRE, IN, N);
    //print_parent(N);
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
    return 0;
}
