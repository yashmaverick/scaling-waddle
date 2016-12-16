#include<stdio.h>
int main(){
		long long int testcases,i,j,k;
		long long int answer,P,Q,R,A[100001],B[100001],C[100001];
		scanf("%lld" ,&testcases);
		while(testcases--){
				scanf("%lld" ,&P);
				for(i=0;i<P;i++)
						scanf("%lld" ,A+i);
				scanf("%lld" ,&Q);
				for(i=0;i<Q;i++)
						scanf("%lld" ,B+i);
				scanf("%lld" ,&R);
				for(i=0;i<R;i++)
						scanf("%lld" ,C+i);
				answer=i=j=k=0;
				if(Q>R)
						Q=R;
				if(P>Q)
						P=Q;
				while(j<Q){
						while(A[i]<=B[j] && i<=j && i<P){
								i++;
						}
						while(C[k]<B[j] && k<R)
								k++;
						if(j>k)
								k=j;
						answer+=(i*(R-k));
						j++;
				}
				printf("%lld\n" ,answer);
		}
		return 0;
}
