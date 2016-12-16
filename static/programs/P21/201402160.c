#include<stdio.h>
#include<stdlib.h>
#define s(n) scanf("%d", &n)
#define p(n) printf("%lld\n", n)
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#define LL long long int
#define N 1000123
#define INF 123123123123
int pos[N], heap[N], sz=0;
LL  sp[N]={INF}; //pos[i] = position of i in heap, heap[i] = vertex in ith position of heap
int *near[N], *wt[N], size[N], u[N], v[N], w[N];
void swap(int * a, int * b){
	int t=*a;
	*a=*b;
	*b=t;
}

void adh(int vertex){
	++sz;
	int fs = sz;
	heap[fs] = vertex;
	while(fs>1 && sp[heap[fs]] < sp[heap[fs/2]])pos[heap[fs]] = fs/2, pos[heap[fs/2]] = fs, swap(&heap[fs], &heap[fs/2]), fs/=2;
	pos[vertex] = fs;
}
void up_heapify(int vertex){
	int fs = pos[vertex];
	while(fs>1 && sp[heap[fs]] < sp[heap[fs/2]])pos[heap[fs]] = fs/2, pos[heap[fs/2]] = fs, swap(&heap[fs], &heap[fs/2]), fs/=2;
	pos[vertex] = fs;
}
void down_heapify(int vertex){
	int fs;
	//swap(heap[1], heap[sz]);
	//sz--;
	fs = pos[vertex];
	while(fs*2<=sz){
		int ctr;
		if(sp[heap[fs*2]]<sp[heap[fs*2+1]])ctr = fs*2;
		else if(fs*2+1<=sz)ctr=fs*2+1;
		else ctr=fs*2;
		if(sp[heap[fs]]<sp[heap[ctr]])break;
		pos[heap[fs]] = ctr; pos[heap[ctr]] = fs;
		swap(&heap[fs], &heap[ctr]);
		fs = ctr;
	}
	//pos[vertex] = fs;
}
int pop(int vertex){
	int t, fs, ret=heap[1];
	swap(&heap[1], &heap[sz]);
	sz--;
	fs = 1;
	while(fs*2<=sz){
		int ctr;
		if(sp[heap[fs*2]]<sp[heap[fs*2+1]])ctr = fs*2;
		else if(fs*2+1<=sz)ctr=fs*2+1;
		else ctr = fs*2;
		if(sp[heap[fs]]<sp[heap[ctr]])break;
		pos[heap[fs]] = ctr; pos[heap[ctr]] = fs;
		swap(&heap[fs], &heap[ctr]);
		fs = ctr;
	}
	pos[vertex]=-1;
	return ret;
}
void show(){
	int i;
	for1(i, sz)printf("%d ", heap[i]); 
	printf("\n");
}
void update(int vertex, LL newval){
	if(sp[vertex] > newval)sp[vertex] = newval, up_heapify(vertex);
	else sp[vertex] = newval, down_heapify(vertex);
}
void dijkstra(){
	if(sz==0)return;
	int curr = heap[1];
	//printf("%d ", curr); //(curr);
	int i;
	forn(i, size[curr])if(sp[curr] + wt[curr][i] < sp[near[curr][i]])
	update(near[curr][i], (sp[curr] + wt[curr][i]));
	pop(curr);
	dijkstra();
}
int main(){
	int so, t, i, n, m;
	s(n); s(m);
	forn(i, m){
		s(u[i]); s(v[i]); s(w[i]);
		size[u[i]]++;
	}
	for1(i, n)if(size[i]>0)near[i] = malloc(sizeof(int)*size[i]), wt[i] = malloc(sizeof(int)*size[i]);
	for1(i, n)size[i] = 0;
	forn(i, m)near[u[i]][size[u[i]]] = v[i], wt[u[i]][size[u[i]]++] = w[i];
	s(so); s(t);
	for1(i, n)sp[i] = INF, adh(i);
	update(so, 0);
	//show();
	dijkstra();
	if(sp[t]==INF)printf("NO\n");
	else p(sp[t]);	
	return 0;
}
