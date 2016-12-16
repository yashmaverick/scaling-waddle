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
#define MAX 1005
typedef long long int lli;
int count=0;
int i;
typedef struct node{
	int val;
	struct node* next;
}node;
node* graph[MAX];
node* graph1[MAX];
int visited[MAX];
node* insert(node* head,int d){
	node* new=(node*)malloc(sizeof(node));
	new->val=d;
	new->next=head;
	return new;
}
void dfs(int u){
	if(!visited[u])visited[u]=1;
	else return;
	node* start=graph[u];
	while(start!=NULL){
		dfs(start->val);
		start=start->next;
	}
	return;
}
void dfs1(int u){
	if(!visited[u]){
		visited[u]=1;
		count++;
	}
	else return;
	node* start=graph1[u];
	while(start!=NULL){
		dfs1(start->val);
		start=start->next;
	}
	return;
}
int complete(int s,int n){
	int flag=1;
	SET(visited,0);
	dfs(s);
	loop(1,n+1){if(visited[i]==0){flag=0;break;}}
	return flag;
}
int main(){
	int t,i;
	si(t);
	while(t--){
	count=0;
	int n,m,x,ans=0;
	int a[MAX];
	si(n);
	loop(0,MAX){
		graph[i]=NULL;
		graph1[i]=NULL;
	}
	loop(1,n+1){
		si(m);
		//a[i]=m;
		while(m--){
			si(x);
			graph[x]=insert(graph[x],i);
			graph1[i]=insert(graph1[i],x);
		}
	}
	/*sout(complete(1,n));
	SET(visited,0);
	dfs1(1);
	sout(count);*/
	for(i=1;i<=n;i++){
		if(complete(i,n)==1){
			//printf("V:%d\n",i);
			SET(visited,0);
			dfs1(i);
			ans=count;
			break;
		}
	}
	sout(ans);
	}
	return 0;
}
