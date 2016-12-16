#include<stdio.h>
 
typedef long long ll;
 
const int md = 1000000007;
int upper,d,m,N;
int A[50];
 
int f(int a,int b,int c){
int ret = 1;
for(;b;b>>=1){
if(b%2 == 1){ret = (ret*a)%c;}
a = (a*a)%c;
}
return ret;
}
 
int g(int x){
if(x == 0) return 1+(upper/N);
int xx = upper/N;
if(upper%N > 0 && upper%N >= x){xx+=1;}
return xx;
}
 
int main(){
int t,i,j,k;
scanf("%d",&t);
for(;t;t--){
scanf("%d %d %d %d",&upper,&d,&m,&N);
A[0] = (d==0)?1:0;
A[1] = 1;
ll ans = 0;
for(i=2;i<N;i++)A[i]=f(i,d,N);
for(i=0;i<N;i++){
for(j=0;j<N;j++){
for(k=0;k<N;k++){
if((A[i]+A[j]+A[k])%N == m){
ll tmp = g(i);
tmp = (tmp*g(j))%md;
tmp = (tmp*g(k))%md;
 ans = (ans+tmp)%md;
}
}
}
}
printf("%lld\n",ans);
}
return 0;
}
