#include<stdio.h>

long long int a[10005];
long long int least=1000000005;
//long long int least2=1000000005;
void min(long long int start,long long int end);
int main(){
	long long int n,k,t,i,j;
	scanf("%lld",&t);
	while(t--){
		least=1000000005;
		scanf("%lld %lld",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);

		for(i=1;i<=k;i++){
			if(a[i] <=least){
				least=a[i];
			}
		}
		printf("%lld",least);
		if(n != k)
			printf(" ");
		for(i=2;i<=n-k+1;i++){
			min(i,i+k-1);
			if(i!=n-k+1)
				printf(" ");
		}

		printf("\n");

	}
	return 0;
}

void min(long long int start,long long int end){
	long long int i;

	if(a[end] <= least){
		least=a[end];
		}

	else if(a[end]>least && least!=a[start-1]);


	else{
		least=a[start];
		for(i=start+1;i<=end;i++){
			if(a[i] <=least){
				least=a[i];
			}
		}
	}

	printf("%lld",least);
}
