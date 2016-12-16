
#include <stdio.h>
long long stk[500000]={0};
long long top;
long long empty=0;
long long count;
long long stktop(){
    return stk[top];
}
void stkpush(long long x){
    stk[++top]=x;
    empty++;
}
long long stkpop(){
    empty--;
    return stk[top--];
}
int main() {
    long long n,i,sum=0,count=0;
    while(1){
        scanf("%lld",&n);
        if(n==0){
            return 0;
        }
        long long a[n];
        for(i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        for (i=0; i<n; i++) {
            while(1){
                //printf("count %d top %d\n",empty,top);
                if(empty==0 || a[i]<a[stktop()]){
                    //    printf("pushing %d\n",a[i]);
                    long long temp;
                    stkpush(i);
                    temp=count;
                    count++;
                    if(temp>1){
                        sum+=temp-1;
                    }
                    break;
                }else if(a[i]==a[stktop()]){
                    long long p;
                    long long temp;
                    p=top;
                    while(p>0 && a[stk[p]]==a[i])
                    {
                        p--;
                    }
                    temp=p;
                    stkpush(i);
                    count++;
                    if(temp>1){
                        //printf("happening %d\n",a[i]);
                        sum+=temp-1;
                    }
                    break;
                }else{
                    //      printf("%d greater than %d empty %d\n",a[i],a[stktop()],empty);
                    stkpop();
                    count--;
                    sum+=n-i-1;
                    //   printf("adding %d",n-i);
                }
            }
        }
        printf("%lld\n",sum);
        sum=0;
        count=0;
        empty=0;
        top=0;
    }
    return 0;
}
