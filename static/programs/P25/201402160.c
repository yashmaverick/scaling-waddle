#include<stdio.h>
#include<stdlib.h>
#define s(n) scanf("%d", &n)
#define p(n) printf("%lld\n", n)
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#define N 100034
#define LL long long int
int mark[N] = {0};
struct edge{
	int first, second;
	int weight;
};
int compare(const void *p1, const void *p2)
{
    const struct edge *elem1 = p1;    
    const struct edge *elem2 = p2;
   if ( elem1->weight < elem2->weight)
      return -1;
   else if (elem1->weight > elem2->weight)
      return 1;
   else
      return 0;
}

struct edge e[N]; int es=0;
int comp[N]={0}, size[N]={0};
int parent[N]={0};

int root(int node){
	if(parent[node]==node)return node;
	return root(parent[node]);
}


int main(){
	int n,m, i, anse=0;
	long long int ans=0;
	s(n); s(m);
	forn(i, m){
		int a, b, c;
		s(a); s(b); s(c);
		struct edge e1;
		e1.first = a;
		e1.second = b;
		e1.weight = c;
		e[es++] = e1;
	}
	forn(i, n)parent[i] = i;
	qsort((void *) &e, es, sizeof(struct edge), compare);
	forn(i, es){
		int frt = root(e[i].first);
		int srt = root(e[i].second);
		if(frt==srt)continue;
		
		//p(ans); printf("\n");
		ans += e[i].weight; anse++;
		//printf("%d %d %d %d %d\n", e[i].first, e[i].second, e[i].weight, anse, ans);
		if(size[srt]>size[frt]){
			int t=frt;
			frt=srt;
			srt=t;
		}
		parent[srt]=frt;
		size[srt] = size[srt] +  size[frt];
		size[frt] = size[srt];
	}
	if(anse!=n-1)printf("-1\n");
	else p(ans);
	return 0;
}

		

