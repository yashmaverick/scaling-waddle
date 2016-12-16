#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
void mergesort();
int flag;
int main() {
	int test;
	scanf("%d", &test);
	while(test--){
		flag=0;
		int n,i,k;
		char **A=(char **)malloc(sizeof(char *)*100000);
		char **B=(char **)malloc(sizeof(char *)*100000);
		for (i = 0; i < 100000; i++) {
			A[i]=(char *)malloc(sizeof(char)*10);
			B[i]=(char *)malloc(sizeof(char)*10);
		}
		scanf("%d", &n);
		for ( i = 0; i < n; i++) {
			scanf("%s", A[i]);
		}
		mergesort(A, 0, n-1,B);
	/*for (i = 0; i < n; i++) {
		printf("%s\n",A[i] );
	}*/
		int temp_flag=0;
		if(flag==0){
			for (i = 0; i < n-1; i++) {
				k=0;
				while(A[i][k]!='\0' && A[i+1][k]!='\0' && A[i+1][k]==A[i][k]){
					k++;
				}
				if(k==strlen(A[i]) || k==strlen(A[i+1])){
					temp_flag=1;
					printf("NO\n");
					break;
				}
			}
			if (temp_flag==0)	 {
				printf("YES\n");
			}
		}
		for (i=0;i<100000;i++){
			// free(B[i]);
			free(A[i]);
		}
		// free(B);
		free(A);
	}
	return 0;	
}
void mergesort(char **A, int low, int up, char **B){
	int i,j,k;
	if(low==up){
		return ;
	}
	if(low+1==up){
		i=0;
		while(A[low][i]==A[up][i] && A[low][i]!='\0' && A[up][i]!='\0'){
			i++;
		}
		int len_a=strlen(A[low]);
		int len_b=strlen(A[up]);
		if(i==len_b || i==len_a){
			if(flag==0){
				printf("NO\n");
				flag=1;
			}
			return ;
		}
		if(A[low][i] > A[up][i]){
			char *temp;
			temp=A[low];
			A[low]=A[up];
			A[up]=temp;
		}
		return ;
	}
	int mid;
	mid=(low+up)/2;
	mergesort(A,low,mid,B);
	mergesort(A,mid+1,up,B);
	int a,b;
	a=low;
	b=mid+1;
	int c=a;
	while(a<=mid&&b<=up){
		i=0;
		while(A[a][i]==A[b][i] && A[a][i]!='\0' && A[b][i]!='\0'){
			i++;
		}
		if(A[a][i]<A[b][i]){
			B[c++]=A[a++];
		}
		else{
			B[c++]=A[b++];
		}
	}
	if(a<=mid){
		while(a<=mid){
			B[c++]=A[a++];
		}
	}
	else if(b<=up){
		while(b<=up){
			B[c++]=A[b++];
		}
	}
	for(i=low;i<=up;i++){
		A[i]=B[i];
	}
	return ;
}
//failing test case is 5 :-123, 456, 49, 321, 45