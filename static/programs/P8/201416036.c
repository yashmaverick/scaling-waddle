#include <stdio.h>
#define ull unsigned long long
int upper,d,m,n;
ull mod (ull a)
{
	return a%1000000007;
}
ull min(ull a, ull b)
{
	if (a < b) {
		return a;
	}
	return b;
}
int fun(int x, int p)
{
	if (p == 0) {
		return 1%n;
	}
	int ans = fun(x,p/2);
	ans = (ans*ans)%n;
	if(p%2) {
		ans = (ans*x)%n;
	}
	return ans;
}
ull solve ()
{
	int x1,x2,x3;
	ull ans = 0;
	for (x1 = 0; x1 < n && x1 <= upper; x1++) {
		for ( x2 = 0; x2 < n && x2 <= upper; x2++ ) {
			for ( x3 = 0; x3 < n && x3 <= upper; x3++ ) {
				if (m == (fun(x1,d)+fun(x2,d)+fun(x3,d))%n) {
					ull a,b,c;
					a = (upper-x1)/n+1;
					b = (upper-x2)/n+1;
					c = (upper-x3)/n+1;
					ans = (ans+mod(mod(a*b)*c))%1000000007;

				}
			}
		}
	}
	return ans;

}
int main ()
{
	int t;
	int i,j;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d%d%d",&upper,&d,&m,&n);

		ull ans = solve();
		printf("%llu\n",ans);
	}
	return 0;
}
