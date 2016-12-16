#include <stdio.h>
#define fr(x) scanf("%lld",&x)

long long int h[1000010],k,n;

int check(long long int y){
	long long int z=0;
	int i;
	for(i=1;i<=n;++i){
		if(h[i]<y){
			z+=y-h[i];
		}
	}
	if(z<=k)return 1;
	else return 0;
}

signed main(){
	long long int lo,hi,mid;
	int i;
	fr(n);
	lo=0;
	hi=100000001000LL;
	for(i=1;i<=n;++i){
		fr(h[i]);
	}
	fr(k);
	while(lo<hi){
		mid=lo+((hi-lo+1)/2);
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	printf("%lld\n",lo);
	return 0;
}
