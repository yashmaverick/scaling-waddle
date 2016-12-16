#include<stdio.h>

int main(){
	long long int t;
	scanf("%lld",&t);
	while(t--){
		long long int i,n;
		scanf("%lld",&n);
		long long int a[n];
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}

		long long int high[n],low[n];
		high[n-1]=a[n-1];
		low[0]=a[0];
		
		for(i=1;i<n;i++){
			if(a[i] < low[i-1])
				low[i]=a[i];
			else
				low[i]=low[i-1];
		}
		
		for(i=n-2;i>=0;i--){
			if(a[i] > high[i+1])
				high[i]=a[i];
			else
				high[i]=high[i+1];
		}
		long long int pmax=0;
		for(i=0;i<n;i++){
			if(high[i]-low[i] >pmax)
				pmax=high[i]-low[i];
		}

		printf("%lld\n",pmax);
	}
	return 0;
}
