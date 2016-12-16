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
#include<assert.h>
typedef long long int lli;
typedef struct node node;
struct node{
	node* a[10];
	int flag;
	int pass;
};
node* init(node* n){
	int i;
	loop(0,10)
		n->a[i]=NULL;
	n->flag=0;
	n->pass=0;
	return n;
}
node* insert(node* n,char s[],int i,int l){
	if(i>=l)
		return n;
	if(n->a[s[i]-'0']==NULL){
		n->a[s[i]-'0']=(node*)malloc(sizeof(node));
		n->pass++;
		n->a[s[i]-'0']=init(n->a[s[i]-'0']);
	}
		if(i==l-1){
			(n->a[s[i]-'0'])->flag++;
		}
		n->a[s[i]-'0']=insert(n->a[s[i]-'0'],s,i+1,l);
		return n;
	}
void print(node* root){
	int i;
	if(root->flag>0){
		printf("\n");
		return;
	}
	loop(0,10){
		if(root->a[i]!=NULL){
			printf("%d",i);
			print(root->a[i]);
		}
	}
	return;
}
int look(node* root,char s[]){
	int l=strlen(s);
	int i,flag=0;
	node* t=root;
	loop(0,l){
		t=t->a[s[i]-'0'];
	}
	if(t->flag>1||t->pass>0)
		flag=1;
	return flag;
}
int main(){
	int t;
	si(t);
	while(t--){
	node* root=(node*)malloc(sizeof(node));
	root=init(root);
	char s[100001][11];
	int n,l,i,find=1;
	si(n);
	loop(0,n){
		scanf("%s",s[i]);
		l=strlen(s[i]);
		root=insert(root,s[i],0,l);
	}
	//sout(root->pass);
	loop(0,n){
		if(look(root,s[i])==1){
			find=0;
			break;
		}
	}
	if(find)
		printf("YES\n");
	else
		printf("NO\n");
	}
	return 0;
}
