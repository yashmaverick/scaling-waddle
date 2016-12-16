#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MS 10010
#define ML 110
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)


char str[MS][ML];
int h, t, n, s;

void print_buffer(char c){
    fprintf(stderr, "Op %c head %d, tail %d, size %d\n",c, h, t, n);
    int i;
    for(i=0; i<n; i++)
        printf("%d %s\n", (h+i)%s, str[(h+i)%s]);
    printf("\n");
}


int f(char c){
    int nt;
    //print_buffer(c);
    switch(c){
        case 'A':
            scanf("%d", &nt);
            n = min(n+nt, s);
            while(nt--){
                scanf("%s",str[t]);
                if(h==t && n==s) 
                    h=(h+1)%s;
                t = (t+1)%s;
            }

            break;
        case 'R':
            scanf("%d", &nt);
            assert(nt<=n);
            n = max(0, n-nt);
            h = (h + nt)%s;
            break;
        case 'L':
            for(nt=0; nt<n; nt++){
                printf("%s\n", str[(h+nt)%s]);
            }
            return 1;
        case 'Q':
            return 0;
        default: 
            return 1;
    }
    return 1;
}

int main(){
    h = t = n = 0;
    char opt[5];
    scanf("%d", &s);
    do{
        scanf("%s", opt);
    }
    while(f(opt[0]));
    return 0;
}
