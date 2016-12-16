#include<stdio.h>
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#define N 100034
#define cin(n) scanf("%lld", &n)
#define cout(n) printf("%lld\n", n)
#define LL long long int
LL temp, h[N], n, l[N], r[N], i, ans=0;
//stack<int> le, ri;
LL le[N], ri[N], sz;

int main(){
	while(1){
		cin(n);
		if(n==0)break;
		forn(i, n)cin(h[i]);
		forn(i, n)l[i]=r[i]=0;
		ans=0;
		sz=0;
		le[sz++]=0; l[0]=-1;
		for1(i, n-1){
			while(sz>0 && le[sz-1]!=-1 && h[i]<=h[le[sz-1]])sz--;
			if(sz>0)
			l[i]=le[sz-1];
			else l[i]=-1;
			le[sz++]=i;
		}
		//forn(i, n)cout<<i-l[i]<<" "; cout<<endl;
		sz=0;
		ri[sz++]=(n-1); r[n-1]=n;
		for(i=n-2; i>=0; i--){
			while(sz>0 && ri[sz-1]!=-1 && h[i]<=h[ri[sz-1]])sz--;
			if(sz>0)
			r[i]=ri[sz-1];
			else r[i]=n;
			ri[sz++]=i;
		}
		//forn(i, n)cout<<r[i]-i<<" "; cout<<endl;
		//forn(i, n)printf("%lld ", i-l[i]); printf("\n");
		//forn(i, n)printf("%lld ", r[i]-i); printf("\n");
		forn(i, n)if(h[i]*(r[i]-l[i]-1)>ans)ans=h[i]*(r[i]-l[i]-1);
		cout(ans);
	}
	return 0;
}
