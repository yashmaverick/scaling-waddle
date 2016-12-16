#include<stdio.h>
#include<stdlib.h>
#define cin(n) scanf("%lld", &n)
#define cout(n) printf("%lld\n", n)
#define N 1003
#define M 1000200
#define ll long long int
ll *a[N],done[N], size[N], wt[N];
int main(){
	ll ans, n, m, MOD, i, j;
	cin(n); cin(MOD);
	for(i=0; i<n; i++){
		done[i] = 0;
		wt[i] = 0;
		cin(size[i]);
		a[i] = malloc(size[i]*sizeof(ll));
		for(j=0; j<size[i]; j++){
			cin(a[i][j]);
			//printf("%lld ", a[i][j]);
			wt[i] += a[i][j];
			wt[i] %= MOD;
		}
		//printf("%lld ", wt[i]);
	}
	for(i=0; i<n; i++){
		for(j=n-1; j>=0; j--)if(!done[j])break;
		ans = j;
		for(j=ans-1; j>=0; j--)if(!done[j] && wt[j]%MOD <=  wt[ans]%MOD)ans=j;
		done[ans]=1;
		cout(wt[ans]);
		for(j=0; j<size[ans]; j++)cout(a[ans][j]);
		printf("\n");
	}
	return 0;
}
