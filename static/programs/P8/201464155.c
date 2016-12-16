#include<stdio.h>

typedef long long ll;

const int md = 1000000007;
int u,d,m,n;
int a[50];

int f(int a,int b,int c){
	int ret = 1;
	for(;b;b>>=1){
		if(b%2 == 1){ret = (ret*a)%c;}
		a = (a*a)%c;
	}
	return ret;
}

int g(int x){
	if(x == 0) return 1+(u/n);
	int xx = u/n;
	if(u%n > 0 && u%n >= x){xx+=1;}
	return xx;
}

int main(){
	int t,i,j,k;
	scanf("%d",&t);
	for(;t;t--){
		scanf("%d %d %d %d",&u,&d,&m,&n);
		a[0] = (d==0)?1:0;
		a[1] = 1;
		ll ans = 0;
		for(i=2;i<n;i++)a[i]=f(i,d,n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					if((a[i]+a[j]+a[k])%n == m){
						ll tmp = g(i);
						tmp = (tmp*g(j))%md;
						tmp = (tmp*g(k))%md;
						ans = (ans+tmp)%md;
					}
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
