#include<stdio.h>
int main(){
	int n,ans;
	long long l,r,q;
	scanf("%d",&n);
	while(n--){
		scanf("%lld",&q);
		ans=0;
		r=1;
		if(((r<<1)+1)<=q){
			r<<=1;
			r++;
			ans++;
			while((r<<1)<=q){
				r<<=1;
				ans++;
			}
		}
		l=1;
		while((l<<1)<=q){
			l<<=1;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
