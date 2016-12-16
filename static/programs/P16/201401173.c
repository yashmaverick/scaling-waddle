#include<stdio.h>
typedef long long int lli;
int l2(int i){
	int l=0;
	while (i >>= 1) { ++l; }
	return l;
}
lli p2(int p){
	lli a=1;
	while(p--){a=a<<1;}
	return a;
}
int main(){
	//printf("%d\n",l2(1));
	//printf("%d\n",p2(5));
	int n,t;
	lli ans;
	scanf("%d",&t);
	while(t--){
	scanf("%d",&n);
	int l=l2(n);
	int pl=l-1;
	int tl=2*pl;
	lli r=p2(l);
	r+=r/2;
	if(n<r)
		ans=tl+1;
	else
		ans=tl+2;
	printf("%lld\n",ans);
	}
	return 0;
}
	
