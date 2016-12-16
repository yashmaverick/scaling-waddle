#include <stdio.h>
#include <stdlib.h>

int buble_sort();

int main() {
int n,i,m,j;
int sum,a, mod;
scanf("%d%d", &n, &mod);

int **A=(int **)malloc(n*sizeof(int *));
int *number=(int *)malloc(n*sizeof(int));
int *index=(int *)malloc(n*sizeof(int));
int *total_weight=(int *)malloc(n*sizeof(int));

	for (i = 0; i < n; i++) {
		index[i]=i;
		sum=0;
		scanf("%d", &m);
		A[i]=(int *)malloc(m*sizeof(int));
		number[i]=m;
		 // printf("entries for %d %d\n",n,m);
		for (j = 0; j < m; j++)	{
			scanf("%d", &a);
			sum=((sum+a)%mod);
			A[i][j]=a;
			 // printf("A[%d][%d] = %d ",i,j,A[i][j]);
		}
		total_weight[i]=sum%mod;
		 // printf("total_weight is %d\n", sum);

	}
buble_sort(total_weight, index, n);
for(i=0;i<n;i++){
	// printf("total_weight = %d with index = %d\n",total_weight[i], index[i]);
	printf("%d\n",total_weight[i]);
	for (j = 0; j < number[index[i]]; j++)
	{

		printf("%d\n",A[index[i]][j]);
	}
	printf("\n");
}
	return 0;
}
	

int buble_sort(int A[], int B[], int n){
	int i,j;
	int a;
	int temp;
	for ( i = 0; i < n; i++) {
		for (j = i+1; j < n; j++) {
			if(A[j]<A[i]){
				
				/*temp=A[i];
				A[i]=A[j];
				A[j]=temp;

				temp=B[i];
				B[i]=B[j];
				B[j]=temp;
*/
				A[i]=A[i]^A[j];
				A[j]=A[i]^A[j];
				A[i]=A[i]^A[j];

				B[i]=B[i]^B[j];
				B[j]=B[i]^B[j];
				B[i]=B[i]^B[j];

			}
		}
	}
return 0;
}



/*int mergesort(int A[], int B[], int low, int up){
	int mid;
	mid=(low+up)/2;
	if(low==up)
		return 0;
	else if(low==(up-1)){
		if(A[low]<=A[up])
			return 0;
		else{
			swap(A,low,up);
			swap(B,low,up);
			// swap(C,low,up);
			return 0;
		}
	}
	else{
			mergesort(A, B, C, low, mid);
			mergesort(A, B, C, mid+1, up);
	}

	int a=low;
	int b=(mid+1);
	int c=a;
	for (i = low; i <= up; i++)	{
		extra[i]=A[i];
	}
	while(a<=mid && b<=up){

		if(extra[a] < extra[b]){
			A[c++]=extra[a];
			a++;
		}
		else{
			A[c++]=extra[b];
			b++
		}

	}
	
	if(a > mid && b<up){
			while(c<=up)
			A[c++]=extra[b++];
	}
	else if(a<mid && b>up){
			while(c<=up)
				A[c++]=extra[a++];
	}

	for (i=low;i<=up;i++){
			A[i]=extra[i];
	}

return 0;
}

*/