#include<stdio.h>
#include<stdlib.h>
long long sempty;
void stackpop(long long *a,long long* top){
    *top=*top-1;
    if(*top<1){
        sempty=1;
        *top=0;
        a[0]=0;
        return;
    }
    return;
}

void stackpush(long long *a,long long* top,long long val){
    *top=*top+1;
    a[*top]=val;
    sempty=0;
    return;
}
int main(){
    long long max;
    long long n;
    long long* topa=(long long *)malloc(sizeof(long long));
    sempty=1;
    *topa=0;
    max=0;
    scanf("%lld",&n);
    while(n!=0){
        long long stacki[n+1],i,a[n+1];
        stacki[0]=0;a[0]=0;
        //prlong longf("%d",n);
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        i=1;
        while (i<=n){
            //printf("current element:-  %d  top of stack:-   %d\n",a[i],a[stacki[*topa]]);
            if(sempty||a[stacki[*topa]]<a[i]){
                //printf("top %d stack %d index %d\n",stacki[*topa],a[stacki[*topa]],*topa);
                stackpush(stacki,topa,i);
                //printf("new top %d stack %d index %d\n",stacki[*topa],a[stacki[*topa]],*topa);
                i++;
            }/*else if (a[stacki[*topa]]==a[i]){
                stackpop(stacki, topa);
                stackpush(stacki, topa, i);
                i++;
            }*/else{
                //printf("popping\n");
                //printf("top %d stack %d index %d sempty %d\n",stacki[*topa],a[stacki[*topa]],*topa,sempty);
                long long temp=a[stacki[*topa]];
                stackpop(stacki, topa);
                long long curr;
                if(sempty==1){curr = temp*(i-1);}
                else {
                    curr= temp * (i-stacki[*topa]-1);
                }
                if(curr>max){
                    max=curr;
                }
                //printf("curr = %d\n",curr);
                //printf("new top %d stack %d index %d sempty %d\n",stacki[*topa],a[stacki[*topa]],*topa,sempty);
            }
            //printf("done stuff\n");
        }
        //printf("reached end %d %d %d %d\n",i,a[stacki[*topa]],stacki[*topa],*topa);
        while(sempty==0){
            long long temp=a[stacki[*topa]];
            //printf("temp %d\n",temp);
            stackpop(stacki, topa);
            long long  curr= temp*(i-stacki[*topa]-1);
            //printf("curr %d\n",curr);
            if(curr>max){
                max=curr;
            }
        }
        //long long curr= stackl[*topa]*(i-stacki[*topb]);
        /*printf("curr %d\n",curr);
        if(curr>max){
            max=curr;
        }*/
        printf("%lld\n",max);
        //max=0;*topa=0;*topb=0;
        max=0;
        scanf("%lld",&n);
    }
    return 0;
}
