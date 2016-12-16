#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int t,n,temp,r;
	scanf("%d",&t);
while(t--){
		scanf("%d",&n);
			temp= log2(n);
			r= n-pow(2,temp);
			if(r >(pow(2,temp-1)-1)){
					temp= 2*temp;
					printf("%d\n",temp);
				}
			else{
					temp= (2*temp)-1;
					printf("%d\n", temp);
				}
		
	}
		return 0;
}