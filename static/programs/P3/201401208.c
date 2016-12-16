#include<stdio.h>

long int a[100002];
long int b[100002];
long int max_profit(long int *a,int n);
int main(){
	int t,n,i,j,flag=0;
	long int result;
	scanf("%d",&t);
	while(t--){
		flag=0;
		result=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%ld",&a[i]);
		}
//		for(i=0;i<n;i++)
//			printf("%ld ",a[i]);
//		printf("\n");
		for(j=0;j<n;j++){
			if(a[j]<0){
			flag=1;
			break;
			}
		}
		if(flag==0){
			for(j=0;j<n-1;j++)
				b[j]=a[j+1]-a[j];

			result=max_profit(b,n);
			if(result<0)
				result=0;
			printf("%ld\n",result);
		}
	}
	return 0;
}

long int max_profit(long int *b,int n){
	long int profit,curr;
	int i;
	profit=b[0];
	for(i=0;i<n-1;i++){
		if(b[i-1]>=0)
			b[i]+=b[i-1];

		if(profit<b[i]){
			profit=b[i];
			//			printf("%ld ",profit);
		}
	}
	//	printf("\n");
	return profit;
}
