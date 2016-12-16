#include<stdio.h>
#include<math.h>

int main(){
	int n,i,j,k,q;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&q);
		k=0;
		j=q;
		if(q!=1){
			while(j!=1){
				j=j/2;
				k++;
			}
			if(q<(pow(2,k)+pow(2,k-1))){
				printf("%d\n",2*k-1);
			}
			else{
				printf("%d\n",2*k);
			}
		}
		else{
			printf("0\n");
		}
	}
	return 0;
}