#include<stdio.h>
long long int binary(long long int A[],long long int l, long long int u, long long int m){
      long long int mid;
      while (l <= u) {
          mid = (l+u)/2;
          if (A[mid] > m)
              u = mid - 1;
          else
              l = mid + 1;
      }
      return l;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long int j,count=0,i,m,u,A[100000],B[100000],C[100000],p,q,r;
        scanf("%lld",&p);
        for(i=0;i<p;i++){
            scanf("%lld",&A[i]);
        }
        scanf("%lld",&q);
        for(i=0;i<q;i++){
            scanf("%lld",&B[i]);
        }
        scanf("%lld",&r);
        for(i=0;i<r;i++){
            scanf("%lld",&C[i]);
        }
        if(q>r)
            q=r;
        for(j=0;j<q;j++){
            m = binary(A,0,j,B[j]);
            u = binary(C,j,r-1,B[j]);
            if(u==r && B[j]==C[r-1]){
                u=r-j;
            }
            else if(C[u]>B[j] && C[u-1]==B[j] && u-1>=j)
                u = r-u+1;
            //if(u==r)
              //  u = r-j;
            else
                u = r-u;
            count += u*m;
            //printf("Debug count %lld m %lld u %lld\n",count,m,u);
        }
        printf("%lld\n",count);
    }
    return 0;
}