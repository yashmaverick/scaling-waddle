#include <stdio.h>
#include<string.h>
#include<stdio.h>
#define ll long long
#define MOD 1000000007
int t;
ll u,d,m,N,ans;
ll cnt[50];
ll p[50];
 
 
ll power(ll a , ll n , ll mod)
{
if(a==0 && n==0)return 1;
ll ret=1ll,inter=a;
while(n){
if(n&1)ret=(ret*inter)%mod;
inter=(inter*inter)%mod;
n>>=1;
}
return ret;
}
 
void pre(ll u , ll d , ll N)
{
ll i,j;
for(i=0;i<N;i++){
p[i]=power(i,d,N);
}
for(i=0;i<N;i++){
for(j=0;j<N;j++){
if(p[j]%N==i)cnt[i]++;
}
cnt[i]=(u/N)*cnt[i];
}
ll x=u%N;
for(i=0;i<N;i++){
for(j=0;j<=x;j++){
if(p[j]%N==i)cnt[i]++;
}
}
 
}
 
int main()
{
scanf("%d",&t);
int i,j,k;
while(t--){
scanf("%lld%lld%lld%lld",&u,&d,&m,&N);
memset(cnt,0,sizeof(cnt));
ans=0;
pre(u,d,N);
for(i=0;i<N;i++)
for(j=0;j<N;j++)
for(k=0;k<N;k++)
if(((i+j)%N+k)%N==m)
ans=(ans+(((cnt[i]*cnt[j])%MOD)*cnt[k])%MOD)%MOD;
printf("%lld\n",ans);
}
return 0;
}
