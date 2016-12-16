#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define si(a)               scanf("%d",&a)
#define sii(a,b)            scanf("%d %d",&a,&b)
#define sl(a)               scanf("%lld",&a)
#define slu(a)              scanf("%llu",&a)
#define sf(a)               scanf("%f",&a)
#define sd(a)               scanf("%lf",&a)
#define ss(a)               scanf("%s",a)
#define pi(a)               printf("%d",a)
#define pii(a,b)            printf("%d %d",a,b)
#define pl(a)               printf("%lld",a)
#define pnl                 printf("\n")

#define LL                  long long 
#define UI                  unsigned int
#define ULL                 unsigned long long
#define MOD                 1000000007
#define MAX                 1000000007000
#define forall(i,a,b)       for(i=a; i<b; i++)

#define max(a,b)    ((a) > (b) ? (a) : (b))
#define min(a,b)    ((a) < (b) ? (a) : (b))

int main()
{
    int N;
    si(N);

    int front = 0,no = 0,i;
    char buffer[10001][101],c;
    while(1)
    {
        c = getchar();
        if(c == 'Q')
            break;
        else if(c == 'A')
        {
            int a;
            si(a);
            for(i = 0;i < a;i++){
                ss(buffer[(front + no) % N]);
            if(no != N)
                no++;
            else
                front = (front + 1) % N;
            }
        }
        else if(c == 'R')
        {
            int r;
            si(r);
            front = (front + r) % N;
            no = no - r;
        }
        else if(c == 'L'){
            for(i = 0; i < no; i++)
                printf("%s\n", buffer[(front + i) % N]);
        }
    }
    return 0;
}
