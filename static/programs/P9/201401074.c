#include<stdio.h>
#include<stdlib.h>

typedef struct bag{
    int nitems;
    long long int weight;
    int* items;
}bag;

bag bags[1000],temp[1000];

void merge(int a,int b,int c,int d){
    //  printf("l=%d, r=%d\n\n",a,d);
    if(d==a){
        return;
    }
    int i=a,j=c,k;
    for(k=a;i<=b&&j<=d&&k<=d;k++){
        //      printf("i=%d j=%d k=%d\n",i,j,k);
        //      printf("weighti=%lld weightj=%lldi\n",bags[i].weight,bags[j].weight);
        if(bags[i].weight<=bags[j].weight){
            temp[k]=bags[i++];
        }
        else{
            temp[k]=bags[j++];
        }
    }
    //  printf("i=%d j=%d k=%d\n",i,j,k);
    if(i>b){
        while(j<=d){
            temp[k++]=bags[j++];
        }
    }
    if(j>d){
        while(i<=b){
            temp[k++]=bags[i++];
        }
    }
    for(k=a;k<=d;k++){
        bags[k]=temp[k];
    }
}

void mergesort(int l,int r){
    int mid;
    if(l<r){
        mid=l+(r-l)/2;
        mergesort(l,mid);
        mergesort(mid+1,r);
        merge(l,mid,mid+1,r);
    }
}

int main(){
    long long int w,mod;
    int n,m,i,j;
    scanf("%d%lld",&n,&mod);
    for(i=0;i<n;i++){
        //        printf("i=%d-------------------\n",i);
        scanf("%d",&m);
        bags[i].nitems=m;
        bags[i].weight=0;
        bags[i].items=(int*)malloc(m*sizeof(int));
        for(j=0;j<m;j++){
            scanf("%lld",&w);
            //            printf("weight=%lld\n",bags[i].weight);
            bags[i].weight=(bags[i].weight+w)%mod;
            //            printf("weight=%lld\n",bags[i].weight);
            (bags[i]).items[j]=w;
        }
    }
    mergesort(0,n-1);
    for(i=0;i<n;i++){
        printf("%lld\n",bags[i].weight);
        for(j=0;j<(bags[i]).nitems;j++){
            printf("%d\n",(bags[i]).items[j]);
        }
        printf("\n");
    }
    return 0;
}




