#include <stdio.h>
int a[1000000],b[1000000],temp[999999],n;
void run() {
    int i,j=0,l,m,x,in;
    scanf("%d %d",&l,&m);
    i=0;
    while(!(b[i]==l||b[i]==m)){
        i++;
    }
    if (b[i]==l)x=m;
    else x=l;
    in=0;
    //temp[in]=b[i];
    while (b[i]!=x) {
        temp[in]=b[i];
        in++;
        i++;
    }
    temp[in]=b[i];
    int state=0;
    for(i=0;i<n;i++){
        for(j=0;j<=in;j++){
            if(a[i]==temp[j]){
                state=1;
                goto END;
            }
        }
    }
END:
    if(state==1){
        printf("%d\n",temp[j]);
    }
}
int main() {
    int x,i;
    scanf("%d",&n);
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (i=0; i<n; i++) {
        scanf("%d",&b[i]);
    }
    scanf("%d",&x);
    for(i=0;i<x;i++){
        run();
    }
    return 0;
}
