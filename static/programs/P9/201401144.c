#include <stdio.h>
#include <stdlib.h>

int main(){
    long long int mod;
    int i;
    int n;
    //int weight[1002];
    scanf("%d",&n);
    long long int* a[n];
    scanf("%lld",&mod);
    for(i=0;i<n;i++){
        //printf("i = %d\n", i);
        int m;
        int j;
        long long int w=0;
        scanf("%d",&m);
        a[i] = (long long int*)malloc((m+2)*sizeof(long long int));
        a[i][1]=m;
        for(j=0;j<m;j++){
            scanf("%lld",&a[i][j+2]);
            w+= a[i][j+2]%mod;
        }
        a[i][0]=w%mod;
    }
    //printf("done input\n");
    
    for(i=n-1;i>0;i--){
        int j;
        //printf("current i: %d \n", i);
        for (j=0;j<i;j++) {
            if(a[j][0]>a[j+1][0]){
                long long int* temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    //partition(a,0,n);
    for(i=0;i<n;i++){
        int j;
        printf("%lld\n",a[i][0]);
        for(j=0;j<a[i][1];j++){
            printf("%lld\n",a[i][j+2]);
        }
        printf("\n");
    }
    return 0;
}