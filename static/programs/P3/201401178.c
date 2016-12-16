#include<stdio.h>
int main(){
	int test,i;
	scanf("%d",&test);
	for(i=0;i<test;i++){
		int size,n,arr[100000],min,max,diff=0,min2=100000000;
		scanf("%d",&size);
		for(n=0;n<size;n++){
			scanf("%d",&arr[n]);
			if(n==0){
				min=arr[n];
				max=arr[n];
			}
			if(arr[n]<min&&arr[n]<min2){
				min2=arr[n];
			}
			if(arr[n]>max){
				max=arr[n];
			}
			if(arr[n]-min2>diff){
				min=min2;
				max=arr[n];
			}
			diff=max-min;
		}
		printf("%d\n",diff);
	}
	return 0;
}

