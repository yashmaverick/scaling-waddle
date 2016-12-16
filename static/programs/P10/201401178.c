#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int ele[100];
}node;
int main(){
	int i,size;
	scanf("%d",&size);
	node a[size];
	int start=0, end=-1;
	int capacity=0;
	while(1){
		int n;
		char q,p;
		scanf("%c",&q);
		if(q=='A'){
			scanf("%d",&n);
			for(i=0;i<n;i++){
				end=(++end)%(size);
			//	printf("e=%d\n",end);
				if(end==start && capacity==size){
					start=(++start)%(size);
					//printf("s=%d\n",start);
				}
				if(capacity<size){
					capacity++;
				}
				//a[i].ele=malloc(sizeof(char)*100);
				scanf("%s",a[end].ele);
				//	printf("%s scanned\n",a[end].ele);
			}
		}
		if(q=='R'){
			scanf("%d",&n);
		//	if(start==end && ){
		//		start=0;
			//	end=-1;
			//}
			if(n==capacity){
				start=0;
				end=-1;
				capacity=0;
			}
			else{
				for(i=0;i<n;i++){
				//start=(start++)%size;
					start=(++start)%size;
					if(capacity>0){
						capacity--;
					}
				}
			}
		}
		if(q=='L'){
			//		printf("start=%d end=%d\n",start,end);
			if(start<=end){
				for(i=start;i<=end;i++){
					int j;
					printf("%s\n",a[i].ele);
				}
			}
			else{
				if(end!=-1){
					for(i=start;i<size;i++){
						printf("%s\n",a[i].ele);
					}
					for(i=0;i<=end;i++){
						printf("%s\n",a[i].ele);
					}
				}
				//else{
				//	printf("");
				//}
			}
		}
		if(q=='Q'){
			break;
		}
	}
	return 0;
}
