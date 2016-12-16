#include<stdio.h>
#include<stdlib.h>
#define cin(n) scanf("%d", &n)
#define cout(n) printf("%d\n", n)
#define N 1000023
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
int height[N], *edge[N], size[N], ae[N], be[N];
int dfs(int vertex, int h){
	//printf("%d %d\n", vertex, size[vertex]);
	if(height[vertex]!=-1)return height[vertex];
	height[vertex] = h;
	int i;
	forn(i, size[vertex]){
		//printf("%d %d %d\n", i, vertex, edge[vertex][i]);
		if(height[edge[vertex][i]]==-1)dfs(edge[vertex][i], h+1);
	}
	return 1;
}
int main(){
	int t, n, j;
	cin(t);
	forn(j, N)size[j] = 0;
	while(t--){
		int i, n, a, b, mdepth = 1;
		cin(n);
		
		for1(i, n)size[i] = 0, height[i] = -1;
		
		forn(i, n-1){
			cin(ae[i]); cin(be[i]);
			size[ae[i]]++; size[be[i]]++;
		}
		for1(i, n)if(size[i])edge[i] = malloc(sizeof(int) * size[i]);
		for1(i, n)size[i] = 0;
		forn(i, n-1)edge[ae[i]][size[ae[i]]++] = be[i], edge[be[i]][size[be[i]]++] = ae[i];
		dfs(1, 1);
		//for1(i, n)printf("%d ", height[i]); printf("\n");
		for1(i, n)if(height[i] > height[mdepth])mdepth = i;
		for1(i, n)height[i] = -1;
		dfs(mdepth, 1);
		//for1(i, n)printf("%d ", height[i]); printf("\n");
		for1(i, n)if(height[i] > height[mdepth])mdepth = i;
		cout(height[mdepth]);
		for1(i, n)if(size[i])free(edge[i]);
	}
	return 0;
}
		
