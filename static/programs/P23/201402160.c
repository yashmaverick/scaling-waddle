#include<stdio.h>
#include<stdlib.h>
#define N 100123
#define s(n) scanf("%d", &n)
#define p(n) printf(" %d", n)
#define endl printf("\n");
#define pfirst(n) printf("%d", n)
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<n; i++)
int st[N], sz=0, *out[N], size[N]={0}, a[N], vis[N] = {0}, b[N], n;
int dfs(int vertex){
	int i;
	//printf("%d %d\n", vertex, size[vertex]);
	if(vis[vertex])return 1;
	vis[vertex] = 1;
	forn(i, size[vertex])dfs(out[vertex][i]);
	st[sz++] = vertex;
	return 1;
}
int main(){
	int m, i;
	s(n); s(m);
	forn(i, m){
		s(a[i]); s(b[i]);
		size[a[i]]++;
	}
	for1(i, N)if(size[i]>0)out[i] = malloc(size[i]*sizeof(int)), size[i]=0;
	forn(i, m)out[a[i]][size[a[i]]++] = b[i];
	for(i=n; i>=1; i--)dfs(i);
	//fo(i, sz)p(st[i]);
	pfirst(st[sz-1]);
	for(i=sz-2; i>=0; i--)p(st[i]);
	endl;
	return 0;
}
