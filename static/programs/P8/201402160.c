#include<stdio.h>
#define cout(n) printf("%lld\n", n)
#define ll long long int
#define MOD 1000000007
//using namespace std;
ll a1,a2,a3,d,u,m,n;
ll fast(ll a, ll b, ll n)
{
	ll pr=1;
	//if(a==0)return !b;
	while(b>0){
		if(b&01)pr*=a;
		pr %= n;
		b/=2;
		a*=a;
		a%=n;
	}
	return pr%n;
}
int main(){
	ll t;
	scanf("%lld", &t);
		ll i, j, k, dp[50], faster[50], count=0;
	while(t--){
	//cin>>a1>>a2>>a3>>u>>d>>m>>n;
	//cin>>u>>d>>m>>n;
	count=0;
	scanf("%lld %lld %lld %lld", &u, &d, &m, &n);
	//cout<<fast(a1,a2);
	for(i=0; i<=n; i++)faster[i] = fast(i, d, n);
	for(i=0;i<n;i++)dp[i]=0;
	for(i=0; i<n;i++)if(i<=u)dp[fast(i,d,n)]+=(u-i)/n + 1;
	//for(i=1;i<=n;i++)cout<<i<<" "<<dp[i]<<endl;
	//ll z = (u<=n)?u+1:n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				//cout<<fast(i,d)<<" ";
				//cout(k);
				if((i+j+k)%n==m%n)
				{
				//cout<<fast(i,d)<<" "<<fast(j,d)<<" "<<fast(k,d)<<endl; 
				count+=(((dp[i]*dp[j])%MOD)*dp[k]%MOD)%MOD;
				count%=MOD;
				}
			}
		}
	}
	cout(count%MOD);
	//cout(t);
	}
	return 0;
}
