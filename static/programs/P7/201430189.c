#include<stdio.h>
#include<stdlib.h>
int main(){
		long long answer,testcases,n,i,var,hash[1000001];
		scanf("%lld" ,&testcases);
		while(testcases--){
				scanf("%lld" ,&n);
				for(i=0;i<1000001;i++)
						hash[i]=0;
				answer=0;
				for(i=0;i<n;i++){
						scanf("%lld" ,&var);
						hash[((var+10000000)%1000001)]++;
				}
				for(i=0;i<1000001;i++){
						answer+=((hash[i]*(hash[i]-1))/2);
				}
				printf("%lld\n" ,answer);
		}
		return 0;
}


