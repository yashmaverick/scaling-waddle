#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define rep(i,n,s) for(i=s;i<=n;i++)
void in(int *address){
	scanf("%d",address);
}
void out(int *pointer){
	printf("%d\n",*pointer);
}
typedef struct node{
	int val;
	struct node* next;
}node;
node *insert(node *head,int val){
	node *p; 
	p=(node*)malloc(sizeof(node));
	p->val=val;
	p->next=head;
	return p;
}
node *fr[1001],*ba[1001];
int count[1001],a[1001],ans;
bool vis[1001];
void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b   = *a;
	*a   = temp;   
}
void dfsba(int src){
	vis[src]=1;
	node *tmp;
	tmp=ba[src];
	while(tmp!=NULL){
		if(!vis[tmp->val]) dfsba(tmp->val);
		tmp=tmp->next;
	}
}
void dfsfr(int src){
	vis[src]=1;
	ans++;
	node *tmp;
	tmp=fr[src];
	while(tmp!=NULL){
		if(!vis[tmp->val]) {
			dfsfr(tmp->val);
		}
		tmp=tmp->next;
	}
}
int main()
{
	int t,z;
	in(&t);
	rep(z,t,1){
		node *tmp;
		bool state=0,state1=0;
		int n,i,j,m,y,temp,root;
		in(&n);
		rep(i,n,1){
			a[i]=i;
			count[i]=0;
			ba[i]=fr[i]=NULL;
		}
		rep(i,n,1){
			in(&m);
			count[i]=m;
			rep(j,m,1){
				in(&y);
				ba[y]=insert(ba[y],i);
				fr[i]=insert(fr[i],y);
			}
		}
		rep(i,n,2) 
			rep(j,n-1,1)
				if (count[j] > count[j + 1]) swap(&a[j],&a[j+1]);
		rep(i,n,1){
			state=0;
			rep(j,n,1)vis[j]=0;
			dfsba(a[i]);
			rep(j,n,1)if(!vis[j])state=1;
			if(!state){
				state1=1;
				root=a[i];
				break;
			}
		}
		ans=0;
		rep(j,n,1) vis[j]=0;
		if(state1) 
			dfsfr(root);
		out(&ans);
	}
	return 0;
}
