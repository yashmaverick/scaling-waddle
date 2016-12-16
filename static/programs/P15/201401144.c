//
//  main.c
//  p15
//
//  Created by Mukul Hase on 06/03/15.
//  Copyright (c) 2015 Mukul Hase. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int k;
int a[100000];
int* curr;
int first;
int last;
int count;
int indexadd(int index, int N){
    index++;
    if (index==N) {
        index=0;
    }
    return index;
}
int indexsub(int index, int N){
    index --;
    if (index==-1) {
        index=N-1;
    }
    return index;
}
void createstk(){
    curr = (int*)malloc(k*sizeof(int));
    first=0;
    last=-1;
    count=0;
    return;
}
int stktop(){
    if(count==0)return 0;
    return curr[last];
}
int stkbot(){
    return curr[first];
}
void stkpush(int x){
    count++;
    last=indexadd(last, k);
    curr[last]=x;
    //printf("pushing %d\n",a[curr[last]]);
}
void stkpull(){
    //int n;
    //printf("pulling %d\n",a[curr[first]]);
    count--;
    if(count==-1){
        count++;
        return;
    }
    first=indexadd(first,k);
}
int stkpop(){
    count--;
    //printf("popping %d\n",a[curr[last]]);
    last=indexsub(last, k);
    //printf("new stkbot %d\n",stkbot());
    return curr[last];
}
void run(){
    int n,i;
    scanf("%d %d",&n,&k);
    createstk();
    //int a[n];
    a[0]=-1;
    for (i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //printf("started\n");
    for(i=0;i<n;i++){
        //printf("-----------doing i = %d----------\n",i);
        //printf("fir %d las %d\n",first,last);
        //printf("i %d k %d i-k %d stkbot %d\n",i,k,i-k,stkbot());
        if (i>=k) {
            if(i-k==stkbot()){
                stkpull();
            }
        }
        while (a[i]<a[stktop()]&&count>0) {
            stkpop();
        }
        stkpush(i);
        if(i>=k-1){
            printf("%d",a[stkbot()]);
            if(i!=n-1){
                printf(" ");
            }
        }
    }
    printf("\n");
}
int main() {
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        run();
    }
    return 0;
}