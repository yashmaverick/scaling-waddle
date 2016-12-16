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
typedef struct node node;
struct node{
	int val,h;
	int cl,cr,ct;
	int lt,gt;
	node* l;
	node* r;
};
int search(node* root,int key){
	if(root==NULL)return 0;
	if(root->val==key)return 1;
	if(key<root->val)return search(root->l,key);
	if(key>root->val)return search(root->r,key);
}
int height(node* root){
	if(root==NULL)return 0;
	return root->h;
}
int countl(node* root){
	if(root==NULL)return 0;
	return root->cl;
}
int countr(node* root){
	if(root==NULL)return 0;
	return root->cr;
}
int count(node* root){
	if(root==NULL)return 0;
	return countl(root)+countr(root)+1;
}
node* updateh(node* root){
	root->h=max(height(root->l),height(root->r))+1;
	return root;
}
node* updatec(node* root){
	int l=root->l==NULL?0:1;
	int r=root->r==NULL?0:1;
	root->cl=countl(root->l)+countr(root->l)+l;
	root->cr=countl(root->r)+countr(root->r)+r;
	root->ct=countl(root)+countr(root)+1;
	//root->ct=count(root->l)+count(root->r)+1;
	return root;
}
node* srl(node* root){
	node* left=root->l;
	root->l=left->r;
	left->r=root;
	root->cl=countr(left);
	left->cr=countl(root);
	root=updateh(root);
	left=updateh(left);
	return left;
}
node* srr(node* root){
	node* right=root->r;
	root->r=right->l;
	right->l=root;
	root->cr=countl(right);
	right->cl=countr(root);
	root=updateh(root);
	right=updateh(right);
	return right;
}
node* drl(node* root){
	root->l=srr(root->l);
	return srl(root);
}
node* drr(node* root){
	root->r=srl(root->r);
	return srr(root);
}
node* insert(node* root,int x){
	if(root==NULL){
		node* new=(node*)malloc(sizeof(node));
		new->val=x;
		new->l=new->r=NULL;
		new->cl=new->cr=new->gt=new->lt=0;
		new->ct=1;
		root= new;
	}
	else if(x<root->val){
		root->l=insert(root->l,x);
		//root->lt++;
		//root->l->gt=root->gt+1;
		//root->cl++;
		if(height(root->l)-height(root->r)==2){
			if(height(root->l->l)>height(root->l->r))
					root=srl(root);
			else
				root=drl(root);
	}
	}
	else{
		root->r=insert(root->r,x);
		//root->gt++;
		//root->r->lt=root->lt+1;
		//root->cr++;
		if(height(root->r)-height(root->l)==2){
			if(height(root->r->r)>height(root->r->l))
					root=srr(root);
			else
				root=drr(root);
	}
	}
	root=updateh(root);
	root=updatec(root);
	return root;
}
void pre(node* root){
	if(root==NULL)return;
	printf("%d ",root->val);
	pre(root->l);
	pre(root->r);
}
int klow(node* root,int k){
	if(root==NULL)return -1;
	else if(countl(root)==k-1)return root->val;
	else if(countl(root)>k-1)return klow(root->l,k);
	else if(k-1>countl(root))return klow(root->r,k-1-countl(root));
}
int countk(node* root,int k){
	if(root==NULL) return 0;
	else if(root->val==k)return countl(root);
	else if(root->val<k)return countl(root)+1+countk(root->r,k);
	else if(root->val>k)return countk(root->l,k);
}
int main(){
	node* root=NULL;
	char s[100];
	int n,x;
	int op;
	while(1){
		scanf("%s",s);
		if(strcmp(s,"Quit")==0)break;
		else if(strcmp(s,"SetHealthy")==0){
			si(x);root=insert(root,x);
		}
		else if(strcmp(s,"CheckHealthy")==0){si(x);
			if(search(root,x))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(strcmp(s,"Healthy")==0){si(x);
			if(klow(root,x)==-1)
				printf("NONE\n");
			else
				sout(klow(root,x));}
		else if(strcmp(s,"RottenBefore")==0){si(x);sout(countk(root,x));}
	}
	return 0;
}
