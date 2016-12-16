#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 1000009
#define rep(i,n) for(i=1;i<=n;i++)
void in(int *address){
	scanf("%d",address);
}
void out(int *pointer){
	printf("%d\n",*pointer);
}
typedef struct node{
	int val;
	struct node *next;
}node;
node *a[MAX];
bool vis[MAX];
int max=0,maxnode=1;
node *insert(node *head,int i){
	node *p;
	p=(node *)malloc(sizeof(node));
	p->val=i;
	p->next=head;
	return p;
}
void dfs(int i,int depth){
	if(depth>max){
		max=depth;
		maxnode=i;
	}
	vis[i]=1;
	node *tmp=a[i];
	while(tmp!=NULL){
		if(!vis[tmp->val])
		{
			dfs(tmp->val,depth+1);
		}
		tmp=tmp->next;
	}
}
int main(){
	int t,z;
	in(&t);
	rep(z,t){
		int n,i,x,y,m,j,ans=0;
		in(&n);
		rep(i,n) a[i]=NULL;
		rep(i,n-1){
			in(&x);
			in(&y);
			a[x]=insert(a[x],y);
			a[y]=insert(a[y],x);
		}
		rep(i,n)vis[i]=0;
		max=0;
		maxnode=1;
		dfs(1,1);
		rep(i,n)vis[i]=0;
		j=maxnode;
		max=0;
		dfs(j,1);
		out(&max);
	}
	return 0;
}
