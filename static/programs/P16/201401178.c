#include<stdio.h>
#include<math.h>
int main(){
	int test,i;
	scanf("%d",&test);
	for(i=0;i<test;i++){
		int q;
		scanf("%d",&q);
		int n=0,depth;
		while(1){
			if(q>pow(2,n)){
				n++;
			}
			else if(q==pow(2,n)){
				depth=n;
				break;
			}
			else{
				depth=n-1;
				break;
			}
		}
		if(q==1){
			printf("0\n");
		}
		else{
			if(q<=(pow(2,depth)+pow(2,(depth-1))-1)){
				printf("%d\n",((2*depth)-1));
			}
			else{
				printf("%d\n",(2*depth));
			}
		}
	}
	return 0;
}
