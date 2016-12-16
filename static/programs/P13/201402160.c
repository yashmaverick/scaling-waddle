#include<stdio.h>
#define N 100023
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#define cin(n) scanf("%d", &n)
#define cout(a,b) printf("%d %d\n", a, b)
int mdepth=0, temp, rt, a[N], l[N], r[N], dp[N], n, ans;
//stack<int> ht;
int ht[N], sz=0;
int dfs(int vertex, int val){
	dp[vertex]=val;
	if(l[vertex])dfs(l[vertex], val+1);
	if(r[vertex])dfs(r[vertex], val+1);
	return 1;
}
int first(int vertex, int val){
	//printf("%d ", vertex);
	if(dp[vertex]==val)return vertex;
	int ans=0;
	if(l[vertex]!=0)ans=first(l[vertex], val);
	if(ans==0)if(r[vertex])ans=first(r[vertex], val);
	if(!l[vertex] && !r[vertex])return 0;
	return ans;
}
int main(){
	int i, t;
	cin(t);
	while(t--){
		cin(n);
		if(n==0)return 0;
		forn(i, n*2)l[i]=r[i]=dp[i]=0; mdepth=0;
		forn(i, n)cin(a[i]);
		rt=a[n-1];
		sz=0;
		ht[sz++]=(a[n-1]);
		for(i=n-2; i>=0; i--){
			//cout<<i<<" "<<ht.top()<<endl;
			if(sz==0)break;
			if(a[i] > ht[sz-1])r[ht[sz-1]]=a[i];
			else {
				while(sz>0 && a[i] < ht[sz-1]){
					temp=ht[sz-1];
					sz--;
				}
				l[temp]=a[i];
				
			}
			ht[sz++]=a[i];
		}
		dfs(rt, 0);
		
		for1(i, n)if(dp[i]>mdepth)mdepth=dp[i];
		cout(first(rt, mdepth), mdepth);
	}
	return 0;
}
