//Abhishek Bansal
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define sout(n) printf("%d\n",n)
#define loop(a,b) for(i=a;i<b;i++)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define SET(a,b) memset(a,b,sizeof(a))
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef long long int lli;
int prime[10000];
int dist[10000];
typedef struct node{
	int val;
	struct node* next;
}node;
node* graph[10000];
node* insert(node* head,int x){
	node* n=(node*)malloc(sizeof(node));
	n->val=x;
	n->next=head;
	return n;
}
int check(int a,int b){
	int a1,a2,a3,a4,b1,b2,b3,b4;
	a1=a/1000;a2=(a%1000)/100;a3=(a%100)/10,a4=a%10;
	b1=b/1000;b2=(b%1000)/100;b3=(b%100)/10,b4=b%10;
	if(a1!=b1&&a2==b2&&a3==b3&&a4==b4)return 1;
	else if(a1==b1&&a2!=b2&&a3==b3&&a4==b4)return 1;
	else if(a1==b1&&a2==b2&&a3!=b3&&a4==b4)return 1;
	else if(a1==b1&&a2==b2&&a3==b3&&a4!=b4)return 1;
	else return 0;
}
int bfs(int s,int d){
	SET(dist,-1);
	dist[s]=0;
	int q[10000],tail=-1,head=0;
	q[++tail]=s;
	while(q[head]!=d){
		int t=q[head++];
		node* tmp=graph[t];
		while(tmp){
			if(dist[tmp->val]==-1){
				q[++tail]=tmp->val;
				dist[tmp->val]=dist[t]+1;
			}
			tmp=tmp->next;
		}
	}
	return dist[d];
}
int main(){
	int i,j,c=0,l;
	int n=10000;
	int a[10000];
	for(i=0;i<n;i++)
		prime[i]=1;
	for(i=2;i<n;i++){
		if(prime[i]==1){
			for(j=i*i;j<n;j+=i){
				prime[j]=0;
			}
		}
	}
	int k=0;
	for(i=1000;i<10000;i++){
		if(prime[i]==1)
			a[k++]=i;
	}
	for(i=0;i<k;i++)graph[a[i]]=NULL;
	for(i=0;i<k;i++){
		for(l=i+1;l<k;l++){
			if(check(a[i],a[l])){
				graph[a[i]]=insert(graph[a[i]],a[l]);
				graph[a[l]]=insert(graph[a[l]],a[i]);
			}
		}
	}
	int t;
	si(t);
	while(t--){
		int s,d;
		si(s);si(d);
		int ans=bfs(s,d);
		sout(ans);
	}
	return 0;
}
