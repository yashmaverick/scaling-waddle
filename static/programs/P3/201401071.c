#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF (int)1e9
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
#define gc getchar_unlocked
#define MAX 100000

void din(int *x){
	register int c = gc();
	*x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

int main(){
	int T, i;
	int N, A[MAX];
	int mx=0, mn=-INF;
	din(&T);
	while(T--){
		din(&N);
		for(i=0; i<N; i++)
			din(&A[i]);
		mx=0;
		mn=A[0];
		for(i=1; i<N; i++){
			mx = max(A[i]-mn, mx);
			mn = min(A[i], mn);
		}
		printf("%d\n", mx);
	}
	return 0;
}
