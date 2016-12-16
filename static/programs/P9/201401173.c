#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define loop(n) for(i=0;i<n;i++)
#include<stdio.h>
#include<stdlib.h>
typedef struct pair pair;
struct pair{
	long long int f;
	int s;
};
int cmp(pair p1,pair p2){
	return (p1.f<p2.f)||((p1.f==p2.f)&&(p1.s<p2.s));
}
/*void print(pair p){
	printf("(%lld %d)\n",p.f,p.s);
	return;
}*/
void sort(pair arr[],int n){
	int i,j;
	pair tmp;
	for(j=0;j<n-1;j++){
		for(i=0;i<n-1;i++){
			if(!cmp(arr[i],arr[i+1])){
				tmp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=tmp;
			}
		}
	}
	return;
}
int main(){
	typedef long long int lli;
	int N,M;
	int i,j,k;
	lli w,iw;
	lli mod;
	int items[1001];
	pair pw[1001];
	scanf("%d %lld",&N,&mod);
	int** bag=(int**)malloc(N*sizeof(int*));
	for(i=0;i<N;i++){
		w=0;
		si(M);
		items[i]=M;
		*(bag+i)=(int*)malloc(M*sizeof(int));
		for(j=0;j<M;j++){
			si(*(*(bag+i)+j));
			iw=*(*(bag+i)+j);
			w+=iw%mod;
			w%=mod;
		}
		pw[i].f=w;
		pw[i].s=i;
	}
	/*for(i=0;i<N;i++){
		for(j=0;j<items[i];j++){
			printf("%d ",*(*(bag+i)+j));
		}
		printf("\n");
	}*/
	sort(pw,N);
	loop(N){
		pl(pw[i].f);
		k=pw[i].s;
		for(j=0;j<items[k];j++){
			printf("%d\n",*(*(bag+k)+j));
		}
		printf("\n");
		//printf("\n");
	}
		return 0;
	}
