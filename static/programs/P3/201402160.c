//#include<iostream>
#include<stdio.h>
#define s(n) scanf("%d", &n)
#define p(n) printf("%d\n", n)
#define endl printf("\n")
#define N 100013
//using namespace std;
int val[N], rightMax[N], n, i, j, t, ans, mx=0;
int main(){
	s(t);
	while(t--){
		s(n);
		for(i=0; i<n; i++)s(val[i]);
		ans = 0;
		mx = val[n-1];
		for(i=n-1; i>=0; i--){
					//cout<<mx<<" "<<i<<endl;
					//cout<<"hello";
			mx = mx > val[i+1] ? mx: val[i+1];
			ans = ans > mx - val[i] ? ans: mx-val[i];
	
		}
		p(ans);
	}
	/*rightMax[n-1] = 0;
	rightMax[n-2] = val[n-1];
	for(i=n-3; i>=0; i--)rightMax[i] = max(rightMax[i+2], val[i+1]);
	for(i=0; i<n; i++)
	cout<<val[i]<<" "; cout<<endl;
	for(i=0; i<n; i++)
	cout<<rightMax[i]<<" "; cout<<endl;
	if(rightMax[i] - val[i] > ans)ans = rightMax[i] - val[i];
	cout<<ans<<endl;*/
	return 0;
}
