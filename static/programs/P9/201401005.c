#include<stdio.h>
#include<stdlib.h>

long long int **a;
/*
void merge(int **A, int l, int m, int r){
	int i, j, k;
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1], R[n2];
	int *P[n1], *Q[n2];

	for(i=0; i<n1; i++){
		L[i] = A[l+i][0];
		P[i] = A[l+i];
	}

	for(j=0; j<n2; j++){
		R[j] = A[m+1+j][0];
		Q[j] = A[m+1+j];
	}

	i = 0; j = 0; k = l;
	while(i<n1 && j<n2){
		if(L[i] <= R[j])
			P[i++] = A[k++];
		else
			Q[j++] = A[k++];
	}	

	while(i<n1)
			A[k++] = P[i++];
	while(j<n2)
			A[k++] = Q[j++];
}

void msort(int **A, int l, int r){
	if(l < r){
		int m=l+(r-l)/2;
		msort(A, l, m);
		msort(A, m+1, r);
		merge(A, l, m, r);
	}
}*/

void isort(int **A, int n){
	int i, j, fl;
	int *temp;
	for(i=1; i<n; i++){
		fl = A[i][0];
		j = i-1;
		while(fl<A[j][0] && j>=0){
			temp = A[j+1];
			A[j+1] = A[j];
			A[j] = temp;
			j--;
		}
		A[j+1] = temp;
	}
}

void ssort(int **A, int n){
	int i, j, *temp;
	for(i=0; i<n; ++i){
		for(j=i+1; j<n; ++j){
			if(A[i][0] > A[j][0]){
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

void bsort(long long int **A, long long int n){
	long long int i, j, fl, *temp;
	for(i=0; i<n; i++){
		fl = 0;
		for(j=0; j<n-i-1; j++){
			if(A[j][0] > A[j+1][0]){
				temp = A[j];
				A[j] = A[j+1];
				A[j+1] = temp;
				fl = 1;
			}
		}
		if(fl == 0)
			break;
	}
}

void init1(long long int **arr, long long int n){
	a = (long long int**)malloc(n*sizeof(long long int*));
}

void init2(long long int **arr, long long int m, long long int i){
	arr[i] = (long long int*)malloc((m+2)*sizeof(long long int));
	a[i][0] = 0;
}

int main(){
	long long n, m, mod, w, i, j;
	scanf("%lld%lld", &n, &mod);
	init1(a, n);
	for(i=0; i<n; i++){
		scanf("%lld", &m);
		init2(a, m, i);
		for(j=2; j<=m+1; j++){
			scanf("%lld", &w);
			a[i][0] += w%mod;
			a[i][j] = w;
			a[i][1]++;
		}
		a[i][0] = a[i][0]%mod;
	}

	bsort(a, n);

	for(i=0; i<n; i++){
		for(j=0; j<=a[i][1]+1; j++){
			if(j==1)
				;
			else
				printf("%lld\n", a[i][j]);
		}
		printf("\n");
	}

	return 0;
}
