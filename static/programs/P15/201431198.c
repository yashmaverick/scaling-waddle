#include<stdio.h>
#define MAXN 100000
int q1[3*MAXN];
int q2[3*MAXN];
int ar[3*MAXN];
int f1,r1,f2,r2;
void enq(int x){
    q1[r1++]=x;
    while(r2>f2 && q2[r2-1]>x)
        r2--;
    q2[r2++]=x;
}
void dq(){
    if(q2[f2]==q1[f1])
        f2++;
    f1++;
}
int getmin(){
    return q2[f2];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        f1=r1=f2=r2=0;
        int n,k,i;
        scanf("%d %d",&n,&k);
        for(i=1; i<=n; i++){
            scanf("%d",&ar[i]);
            if(i<=k)enq(ar[i]);
        }
        printf("%d",getmin());
        if(n-k+1>1)putchar(' ');
        for(i=k+1; i<=n; i++){
            enq(ar[i]);
            dq();
            printf("%d",getmin());
            if(i<n)putchar(' ');
        }
        printf("\n");
    }
    return 0;
}
