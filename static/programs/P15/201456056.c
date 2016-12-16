#include <stdio.h>
#define MAX 10010

typedef struct e_t{
    int index;
    int val;

}elem;

void print_window(elem *e, int head, int tail){
    printf("Sliding Window: \n");
    while(head<=tail){
        printf("%d ", e[head].val);
        head++;
    }
    printf("\n");
}

int main(){
    int N, T, i, x, K;
    int head, tail;
    elem e[MAX];
    scanf("%d", &T);
    while(T--){
        head = 0;
        tail = -1;
        scanf("%d %d", &N, &K);
        for(i=0; i<K-1; i++){
            scanf("%d", &x);
            while(head<=tail && x<=e[tail].val){
                tail = tail - 1;
            }
            tail = tail + 1;
            e[tail].val = x;
            e[tail].index = i;
            while( e[head].index <= i-K){
                head = head + 1;
            }

        }
        for(i=K-1; i<N; i++){
            scanf("%d", &x);
            while(head<=tail && x<=e[tail].val){
                tail = tail - 1;
            }
            tail = tail + 1;
            e[tail].val = x;
            e[tail].index = i;
            while(e[head].index <= i-K){
                head = head + 1;
            }
            //print_window(e, head, tail);
            if(i!=N-1){
                printf("%d ", e[head].val);
            }
            else{
                printf("%d\n", e[head].val);
            }
        }
    }
    return 0;
}
