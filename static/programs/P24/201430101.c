#include<stdio.h>
#include<stdlib.h>
typedef long long int ll;
typedef struct list{
	long long int a;
	long long int ht;
	long long int ln;
	long long int rn;
	struct list*left;
	struct list*right;
}node;

node *head=NULL;
node *rightrot(node *);
node *leftrot(node *);

int height(node *l){
	if(l==NULL)
		return -1;
	return l->ht;
}

node *insert(node*root,ll val)
{
	ll bl=0, br=0;
	if(root==NULL)
	{
		root=malloc(sizeof(node));
		root->a=val;
		root->left=NULL;
		root->right=NULL;
		root->ln=0;
		root->rn=0;
		root->ht = 0;
	}
	else if(val>root->a)
	{
		(root->rn)++;
		root->right=insert(root->right,val);
		br = height(root->right->left)-height(root->right->right);

	}
	else if(val<root->a)
	{
		(root->ln)++;
		root->left=insert(root->left,val);
		bl = height(root->left->left)-height(root->left->right);
	}
	//just the height
	int hr, hl;
	hl = height(root->left);
	hr = height(root->right);
	root->ht = (hl>hr)?hl+1:hr+1;

	//height end
	ll bal = height(root->left)-height(root->right);


#ifdef DEBUG
	fprintf(stderr, "%lld %lld %lld\n", bal, bl, br);
	fprintf(stderr, "%lld\n", root->ht);
	fprintf(stderr, "hl %d hr %d\n", hl, hr);
#endif
	//checking bal
	//end balance

	//LL case
	if(bal>1 && bl>0)
		root=rightrot(root);
	//RR case
	if(bal<-1 && br<0)
		root=leftrot(root);
	//RL case
	if(bal<-1 && br>0)
	{
		root->right= rightrot(root->right);
		root=leftrot(root);
	}
	//LR case
	if(bal>1 && bl<0)
	{
		root->left=leftrot(root->left);
		root=rightrot(root);
	}
	return root;
}
node *rightrot(node*temp)
{
	//if(temp==NULL)
	//	return;

	node*var1=temp->left;
	node *var2=NULL;
	//var1->right;
	if(var1->right!=NULL)
		var2=var1->right;

	//ln and rn
	if(var2!=NULL)
	{
		temp->ln=var2->ln+var2->rn+1;
		var1->rn=temp->ln+temp->rn+1;
	}
	if(var2==NULL)
	{
		(temp->ln)=0;
		var1->rn=temp->ln+temp->rn+1;
	}

	var1->right=temp;
	temp->left=var2;

	if(temp->left==NULL && temp->right==NULL)//updating height of temp
		temp->ht=1;
	else if(temp->left==NULL)
		temp->ht=(temp->right)->ht+1;
	else if(temp->right==NULL)
		temp->ht=(temp->left)->ht+1;

	else if((temp->left)->ht>(temp->right)->ht)
		temp->ht=(temp->left)->ht+1;
	else
		temp->ht=(temp->right)->ht+1;
	if(var1->left==NULL && var1->right==NULL)//updating height of var1
		var1->ht=1;
	else if(var1->left==NULL)
		var1->ht=(var1->right)->ht+1;
	else if(var1->right==NULL)
		var1->ht=(var1->left)->ht+1;
	else if((var1->left)->ht>(var1->right)->ht)
		var1->ht=(var1->left)->ht+1;
	else
		var1->ht=(var1->right)->ht+1;

	return var1;//returns new node	
}
node*leftrot(node*temp)
{

	//	if(temp==NULL)
	//		return;
	node*var1=temp->right;
	node*var2=NULL;//var1->left;
	if(var1->left!=NULL)
		var2=var1->left;
	//updating rn and ln
	if(var2!=NULL)
	{
		temp->rn=var2->ln+var2->rn+1;
		var1->ln=temp->ln+temp->rn+1;
	}
	if(var2==NULL)
	{
		temp->rn=0;
		var1->ln=temp->ln+temp->rn+1;
	}


	var1->left=temp;
	temp->right=var2;
	if(temp->left==NULL && temp->right==NULL)//updating height of temp
		temp->ht=1;
	else if(temp->left==NULL)
		temp->ht=(temp->right)->ht+1;
	else if(temp->right==NULL)
		temp->ht=(temp->left)->ht+1;
	else if((temp->left)->ht>(temp->right)->ht)
		temp->ht=(temp->left)->ht+1;
	else
		temp->ht=(temp->right)->ht+1;
	if(var1->left==NULL && var1->right==NULL)//updating height of var1
		var1->ht=1;
	else if(var1->left==NULL)
		var1->ht=(var1->right)->ht+1;
	else if(var1->right==NULL)
		var1->ht=(var1->left)->ht+1;

	else if((var1->left)->ht>(var1->right)->ht)
		var1->ht=(var1->left)->ht+1;
	else
		var1->ht=(var1->right)->ht+1;

	return var1;
}
ll search(node *temp,ll x)
{
	if(temp==NULL)
		return 0;
	if(x==temp->a)
		return 1;
	if(temp->a>x)
		search(temp->left,x);
	else if(temp->a<x)
		search(temp->right,x);

}
ll rem=-1;
void healthy(node*temp,ll x)
{
	if(temp==NULL)
		return;
	if(temp->ln==x-1)
		rem=temp->a;
	else if(temp->ln>=x)
		healthy(temp->left,x);
	else if(temp->ln<x)
		healthy(temp->right,x-temp->ln-1);
}
//void inde(node *);
ll fin=0;
void rotten(node*temp,ll x)
{
	if(temp==NULL)
		return;
	if(x==temp->a)
		fin=temp->ln+fin;
	else if(x>temp->a)
	{
		fin=temp->ln+1+fin;
		rotten(temp->right,x);
	}
	else if(x<temp->a)
		rotten(temp->left,x);
}


void print_n(node *t, int s){
	if(t==NULL) 
		return;
	int i;
	for(i=0; i<s; i++){
		fprintf(stderr, " ");
	}
	fprintf(stderr, "%lld\n", t->a);
	print_n(t->left, s+1);
	print_n(t->right, s+1);
}

void debug_tree(node *root){
	fprintf(stderr, "Tree:\n");
	print_n(root, 0);
	fprintf(stderr, "\n");
}


int main()
{
	ll num;
	char c[1000];
	while(3)
	{
		fin=0;
		rem=-1;

		scanf("%s",c);
		if(c[0]=='Q')
			break;
		scanf("%lld",&num);
		if(c[0]=='S')
			head=insert(head,num);
		else if(c[0]=='C')
		{
			ll e=search(head,num);	
			if(e==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(c[0]=='R')
		{
			rotten(head,num);
			printf("%lld\n",fin);

		}
		else if(c[0]=='H')
		{
			healthy(head,num);
			if(rem==-1)
				printf("NONE\n");
			else
				printf("%lld\n",rem);
		}
#ifdef DEBUG
		debug_tree(head);
#endif
	}
	return 0;
}
/*      while(3)
		181                 {
		182                 int p;
		183                 scanf("%d",&p);
		184                 if(p==-1)
		185                 break;
		186                 head=insert(head,p);
		187                 }
		188                 inde(head);
		189                 return 0;
		190                 }
		191                 void inde(node *T)
		192                 {
		193                 if(T!=NULL)
		194                 {
		195                 inde(T->left);
		196                 printf("%d(ln=%d) rn-%d ht-%d ",T->a,T->ln,T->rn,T->ht);
		197                 inde(T->right);
		198                 }
		199 
		200                 }
		201          */

