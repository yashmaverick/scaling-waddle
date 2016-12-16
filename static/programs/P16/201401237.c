#include<stdio.h>
#include<math.h>

int main(){
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int q;
        scanf("%d",&q);
        int power=log2(q)-1;
        int k=2<<power;
        int m=k/2;
        if(q>=(k+m))
            printf("%d\n",power*2+2);
        else
            printf("%d\n",power*2+1);
    }
    return 0;
}
