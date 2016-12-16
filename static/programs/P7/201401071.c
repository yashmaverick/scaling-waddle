#include <stdio.h>
#include <stdlib.h>
#define MAX 1000003
#define gc getchar_unlocked

void din(int *x){
	register int c = gc();
	*x = 0;
	for(;(c<48 || c>57);c = gc());
	for(;c>47 && c<58;c = gc()) {*x = (*x<<1) + (*x<<3) + c - 48;}
}

int compare(const void *a, const void *b){
	return *((int*)a)-*((int*)b);
}

long long f(int *A, int N){
	int curr_val=A[0];
	int i;
	long long counter = 1;
	long long res = 0;
	for(i=1; i<N; i++){
		if(A[i]!=curr_val){
			res += counter*(counter-1)/2;
			counter = 0;
			curr_val = A[i];
		}
		counter += 1;
	}
	res += counter*(counter-1)/2;
	return res;
}


int main(){
	int A[MAX], N, T, i;
	din(&T);
	while(T--){
		din(&N);
		for(i=0; i<N; i++)
			din(&A[i]);
		qsort(A, N, sizeof(int), compare);
		printf("%lld\n", f(A, N));
	}
	return 0;
}
