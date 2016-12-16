#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void max_insert(long long int A[],long long int val,long long int count){
	A[count]=val;
	long long int temp;
	while(A[count] > A[count/2] && count>1){
		temp=A[count];
		A[count]=A[count/2];
		A[count/2]=temp;
		count=count/2;
	}
}


long long int max_delete(long long int A[],long long int count){
	long long int max=count;
	long long int final=A[1];
	A[1]=A[count];
	A[count]=-1;
	count=1;
	long long int temp;
	while( (A[count] < A[2*count] || A[count] < A[2*count+1]) && ( (2*count+1)<max || 2*count<max) ){
		if(A[2*count] > A[2*count+1]){
			// printf("If Swapping %d and %d\n",A[count],A[2*count] );
			temp=A[count];
			A[count]=A[2*count];
			A[2*count]=temp;
			count=2*count;
		}
		else{
			// printf("Else Swapping %d and %d\n",A[count],A[2*count+1] );
			temp=A[2*count+1];
			A[2*count+1]=A[count];
			A[count]=temp;
			count=(2*count+1);	
		}
	}
	return final;
}



void min_insert(long long int A[],long long int val,long long int count){
	A[count]=val;
	long long int temp;
	while(A[count] < A[count/2] && count>1){
		temp=A[count];
		A[count]=A[count/2];
		A[count/2]=temp;
		count=count/2;
	}
}

long long int min_delete(long long int A[],long long int count){
	long long int max=count;
	long long int final=A[1];
	A[1]=A[count];
	A[count]=92233720368547750;
	count=1;
	long long int temp;
	while( (A[count] > A[2*count] || A[count] > A[2*count+1]) && ( (2*count+1)<max || 2*count<max) ){
		if(A[2*count] < A[2*count+1]){
			// printf("If Swapping %d and %d\n",A[count],A[2*count] );
			temp=A[count];
			A[count]=A[2*count];
			A[2*count]=temp;
			count=2*count;
		}
		else{
			// printf("Else Swapping %d and %d\n",A[count],A[2*count+1] );
			temp=A[2*count+1];
			A[2*count+1]=A[count];
			A[count]=temp;
			count=(2*count+1);	
		}
	}
	return final;
}


int main() {
	int test;
	scanf("%d", &test);
	while(test--){
		long long int x,y,z;
		long long int n,i,a,A[200005],B[200005];
		for (i=0;i<200005;i++){
			A[i]=92233720368547750;
			B[i]=-1;
		}
		scanf("%lld%lld%lld",&x,&y,&z);
		scanf("%lld", &n);
		long long int max_count=1,min_count=1;
		
		//First insert 1 into the max heap
		max_insert(B,1,max_count);
		max_count++;

		/*for (i = 1; i < max_count; i++) {

			printf("%lld\n",B[i] );
		}*/
		// printf("Completed inserting B[1]");
		// scanf("%lld", &i);
		long long int sum=B[1];
long long int temp;
		for (i = 2; i <= n; i++) {
			//Just below this, put a as what do you want to insert
			// printf("At the starting B[max_count-1] is %lld ",B[max_count-1]);
			a=((((x*B[1])%1000000007+(y*i)%1000000007))%1000000007+z)%1000000007;
			// scanf("%lld", &a);
			sum=sum+a;
			// printf("And value generated is %lld\n",a );
			if(i%2==1){
				// printf("Insert into max heap\n");
				if(a > A[1]){
					// printf("If condition of max heap\n");
					temp=min_delete(A, min_count-1);
					min_count--;
					// printf("min_count is %lld\n", min_count);

					// printf("Temp is %lld\n",temp);
				/*	for (j = 1; j < min_count; j++) {
						printf("%lld\n",A[j] );
					}*/
					max_insert(B,temp, max_count);
					max_count++;
					min_insert(A,a,min_count);
					min_count++;
				}
				else{
					// printf("Else condition of min heap\n");
					max_insert(B, a, max_count);
					max_count++;
				}
			}
			else{
				// printf("Else insert into min heap, which is on the right side\n");
				if(a < B[1]){
					// printf("If condition of min heap\n");
					min_insert(A, max_delete(B, max_count-1), min_count);
					min_count++;
					max_count--;
					max_insert(B, a, max_count);
					max_count++;
				}
				else{
					// printf("Else condition of min heap\n");
					min_insert(A, a, min_count);
					min_count++;
				}
			}
			/*printf("Printing the complete list with i=%lld\n", i);
		for (j = 1; j < max_count; j++) {
			printf("%lld ",B[j]);
		}
		printf(" -> ");
		for (j = 1; j < min_count; j++) {
			printf("%lld ",A[j]);
		}
		puts("");
*/
	}
	printf("%lld\n",sum);
}

return 0;
}