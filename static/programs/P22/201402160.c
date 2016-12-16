#include<stdio.h>
#include<stdlib.h>
#define N 1000123
#define mod 1000000007
#define s(n) scanf("%lld", &n)
#define p(n) printf("%lld ", n)
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#define LL long long int
int as, b, c;
int F(LL d, LL e){
	LL ans;
	ans = (as*d + b*e + c)%mod;
	//printf("%lld %lld %lld %lld %lld %lld\n", as, b, c, d, e, ans);
	return (int)ans;
}
void swap(int * a, int * b){
	LL t = *a;
	*a = *b;
	*b = t;
}
int min[N], max[N], smin, smax;
void admin(LL data){
	++smin;
	int i, fs = smin;
	min[fs] = data;
	while(fs>1 && min[fs]<min[fs/2])swap(&min[fs], &min[fs/2]), fs/=2;
}
void admax(LL data){
	++smax;
	int i, fs = smax;
	max[fs] = data;
	while(fs>1 && max[fs]>max[fs/2])swap(&max[fs], &max[fs/2]), fs/=2;
}
LL popmin(){
	int i, fs=1, ctr, ret = min[1];
	swap(&min[1], &min[smin]);
	smin--;
	while(fs*2<=smin){
		if(fs*2+1>smin)ctr = fs*2;
		else ctr=(min[fs*2]<min[fs*2+1]?fs*2:fs*2+1);
		if(min[fs] < min[ctr])break;
		swap(&min[fs], &min[ctr]);
		fs = ctr;
	}
	return ret;
}
LL popmax(){
	LL i, fs=1, ctr, ret = max[1];
	swap(&max[1], &max[smax]);
	smax--;
	while(fs*2<=smax){
		if(fs*2+1>smax)ctr = fs*2;
		else ctr=(max[fs*2]>max[fs*2+1]?fs*2:fs*2+1);
		if(max[fs]>max[ctr])break;
		swap(&max[fs], &max[ctr]);
		fs = ctr;
	}
	//printf("Popping %lld\n", ret);
	return ret;
}
void showmin(){
	int i;
	for1(i, smin)p(min[i]);
	printf("\n");
}
void showmax(){
	int i;
	for1(i, smax)p(max[i]);
	printf("\n");
}
int main(){
	LL t, i, sum=1, n, a=1, med;
	s(t);
	while(t--){
		s(as); s(b); s(c); s(n);
		sum = 1; a = 1; smax=smin=0;
		for1(i, n-1){
			//LL a, med;
			//s(a);
			//sum+=a; sum%=mod;
			//printf("%lld\n", i);
			if(smax==0 && smin==0){admax(a); med=a; a=F(med, 2); sum+=a;
			//printf("%lld %lld\n", a, med);
			continue; }
			if(a>med)admin(a); else admax(a);
			if(smax-smin>1)admin(popmax());
			else if(smin-smax>1)admax(popmin());
			if(smax>=smin)med=max[1];
			else med=min[1];
			sum+=F(med, i+1); 
			a=F(med, i+1);
			//showmin();
			//showmax(); printf("\n");
			//printf("%lld %lld\n", a, med);
			
		}
		printf("%lld\n", sum);
	}
	return 0;
}
