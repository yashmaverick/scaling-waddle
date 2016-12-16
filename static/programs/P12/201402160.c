#include<stdio.h>
#define N 600024
#define s(n) scanf("%lld", &n)
#define p(n) printf("%lld\n", n)
#define ul long long

struct element{
	ul height;
	ul c;
}a[N], st[N];
ul sz=0;

int main(){
	ul n, i, j, ans=0;
	while(1){
		s(n);
		if(n==0)return 0;
		ans=0;
		for(i=0; i<n; i++)s(a[i].height), a[i].c=1;
		st[0]=a[0]; sz=1;
		
		for(i=1; i<n; i++){
			while(sz>0){
				if(a[i].height>st[sz-1].height)ans += st[sz-1].c, sz--;
				else  if(a[i].height==st[sz-1].height){
					ans += st[sz-1].c + (sz>1);
					a[i].c = st[sz-1].c + 1;
					sz--;
					break;
				}
				else{
					ans += (sz>0);
					break;
				}
			}
			st[sz++]=a[i];
		}
		p(n*(n-1)/2 - ans);
	}
	
	return 0;
}
