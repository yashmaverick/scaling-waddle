#include <stdio.h>
#define MAX 100

unsigned long long int d, U; 
unsigned long long int n, m;
#define  MOD 1000000007
unsigned long long int A[MAX];

unsigned long long int fastexp(unsigned long long int a, unsigned long long int b){
	if(b==0) return 1;
	if(b==1) return a;
	long long res=1;
	res = fastexp(a, b/2);
	res = res*res;
	if(res>m) res = res%n;
	if(b%2) res=res*a;
	return res%n;
}

unsigned long long int sols(unsigned long long int x){
	return (U/n)+(x<=(U%n));
}

unsigned long long int f(){
	unsigned long long int i, j, k;
	for(i=0; i<=n; i++){
		A[i] = fastexp(i, d);
	}
	unsigned long long ans=0;
	unsigned long long int temp;
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			for(k=0; k<n; k++){
				if((A[i]+A[j]+A[k])%n==m){
					temp = sols(i)*sols(j);
					if(temp>MOD) temp = temp%MOD;
					temp = temp*sols(k);
					if(temp>MOD) temp = temp%MOD;
					ans += temp;
					if(ans>MOD) ans = ans%MOD;
				}
			}
		}
	}
	return ans;
}

void  printarr(unsigned long long int *A, unsigned long long int len){
	unsigned long long int i;
	for(i=0; i<len; i++)
		printf("%lld ", A[i]);
	printf("\n");
}

unsigned long long int main(){
	unsigned long long int T, i;
	scanf("%lld", &T);
	while(T--){
		scanf("%lld %lld %lld %lld", &U, &d, &m, &n);
		printf("%lld\n", f());
	}
	return 0;
}
