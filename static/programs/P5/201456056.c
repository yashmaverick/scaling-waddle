#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b){
	return *(int*)a-*(int*)b;
}

int binary_search(int A[], int key, int l, int r){
	int mid;
	while(l<=r){
		mid = (l+r)/2;
		if(A[mid]>key) r = mid-1;
		else if(A[mid]<key) l = mid+1;
		else return mid;
	}
	return -1;
}


int find(int A[], int N, int K){
	int i, j;
	for(i=0; i<N; i++){
		for(j=i+1; j<N; j++){
			if(binary_search(A, K-(A[i]+A[j]), j+1, N-1)>=0){
				return 1;
			}
		}
	}
	return 0;

}

int main(){
	int T, N, K, t;
	int A[1010]; 
	char S[101];
	int i;
	scanf("%d", &T);
	for(t=0; t<T; t++){
		scanf("%d %d", &N, &K);
		for(i=0; i<N; i++){
			scanf("%s %d", S, &A[i]);
		}
		qsort(A, N, sizeof(int), compare);
		printf("%s\n", find(A, N, K)?"YES":"NO");
	}
	return 0;
}
