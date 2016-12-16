#include<stdio.h>
int a[100000];
int min(int start,int end){
	int value=a[start];
	int i;
	for(i=start+1;i<=end;i++){
		if(a[i]<value)
			value=a[i];
	}
	return value;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int N,k;
		scanf("%d%d",&N,&k);
		int b[100000];
		int i;
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		b[0]=min(0,k-1);
		for(i=1;i<N-k+1;i++){
			if(b[i-1]!=a[i-1]){
				b[i]=(b[i-1] > a[i+k-1])?a[i+k-1]:b[i-1];
			}
			else{
				b[i]=min(i,i+k-1);
			}
		}int flag=0;
		for(i=0;i<N-k+1;i++){
			if(i==N-k)
				flag=1;
			printf("%d",b[i]);
			if(flag!=1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}


