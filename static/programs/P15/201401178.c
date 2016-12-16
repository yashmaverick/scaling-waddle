#include<stdio.h>
int main(){
	int test,z;
	scanf("%d",&test);
	for(z=0;z<test;z++){
		int N,K,i,j,min=99999999,index;
		scanf("%d %d",&N,&K);
		int a[N];
		for(i=0;i<N;i++){
			scanf("%d",&a[i]);
			if(i<K && a[i]<min){
				min=a[i];
				index=i;
				}
		}
		for(i=0;i<N-K+1;i++){
			if(i!=N-K)
				printf("%d ",min);
			else
				printf("%d",min);
			if(i==index){
				if(a[i+K]<min){
					min=a[i+K];
					index=i+K;
				}
				else if(a[i+K]>=min){
					min=99999999;
					for(j=i+1;j<i+K+1;j++){
						if(min>a[j]){
							min=a[j];
							index=j;
						}
					}
				}
			}
			else if(i!=index){
				if(a[i+K]<min){
					min=a[i+K];
					index=i+K;
				}
			}
		}
		printf("\n");
	}
	return 0;
}
