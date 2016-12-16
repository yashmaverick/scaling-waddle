#include <stdio.h>
#include <stdlib.h>

#define MAX 1001


typedef struct{
    int *A;
    int w;
    int s;
}bag;

bag *tmp[MAX];

int *getbag(int n){
    return (int*)malloc(sizeof(int)*n);
}

void init(bag *b, int m){
    b->A = getbag(m);
    b->s = m;
    b->w = 0;
}

int compare(const void *a, const void *b){
    return (((bag*)a)->w)<=(((bag*)b)->w);
}

void print_bag(bag *S){
    int j;
    printf("%d\n", S->w);
    for(j=0; j<(S->s); j++){
        printf("%d\n", S->A[j]);
    }
    printf("\n");
}



void merge(bag **A, int left, int mid, int right){
    int le=mid-1;
    int start=left;
    int c=left, j;
    while(left<=le && mid <= right){
        if(compare(A[left], A[mid])){
            tmp[c] = A[left];
            c++; left++;
        }
        else{
            tmp[c] = A[mid];
            c++; mid++;
        }
    }

    while(left<=le){
        tmp[c] = A[left]; 
        c++; left++;
    }

    while(mid<=right){
        tmp[c] = A[mid];
        c++; mid++;
    }

    for(j=right; j>=start; j--){
        A[j] = tmp[j];
    }
}

void mergesort(bag **A, int left, int right){
    if(left>=right) return;
    int mid = (left+right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid+1, right);
    merge(A, left, mid+1, right);
}


int main(){
    int N, P, M;
    int i, j;
    bag S[MAX];
    bag *B[MAX];
    scanf("%d %d", &N, &P);
    for(i=0; i<N; i++){
        scanf("%d", &M);
        init(&S[i], M);
        B[i] = &S[i];
        for(j=0; j<M; j++){
            scanf("%d", &(S[i].A[j]));
            S[i].w += S[i].A[j];
            if(S[i].w>=P)
                S[i].w = S[i].w%P;
        }
    }
    mergesort(B, 0, N-1);
    for(i=0; i<N; i++){
        print_bag(B[i]);
    }
    return 0;
}


