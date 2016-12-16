#include<stdio.h>

int main(){
	long long n, q, i;
	long long pre[1001], sum[1001];
	scanf("%lld", &n);
	while(n--){
		scanf("%lld", &q);

		if(q == 1)
			printf("0\n");
		else{
			pre[0] = 1;
			for(i=1; i<=30; i++)
				pre[i] = 2*pre[i-1];
			//	for(i=0; i<=30; i++)
			//		printf("%lld ", pre[i]);
			//	printf("\n");

			for(i=0; i<30; i++)
				sum[i] = pre[i+1]-1;
			sum[30] = pre[30]*2-1;
//			for(i=0; i<=30; i++)
//				printf("%lld ", sum[i]);
//			printf("\n");

			i = 0;
			while(q > sum[i])
				i++;
//			printf("i = %lld\n", i);

			if(q <= sum[i] && q > sum[i]-pre[i-1]){
				printf("%lld\n", 2*(i));
			}
			else if(q >= sum[i-1]+1 && q <= sum[i]-pre[i-1]){
				printf("%lld\n", 2*(i)-1);
			}
		}
	}
	
	return 0;
}
