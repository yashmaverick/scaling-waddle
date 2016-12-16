#include<stdio.h>
#include<stdlib.h>

struct edge{
	int val,parent;
	long long w;
};

struct list{
	struct edge val;
	struct list *next;
};

void swap(int,int);
void heapify(int);
void rev_heapify(int);
void insert(struct edge);
void putin(int,int,int);
void allow(int);
struct edge htop();
struct list **lst;
struct edge *har;
int hlen,*parent;
long long *dist;
int main(){
	struct edge nowe;
	int n,m,i,j,k,t,src,dest;
	long long l;
	har=(struct edge *)malloc(sizeof(struct edge)*500005);
	lst=(struct list **)malloc(sizeof(struct list *)*100005);
	dist=(long long *)malloc(sizeof(long long)*100005);
	parent=malloc(sizeof(int)*100005);
	t=1;
	while(t--){
		scanf("%d %d",&n,&m);
		hlen=0;
		for(i=0;i<n;i++){
			parent[i]=-1;
			dist[i]=-1;
			lst[i]=NULL;
		}
		for(i=0;i<m;i++){
			scanf("%d %d %lld",&j,&k,&l);
			j--;k--;
			putin(j,k,l);
		}
		scanf("%d %d",&src,&dest);
		src--;
		dest--;
		dist[src]=0;allow(src);
		while(dist[dest]==-1&&hlen>0){
			nowe=htop();
			if(dist[nowe.val]!=-1){
				continue;
			}
			dist[nowe.val]=nowe.w;
			parent[nowe.val]=nowe.parent;
			allow(nowe.val);
		}
		if(dist[dest]==-1){
			printf("NO\n");
		}
		else{
			printf("%lld\n",dist[dest]);
		}
	}
	return 0;
}

void swap(int a,int b){
	struct edge c;
	c=har[a];
	har[a]=har[b];
	har[b]=c;
}

void heapify(int ind){
	int i;
	while(ind<<1<hlen){
		i=ind<<1;
		if(har[i].w>har[i+1].w){
			i++;
		}
		if(har[i].w<har[ind].w){
			swap(ind,i);
			ind=i;
		}
		else{
			break;
		}
	}
	if(ind<<1==hlen&&har[ind<<1].w<har[ind].w){
		swap(ind,ind<<1);
	}
}

void rev_heapify(int ind){
	while(ind>1){
		if(har[ind].w<har[ind>>1].w){
			swap(ind,ind>>1);
			ind>>=1;
		}
		else{
			break;
		}
	}
}

void insert(struct edge ed){
	har[++hlen]=ed;
	rev_heapify(hlen);
}

struct edge htop(){
	struct edge toret;
	toret=har[1];
	har[1]=har[hlen--];
	heapify(1);
	return toret;
}

void putin(int in,int val,int w){
	struct list *tmp;
	tmp=lst[in];
	lst[in]=(struct list *)malloc(sizeof(struct list));
	lst[in]->val.val=val;
	lst[in]->val.parent=in;
	lst[in]->val.w=w;
	lst[in]->next=tmp;
}

void allow(int ind){
	while(lst[ind]!=NULL){
		if(dist[lst[ind]->val.val]==-1){
			lst[ind]->val.w+=dist[ind];
			insert(lst[ind]->val);
		}
		lst[ind]=lst[ind]->next;
	}
}

