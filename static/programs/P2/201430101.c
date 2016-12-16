#include <stdio.h>

#define MAX 100020

void printarr(long long *A, int len){
	int i;
	for(i=0; i<len; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}


void resetarr(long long *A, int len){
	int i;
	for(i=0; i<len; i++){
		A[i] = 0;
	}
}


int main(){
	int i, j, T, P[MAX], Q[MAX], R[MAX], p, q, r;
	int lim;
	long long t1[MAX], ans;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &p);
		for(i=0; i<p; i++)
			scanf("%d", &P[i]);
		scanf("%d", &q);
		for(i=0; i<q; i++)
			scanf("%d", &Q[i]);
		scanf("%d", &r);
		for(i=0; i<r; i++)
			scanf("%d", &R[i]);
		resetarr(t1, q+1);
		//printarr(t1, q+1);
		j = 0;
		for(i=0; i<q; i++){
			if(j<i) j=i;
			if(j>r) j=r;
			for(; j<r && R[j]<Q[i]; j++);
			t1[i] = r-j;
		}
		//printarr(t1, q);
		for(i=q-2; i>=0; i--){
			t1[i] += t1[i+1];
		}
		//printarr(t1, q);
		j = 0;
		ans = 0;
		lim = (q<p)?q:p;
		for(i=0; i<lim; i++){
			if(j<i) j=i;
			if(j>q) j=q;
			for(; j<q && Q[j]<P[i]; j++);
			ans += t1[j];
			//printf("%d %d %lld %lld\n", i, j, t1[j], ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
