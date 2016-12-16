#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int i,j,k,a,n,b,min,max,test, min_value,max_value,flag;
	scanf("%d",&n);
	int *A=(int *)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	int B[1000000];
	for (i = 0; i < n; i++) {
		scanf("%d",&a);
		B[a]=i;
	}
	scanf("%d", &test);
	for (k = 0; k < test; k++){
		scanf("%d%d",&a,&b);
		// printf("%d and %d\n",a,b);
		if(B[b]>B[a]){
			max=B[b];
			min_value=a;
			max_value=b;
			min=B[a];
			// printf("max index is %d, min index is %d and min_value is %d\n",max, min, min_value);
		}
		else{
			max=B[a];
			min_value=b;
			max_value=a;
			min=B[b];
			// printf("max index is %d, min index is %d and min_value is %d\n",max, min, min_value);
		}
		flag=0;
		i=0;
		while(A[i]!=min_value && A[i]!=max_value){
			if(B[A[i]] > min && B[A[i]] < max){
				printf("%d\n",A[i]);
				flag=1;
				break;
			}
		i++;
		}
		if(flag==0){
			printf("%d\n",A[i]);
		}
	}
	free(A);
	return 0;
}