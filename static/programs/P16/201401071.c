#include <stdio.h>

int f(int x){
    int n=0, i, prev, res;
    for(i=1; i*2<=x; i*=2)
        n++;
    //This level contains i elements, prev, i/2, also, half of this elements
    prev = i/2;
    //if x-half of no of elements on this level > i
    //printf("%d %d\n", x-prev, i);
    res= (x-prev<i)?2*n-1:2*n;
    return res;
}

int main(){
    int N, x;
    scanf("%d", &N);
    while(N--){
        scanf("%d", &x);
        printf("%d\n", f(x));
    }
    return 0;
}
