#include<stdio.h>
#include<string.h>
#define MIN(x,y) (x<y) ? x : y
#define MOD 1000000007
     
long long int mod_power(long long int a, long long int p, long long int n)
{
 if(p==0)
 return 1;
  if(p==1)
   return a%n;
    if(a==1)
     return 1;
long long int tmp = mod_power(a,p/2,n);
 tmp = tmp * tmp;
  if(tmp >= n)
   tmp %= n;
     
  if(p%2)
   tmp *= a;
   tmp %= n;
    return tmp;
}
     
long long int main()
{
long long int upper, d, m, n, i, j, k,t;
scanf("%lld",&t);
while(t--)
{
scanf("%lld %lld %lld %lld",&upper,&d,&m,&n);
long long int sum = m%n;
long long int limit = MIN(n-1,upper);
long long int arr[limit+1], cnt=0;
for(i=0;i<=limit;i++)
arr[i] = mod_power(i,d,n);
 
long long int hash[40];
memset(hash,0,sizeof(hash));
     
long long int tot = (upper+1)/(n);
long long int rem = (upper+1)%(n);
for(i=0;i<=limit;i++)
{
 hash[i] = tot;
 if(rem > 0)
 {
  hash[i]++;
  rem--;
 }
}
for(i=0;i<=limit;i++)
{
 for(j=0;j<=limit;j++)
 {
  for(k=0;k<=limit;k++)
  {
   if((arr[i]+arr[j]+arr[k])%n == sum)
   {
   cnt += ((((hash[i]%MOD)*(hash[j]%MOD))%MOD*(hash[k]%MOD))%MOD);
   if(cnt>=MOD)
   cnt %= MOD;
   }
  }
 }
}
printf("%lld\n",cnt);
}
return 0;
} 
