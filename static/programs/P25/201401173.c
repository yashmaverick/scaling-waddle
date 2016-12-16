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
typedef struct edge{
	int u,v;
	lli w;
}edge;
edge a[1000005];
typedef struct node{
	int val;
	struct node* next;
}node;
node* component[100005];
int c[100005],s[100005];
node* insert(node* head,int x){
	node* n=(node*)malloc(sizeof(node));
	n->val=x;
	n->next=head;
	return n;
}
int cmp(const void* a,const void* b){
	return (((edge*)a)->w - ((edge*)b)->w);
}
node* merge(node* l1,node* l2,int c1){
	node* to=l1;
	node* from=l2;
	while(from){
		to=insert(to,from->val);
		c[from->val]=c1;
		from=from->next;
	}
	return to;
}
int main(){
	int n,m,u,i,v;
	lli w,z;
	si(n);
	si(m);
	int x,y,t,count=0;
	lli sum=0;
	loop(1,n+1)c[i]=i;
	loop(1,n+1)component[i]=NULL;
	loop(1,n+1)s[i]=1;
	loop(1,n+1)component[i]=insert(component[i],i);
	loop(0,m){
		si(u);
		si(v);
		sll(w);
		a[i].u=u;
		a[i].v=v;
		a[i].w=w;
	}
	qsort(a,m,sizeof(edge),cmp);
	loop(0,m){
		x=a[i].u;
		y=a[i].v;
		z=a[i].w;
		if(c[x]!=c[y]){
			sum+=z;
			count++;
			if(s[c[x]]<s[c[y]])
				component[c[y]]=merge(component[c[y]],component[c[x]],c[y]);
			else
				component[c[x]]=merge(component[c[x]],component[c[y]],c[x]);
			t=s[x]+s[y];
			s[x]=s[y]=t;
		}
	}
	if(count!=n-1)
		sum=-1;
	printf("%lld\n",sum);
	return 0;
}
