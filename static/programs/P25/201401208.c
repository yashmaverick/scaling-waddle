#include<stdio.h>
#include<stdlib.h>
typedef long long int LL;
int parent[1000005],rank[1000005],v[1000005];
void union_of(int x,int y);
int find(int x);
int is_same_set(int x,int y);

struct Edge{
	int beg;
	int end;
	LL wt;
}*head[1000005];

typedef struct Edge Edge;
Edge *head[1000005],*tmp[1000005];
void sort(int left,int right);
void merge(int left,int mid,int right);
int main(){
	int n,m,q,x,y,i,ch,ans,ct,c,fl,edge;
	LL s,w;
	s=0;
	fl=0;
	scanf("%d %d",&n,&m);

	for(i=0;i<m;i++){
		scanf("%d %d %lld",&x,&y,&w);
		head[i]=malloc(sizeof(Edge));
		head[i]->beg=x;
		head[i]->end=y;
		head[i]->wt=w;
		v[x]++;
		v[y]++;
	}
	if( m < n-1)
		fl=1;
	for(i=1;i<=n;i++){
		if(v[i]==0){
			fl=1;
			break;
		}
	}
	for(i=1;i<=n;i++){
		parent[i]=i;
		rank[i]=0;
	}
	if(fl==0){
		sort(0,m-1);
		i=0;
		edge=0;
		while(edge<n-1){
			x=head[i]->beg;
			y=head[i]->end;
			w=head[i]->wt;
			if((find(x))!=(find(y))){
				union_of(x,y);
				s+=w;
				edge++;
			}
			i++;
			if(i > m-1){
				fl=1;
				break;
			}
		}
	}
	if(fl==1)
		printf("-1\n");
	if(fl==0)
		printf("%lld\n",s);
	return 0;
}
void union_of(int x,int y){
	int px,py;
	px=find(x);
	py=find(y);
	if(px!=py){
		if(rank[px] < rank[py])
			parent[px]=py;
		else if(rank[px] > rank[py])
			parent[py]=px;
		else{
			parent[py]=px;
			rank[px]++;
		}
	}
}

int find(int x){
	if(parent[x]!=x)
		parent[x]=find(parent[x]);
	return parent[x];
}

int is_same_set(int x,int y){
	int fl,px,py;
	px=find(x);
	py=find(y);
	if(px==py)
		fl=1;
	else
		fl=0;
	return fl;
}

void sort(int left,int right){
	int mid;
	if(left>=right)
		return;

	else{
		mid=(left+right)/2;
		sort(left,mid);
		sort(mid+1,right);
		merge(left,mid,right);
	}
}

void merge(int left,int mid,int right){
	int i,j,k,m;
	j=left;
	m=mid+1;
	for(i=left;j<=mid&&m<=right;i++){
		if((head[j]->wt)<(head[m]->wt)){
			tmp[i]=head[j];
			j++;
		}
		else{
			tmp[i]=head[m];
			m++;
		}
	}

	if(j>mid){
		for(k=m;k<=right;k++){
			tmp[i]=head[k];
			i++;
		}
	}

	else{
		for(k=j;k<=mid;k++){
			tmp[i]=head[k];
			i++;
		}
	}

	for(k=left;k<=right;k++)
		head[k]=tmp[k];

}

