#include<stdio.h>
#define N 1000004
#define s(n) scanf("%lld", &n)
#define p(n) printf("%lld\n", n)
#define int long long int
int t, n, A[N], bucket[N], offset, min, max, i, j, ans;
int main(){
	s(t);
	while(t--){
		ans = 0; s(n);
		for(i=0; i<n; i++)
			s(A[i]);
		min = max = A[0];
		for(i=1; i<n; i++){
			if(A[i] < min)min = A[i];
			if(A[i] > max)max = A[i];
		}
		for(i=0; i<=max-min; i++)bucket[i] = 0;
		for(i=0; i<n; i++)bucket[A[i] - min]++;
		for(i=0; i<=max-min; i++)ans += bucket[i]*(bucket[i]-1)/2;
		p(ans);
	}
	return 0;
}

