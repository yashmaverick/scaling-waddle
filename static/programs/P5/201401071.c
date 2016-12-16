#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int T, N, A[MAX], K, i;


int f(int *A, int n, int K){
	int i, j, k;
	for(i=0; i<n; i++){
		if(A[i]>K) continue;
		for(j=i+1; j<n; j++){
			if(A[i]+A[j]>K) continue;
			for(k=j+1; k<n; k++){
				if(A[i]+A[j]+A[k]==K) return 1;
			}
		}
	}
	return 0;
}


int main(){
	char S[100];
	scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &K);
		for(i=0; i<N; i++){
			scanf("%s %d", S, &A[i]);	
		}
		if(f(A,N,K)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
