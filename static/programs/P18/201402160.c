#include<stdio.h>
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#define cin(n) scanf("%d", &n)
#define cout(n) printf("%d\n", n)
#define N 2003
int t, n, can_beat[N][N], cannot_beat[N][N], size[N], sizec[N], mark[N], ans=0;
int dfs(int vertex){
	int i;
	//printf("At vertex: %d\n", vertex);
	if(mark[vertex])return 0;
	mark[vertex] = 1;
	forn(i, size[vertex])if(!mark[can_beat[vertex][i]])dfs(can_beat[vertex][i]);
}
int reverse_dfs(int vertex){
	//cout<<"At vertex: "<<vertex<<endl;
	int i;
	if(mark[vertex])return 0;
	mark[vertex] = 1;
	forn(i, sizec[vertex])if(!mark[cannot_beat[vertex][i]])reverse_dfs(cannot_beat[vertex][i]);
}
int main(){
	cin(t);
	while(t--){
		ans = 0;
		cin(n); int m, c, i, j, valid=0;
				for1(i, n)size[i] = sizec[i] = 0;
		for1(i, n){
			cin(m);
			forn(j, m)cin(c), can_beat[c][size[c]++]=i, cannot_beat[i][sizec[i]++]=c;
 		}

		for1(i, n)mark[i] = 0;
		for1(i, n){
			valid = i;
			//cout(i);
			for1(j, n)mark[j] = 0;
			dfs(i);
			for1(j, n)if(!mark[j]){valid = 0; break;}
			if(valid!=0)break;
		}	
		//cout(valid);
		for1(i, n)mark[i] = 0;
		reverse_dfs(valid);
		for1(j, n)ans += mark[j];
		cout(ans);
	}
	return 0;
}
 
