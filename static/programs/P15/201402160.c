#include<stdio.h>
#define N 100034
#define s(n) scanf("%lld", &n)
#define p(n) printf("%lld ", n)
#define forn(i, n) for(i=0; i<n; i++)
#define LL long long int

LL a[N], n, k, t;
LL deq[N], front, back;

int main(){
	LL i, j;
	scanf("%lld\n", &t); //p(t);
	while(t--){
		scanf("%lld %lld", &n, &k);
		//p(n); p(k);
		forn(i, n)s(a[i]);
		if(k>n)k=n;
		front=back=0; deq[0]=0;
		//if(k==0)while(1);
		if(k==0){
			for(i=0; i<n; i++)printf("1000000001 ");
			printf("1000000001\n");
			continue;
		}
		if(k==1){	
			for(i=0; i<n-1; i++)printf("%lld ", a[i]);
			printf("%lld\n", a[n-1]);
			continue;
		}
		for(i=1; i<n; i++){
			while(deq[front]<=i-k)front++;
			
			//if(back-front+1==k)front++;
			//printf("\n");
			//for(j=front; j<=back; j++)p(a[deq[j]]); printf("\n");
			while(back>=front && a[deq[back]]>a[i])back--; back++; deq[back]=i;
			if(i>=k-1){	
				if(i==n-1)printf("%lld\n", a[deq[front]]);
				else p(a[deq[front]]);
			}
		}
	}
	return 0;
}
		
