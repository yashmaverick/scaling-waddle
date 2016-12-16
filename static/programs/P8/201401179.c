#include<stdio.h>
long long int power(int a,long long int b,int mod){
long long int x=1,y=a;
while(b!=0){
if(b%2==1){
x=(x*y)%mod;
}
y=(y*y)%mod;
b=b/2;
}
return x;
}
int main(){
int tc;
scanf("%d",&tc);
while(tc--){
long long int upper,d;
int m,n,i;
scanf("%lld %lld %d %d",&upper,&d,&m,&n);
long long int c[n];
long long int p[n];
for(i=0;i<n;i++){
if(upper>=i){
c[i]=((upper-i)/n)+1;
}
else{
c[i]=0;
}
}
for(i=0;i<n;i++){
p[i]=power(i,d,n);
}
long long int ans=0;
int j,k;
for(i=0;i<n;i++){
for(j=0;j<n;j++){
for(k=0;k<n;k++){
if((p[i]+p[j]+p[k])%n==m){
ans=(ans+((c[i]*c[j])%1000000007)*c[k])%1000000007;
//ans=ans+((((c[i]*c[j])%1000000007)*c[k])%1000000007);
}
}
}
}
printf("%lld\n",ans);
}
return 0;
}