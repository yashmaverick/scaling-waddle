#include<stdio.h>
#include<math.h>

int main(){
    int t,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&a);
        int left=log(a)/(double)log(2);
       // printf("%d\n",left);
       // printf("%d %d %d\n",1<<(left),a,((1<<(left))*3)/2);
        if(a>=(1<<(left)) && a<((1<<(left))*3)/2)
            printf("%d\n",2*left-1);
        else
            printf("%d\n",2*left);
    }
    return 0;
}
