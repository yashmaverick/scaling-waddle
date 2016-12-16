#include<stdio.h>
int modpow(int,int,int);
int main(){
	int test,limit,d,m,n,ar[40],i,j,k,l,mods[40],tmod;
	long long ans;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d %d",&limit,&d,&m,&n);
		for(i=0;i<40;i++){
			ar[i]=0;
		}
		for(i=0;i<n&&i<=limit;i++){
			mods[i]=modpow(i,d,n);
			for(j=i;j<=limit;j+=n){
				ar[mods[i]]++;
			}
		}
		for(i=0,ans=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=m-i-j;k<3*n;k+=n){
					if(0<=k&&k<n){
						ans=(ans+(((((long long)ar[i]*(long long)ar[j])%1000000007)*(long long)ar[k])%1000000007))%1000000007;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

int modpow(int base,int pow,int mod){
	int ans;
	ans=1;
	while(pow>0){
		if(pow&01){
			ans=(ans*base)%mod;
		}
		base=(base*base)%mod;
		pow>>=1;
	}
	return ans;
}
