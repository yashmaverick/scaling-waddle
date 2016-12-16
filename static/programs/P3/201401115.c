#include<stdio.h>
long long int cmpfunc (const void * a, const void * b)
{
   return ( *(long long int*)a - *(long long int*)b );
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		long long int min,size,A[100000],i,B[100000],maxdiff=0,j,k;
		scanf("%lld",&size);
		for(i=0;i<size;i++){
			scanf("%lld",&A[i]);
			//B[i] = A[i];
		}
		min = A[0];
		for(i=0;i<size;i++){
			if(A[i]>min){
				if(A[i] - min > maxdiff){
					maxdiff = A[i] - min;
				}
			}
			else{
				min = A[i];
			}
		}
		printf("%lld\n",maxdiff);
	}
	return 0;
}