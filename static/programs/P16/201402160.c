#include<stdio.h>
#define s(n) scanf("%lld", &n)
#define p(n) printf("%lld\n", n)
#define LL long long int

LL po[42], t, q;
LL bs(LL start, LL end){

	if(start>=end)return start;
	LL mid = (start+end)/2;
	//	cout<<[mid]<<" ";
	if(po[mid]<q && po[mid+1]>q)return mid;
	if(po[mid]==q)return mid;
	if(po[mid]>q)return bs(start, mid-1);
	return bs(mid+1, end);
}
int main(){
	LL i, t, temp;
	po[0]=1;
	for(i=1; i<42; i++)po[i]=po[i-1]*2;
	s(t);
	while(t--){
		s(q);
		if(q==1){p(0); continue;}
		temp=bs(0, 41);
		if(po[temp]+po[temp-1] <= q)p(2*temp);
		else p(2*temp-1);
	}
	return 0;
}
	
