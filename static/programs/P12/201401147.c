#include<stdio.h>
int main(){
	long long int N;
	while(1){
		scanf("%lld",&N);
		long long int i;
		long long int localmax=0;
		long long int j,count=0;
		long long int a[500002];
		if(N==0)
			break;
		for(i=0;i<N;i++)
			scanf("%lld",&a[i]);
		if(N==1 || N==2)
			printf("0\n");
		else{
			for(i=0;i<=N-2;i++){
				localmax=a[i+1];
				for(j=i+1;j<=N-1;j++){
					if(a[j]>a[i]){
						count+=N-1-j;
						break;
					}
					else if(a[j] < localmax)
						count++;
					if(a[j]>localmax)
						localmax=a[j];
				}
			}
			printf("%lld\n",count);
		}
	}
	return 0;
}
