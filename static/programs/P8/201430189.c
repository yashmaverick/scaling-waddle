#include<stdio.h>
long long fastexp(long long A,long long e,long long N){
		if(e==0)
				return 1;
		else if(e==1)
				return A%N;
		else if(e%2==0){
				long long k=fastexp(A,e/2,N);
				return (k*k)%N;
		}
		else{
				long long k=fastexp(A,(e-1)/2,N);
				return (k*k*A)%N;
		}
}

long long func(long long A1,long long A2,long long A3,long long d,long long N){
		if(d==0)
				return (3%N);
		long long e1=fastexp(A1,d,N);
		long long e2=fastexp(A2,d,N);
		long long e3=fastexp(A3,d,N);
		return ((e1+e2+e3)%N);
}

int main(){
		long long testcases,m,N;
		long long uplim,d;
		long long A1,A2,A3,i;
		long long numnum,num[40],answer;
		scanf("%lld" ,&testcases);
		while(testcases--){
				answer=0;
				scanf("%lld%lld%lld%lld" ,&uplim,&d,&m,&N);
				//finding number of such numbers
				i=0;
				numnum=uplim/N;
				while(i<=(uplim%N)){
						num[i]=numnum+1;
						i++;
				}
				while(i<N){
						num[i]=numnum;
						i++;
				}
				//solving for N numbers
				for(A1=0;A1<N;A1++){
						for(A2=0;A2<N;A2++){
								for(A3=0;A3<N;A3++){
										if(func(A1,A2,A3,d,N)==m){
												answer+=((((num[A1]*num[A2])%1000000007)*num[A3])%1000000007);
												answer=answer%1000000007;
										}
								}
						}
				}
				printf("%lld\n" ,answer);
		}
		return 0;
}
