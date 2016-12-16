#include<stdio.h>
#include<stdlib.h>

struct edge{
	int a,b,wt;
};

void swap(int,int);
void heapify(int);
char notsame(int,int);
int getp(int);
void join(int,int);
struct edge *edgs;
int *parent,arlen;
int main(){
	int n,m,i,j,k,sets;
	long long ans;
	scanf("%d %d",&n,&m);
	parent=malloc(sizeof(int)*n);
	edgs=(struct edge *)malloc(sizeof(struct edge)*m);
	sets=n;
	for(i=0;i<n;i++){
		parent[i]=-1;
	}
	for(i=0;i<m;i++){
		scanf("%d %d %d",&edgs[i].a,&edgs[i].b,&edgs[i].wt);
		edgs[i].a--;edgs[i].b--;
	}
	edgs--;
	arlen=m;
	for(i=m>>1;i>0;i--){
		heapify(i);
	}
	while(arlen>1){
		swap(1,arlen);
		arlen--;
		heapify(1);
	}
	ans=0;
	edgs++;
	for(i=0;i<m&&sets>1;i++){
		if(notsame(edgs[i].a,edgs[i].b)){
			ans+=edgs[i].wt;
			join(edgs[i].a,edgs[i].b);
			sets--;
		}
	}
	if(sets>1){
		printf("-1\n");
	}
	else{
		printf("%lld\n",ans);
	}
	return 0;
}

void swap(int a,int b){
	struct edge temp;
	temp=edgs[a];
	edgs[a]=edgs[b];
	edgs[b]=temp;
}

void heapify(int ind){
	int i;
	while(ind<<1<arlen){
		i=ind<<1;
		if(edgs[i].wt<edgs[i+1].wt){
			i++;
		}
		if(edgs[i].wt>edgs[ind].wt){
			swap(i,ind);
			ind=i;
		}
		else{
			break;
		}
	}
	if(ind<<1==arlen&&edgs[ind<<1].wt>edgs[ind].wt){
		swap(ind<<1,ind);
	}
}

char notsame(int a,int b){
	int p1,p2;
	p1=getp(a);
	p2=getp(b);
	if(p1==p2){
		return 0;
	}
	else{
		return 1;
	}
}

int getp(int x){
	int i,j;
	i=x;
	while(parent[i]>=0){
		i=parent[i];
	}
	while(parent[x]>=0){
		j=parent[x];
		parent[x]=i;
		x=j;
	}
	return i;
}

void join(int a,int b){
	a=getp(a);b=getp(b);
	if(parent[a]>parent[b]){
		parent[a]=b;
	}
	else{
		if(parent[a]==parent[b]){
			parent[a]--;
		}
		parent[b]=a;
	}
}
