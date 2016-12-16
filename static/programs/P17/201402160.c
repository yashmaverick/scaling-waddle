#include<stdio.h>
#define cin(n) scanf("%d", &n)
#define cout(n) printf("%d\n", n)
#define N 100034
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)

int pre[N], in[N], ind[N], prind[N], n, l, r; //x<y
int find_ancestor(int x, int y, int node){
	//cout<<x<<" "<<y<<" "<<node<<endl;
	if(ind[x]<=ind[node] && ind[y]>=ind[node])return node;
	if(ind[x]>=ind[node] && ind[y]<=ind[node])return node;
	if(ind[x]>=ind[node])return find_ancestor(x, y, pre[ind[node]+1]);
	return find_ancestor(x, y, pre[prind[node]+1]);
}
	
int main(){
	cin(n);
	int i;
	forn(i, n)cin(pre[i]), prind[pre[i]]=i;
	forn(i, n)cin(in[i]), ind[in[i]] = i;
	int a, b, t, j, tes;
	cin(tes);
	while(tes--){
		cin(a); cin(b); 
		if(ind[a]>ind[b]){
			t=a;
			a=b;
			b=t;
		}	 	
		t=prind[in[ind[a]]];
		for(i=ind[a]; i<=ind[b]; i++){
			if(prind[in[i]]<t)t=prind[in[i]];
			//printf("%d %d %d\n", in[i], prind[in[i]], t);
			//cout(prind[in[i]]);
		}
		cout(pre[t]);
	}

	return 0;
}

