#include <stdio.h>
#define min(a,b) (a)<(b)?(a):(b)

void nkmin(int arr[], int n, int k)
{
	int L[n], R[n];
	int x=n-k+1, i;
	int min[x];

	for(i=1; i<=n; i++){
		if(i%k == 1)
			L[i] = arr[i];
		else
			L[i] = min(L[i - 1], arr[i]);
	}

	R[n] = arr[n];
	for(i=n-1; i>=1; i--){
		if(i%k == 0)
			R[i] = arr[i];
		else
			R[i] = min(R[i+1], arr[i]);
	}

	for(i=1; i<=x; i++)
		min[i] = min(R[i], L[i + k - 1]);

	for(i=1; i<x; i++)
		printf("%d ", min[i]);
	printf("%d\n", min[i]);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, k, a[100001], i, j;
		scanf("%d%d", &n, &k);
		for(i=1; i<=n; i++)
			scanf("%d", &a[i]);
		if(k == 1){
			for(i=1; i<n; i++)
				printf("%d ", a[i]);
			printf("%d\n", a[n]);
		}
		else
			nkmin(a, n, k);
	}
	return 0;
}
