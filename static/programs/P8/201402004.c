#include<stdio.h>
#define MOD 1000000007
#define ll long long int
ll pwr(ll x,ll y,ll p)
{
    ll z=1;
    for(;y;y>>=1,x=x*x%p)if(y&1)z=z*x%p;
    return z;
}
int main()
{
    ll upper,d,cnt, N,m,T,i,j,k,p;
    scanf("%lld",&T);
    while(T--)
    {
    	scanf("%lld %lld %lld %lld",&upper,&d,&m,&N);
    	cnt=0;
    	for(i=0;i<N && i<=upper;i++){
    		for(j=0;j<N && j<=upper;j++){
    			for(k=0;k<N && k<=upper;k++){
    				p=(pwr(i,d,N)+pwr(j,d,N)+pwr(k,d,N))%N;
    				if(p==m){
    					p=((((((upper-i)/N)+1)*(((upper-j)/N)+1))%MOD)*(((upper-k)/N)+1))%MOD;
    					cnt+=p;
    				}
    				cnt%=MOD;
    			}
    		}
    	}
    	printf("%lld\n",cnt);
    }
return 0;
} 
