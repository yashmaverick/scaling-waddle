#include<stdio.h>
int main(){
		long long testcases,Q;
		long long log,temp;
		long long checknum;
		scanf("%lld" ,&testcases);
		while(testcases--){
				scanf("%lld" ,&Q);
				log=0;
				temp=Q;
				while(temp!=1){
						log++;
						temp=temp>>1;
				}
				checknum= ((1<<log) + (1<<(log-1)));
				if(Q>=checknum){
						printf("%lld\n" ,(2*log));
				}
				else{
						printf("%lld\n" ,((2*log)-1));
				}
		}
		return 0;
}
