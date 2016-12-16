#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define K 100000

#define MAX 100010


int val(char c){
	if(c=='M')
		return K;
	if(c=='J')
		return 1;
	return -K-1;
}

int compare(const void *a, const void *b){
	return *((int*)a)-*((int*)b);
}

void print_array(int *A, int len){
	int i;
	for(i=0; i<len; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

int f(char *S, int len){
	int A[MAX];
	int i;
	A[0] = val(S[0]);
	for(i=1; i<len; i++){
		A[i] = A[i-1]+val(S[i]);
	}
	//print_array(A, len);
	qsort(A, len, sizeof(int), compare);
	//print_array(A, len);
	int counter=1;
	int curr_val = A[0];
	int nos=0;
	for(i=1; i<len; i++){
		if(A[i] == curr_val){
			counter += 1;
		}
		else{
			nos += (counter)*(counter-1)/2;
			if(curr_val==0) nos += counter;
			counter=1;
			curr_val = A[i];
		}
	}
	nos += (counter)*(counter-1)/2;
	return nos;
}


int main(){
	char S[MAX];
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", S);
		printf("%d\n", f(S, strlen(S)));
	}

	return 0;
}
