#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 1005

typedef struct bag 
{
    long long int Ma;
    long long int sum;
    long long int *W;
} lol;

void mergeSort(lol arr[],long long int low,long long int mid,long long int high);
void partition(lol arr[],long long int low,long long int high);


int main()
{
    long long int N, MOD, M, i, j;
    scanf("%lld %lld", &N, &MOD);
    
    lol A[1001];
    
    for (i = 0; i < N; i++)
    {
        scanf("%lld", &M);
        A[i].Ma = M;
        A[i].W=(long long int*)malloc(M*sizeof(long long int));
        A[i].sum = 0;
        for (j = 0; j < M; j++)
        {
            scanf("%lld", &A[i].W[j]);
            A[i].sum = (A[i].sum+A[i].W[j])%MOD;
        }
        
        //~ printf("%lld", A[i].sum);
        
    }    
    partition(A, 0, N-1);
    for (i = 0; i < N; i++)
    {
        printf("%lld\n", A[i].sum % MOD);
        
        for (j = 0; j < A[i].Ma; j++)
        {
            printf("%lld\n", A[i].W[j]);
        }
        printf("\n");
        
    }
    
        
    return 0;
}

void partition(lol arr[],long long int low,long long int high){
 
    long long int mid;
 
    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}
 
void mergeSort(lol arr[], long long int low, long long int mid, long long int high){
 
    long long int i,m,k,l;
    lol  temp[MAX];
 
    l=low;
    i=low;
    m=mid+1;
 
    while((l<=mid)&&(m<=high)){
 
         if(arr[l].sum<=arr[m].sum){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
 
    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
 
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
