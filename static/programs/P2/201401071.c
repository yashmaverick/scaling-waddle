#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 100011
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

#define din(x) scanf("%d", x)

int main(){
	int P[M], Q[M], R[M];
	unsigned long long P1, Q1;
	int p, q, r;
	int T;
	int i, j, k;
	din(&T);
	while(T--){
		din(&p);
		for(i=1; i<=p; i++)
			din(&P[i]);
		din(&q);
		for(i=1; i<=q; i++)
			din(&Q[i]);
		din(&r);
		for(i=1; i<=r; i++)
			din(&R[i]);
		Q1 = 0;
		P1 = 0;
		for(k=p, j=q, i=r; k>=1; k--){
			while(Q[j]>=P[k] && j>=k){
				while(R[i]>=Q[j] && i>=j){
					i--;
				}
				Q1 = Q1+r-i;
				j--;
			}
			P1 = P1+Q1;
		}
		printf("%llu\n", P1);
	}
	return 0;
}
