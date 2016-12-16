#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct avl{
	int val;
	int height;
	int balance;
	int rc,lc;
	struct avl* left,*right;
}avl;
void out(int *pointer){
printf("%d\n",*pointer);
}
void inv(){
printf("NONE\n");
}
void strin(char *address){
scanf("%s",address);
}
void intin(int *address){
scanf("%d",address);
}
void yes(){
printf("YES\n");
}
void no(){
printf("NO\n");
}
int max(int a,int b){return a>b?a:b;}
int height(avl* root){
	if(root==NULL) return 0;
	return root->height;
}
int balance(avl* root){
	if(root==NULL) return 0;
	return root->balance;
}
avl *findinorder(avl *root){
	avl *current=root;
	while(current!=NULL && current->right!=NULL) current=current->right;
	return current;
}
avl *rightrot(avl *root){
	avl *tmp1=root->left;
	avl *tmp2=tmp1->right;
	tmp1->right=root;
	root->left=tmp2;
	root->height=max(height(root->left),height(root->right))+1;
	root->balance=height(root->left)-height(root->right);
	tmp1->height=max(height(tmp1->left),height(tmp1->right))+1;
	tmp1->balance=height(tmp1->left)-height(tmp1->right);
	root->lc=tmp1->rc;
	tmp1->rc=root->lc+root->rc+1;
	return tmp1;
}
avl *leftrot(avl *root){
	avl *tmp1=root->right;
	avl *tmp2=tmp1->left;
	tmp1->left=root;
	root->right=tmp2;
	root->height=max(height(root->left),height(root->right))+1;
	root->balance=height(root->left)-height(root->right);
	tmp1->height=max(height(tmp1->left),height(tmp1->right))+1;
	tmp1->balance=height(tmp1->left)-height(tmp1->right);
	root->rc=tmp1->lc;
	tmp1->lc=root->rc+root->lc+1;
	return tmp1;
}
avl* balanceavl(avl *root){
	int b,bl,br;
	b=balance(root);
	bl=balance(root->left);
	br=balance(root->right);
	if(b==2 && bl>=0) return rightrot(root);
	else if (b==2 && bl<0){
		root->left=leftrot(root->left);
		return rightrot(root);
	}
	else if (b==-2 && br<=0) return leftrot(root);
	else if(b==-2 && br==1) {
		root->right=rightrot(root->right);
		return leftrot(root);
	}
}
avl* insert(avl *root,int value){
	if(root==NULL){
		avl *new=(avl*)malloc(sizeof(avl));
		new->val=value;
		new->height=1;
		new->left=new->right=NULL;
		new->balance=new->rc=new->lc=0;
		return new;
	}
	if(value<root->val) {
		root->lc++;
		root->left=insert(root->left,value);
	}
	else{
		root->rc++;
		root->right=insert(root->right,value);
	}
	root->height=max(height(root->left),height(root->right))+1;
	root->balance=height(root->left)-height(root->right);
	if(root->balance ==2 || root->balance==-2)
		return balanceavl(root);
	return root;
}
avl *delete(avl *root,int value){
	if(root==NULL)
		return root;
	else if (value<root->val){
		root->lc--;
		root->left=delete(root->left,value);
	}
	else if(value>root->val){
		root->rc--;
		root->right=delete(root->right,value);
	}
	else{
		avl *tmp;
		if(root->left==NULL||root->right==NULL){
			if(root->left==NULL) tmp=root->right;
			else tmp=root->left;
			if(tmp==NULL){
				tmp=root;
				root=NULL;
			}
			else *root=*tmp;
			free(tmp);
		}
		else{
			tmp=findinorder(root->left);
			root->val=tmp->val;
			root->left=delete(root->left,tmp->val);
		}
	}
	if(root==NULL) return root;
	root->height=max(height(root->left),height(root->right))+1;
	root->balance=height(root->left)-height(root->right);
	if(root->balance ==2 || root->balance==-2)
		return balanceavl(root);
	return root;
}
void ksmall(avl *head,int k){
	int ans;
	while(head!=NULL){
		if(k==head->lc+1){
			ans=head->val;
			break;
		}
		else if (k>head->lc+1){
			k-=head->lc+1;
			head=head->right;
		}
		else head=head->left;
	}
		out(&ans);
}
void smallest(avl *head,int value){
	int ans=0;
	while(head!=NULL){
		if(head->val==value){
			ans+=head->lc;
			break;
		}
		else if(head->val<value){
			ans+=head->lc+1;
			head=head->right;
		}
		else head=head->left;
	}
	out(&ans);
}
bool search(avl *head,int i)
{
	if(head==NULL)
		return 0;
	if(head->val==i)
		return 1;
	if(head->val>i)
		return search(head->left,i);
	else return search(head->right,i);
}
int main()
{
	int n,i,x,y;
	char q[12];
	avl *head=NULL;
	while(1){	
		strin(q);
		intin(&x);
		if(q[0]=='S') {
			if(!search(head,x))
				head=insert(head,x);
		}
		else if(q[0]=='C'){
			if(search(head,x))yes();
			else no();
		}
		else if(q[0]=='H'){
			if(x==0||head==NULL||x>head->lc+head->rc+1)inv();
			else ksmall(head,x);
		}
		else if (q[0]=='R'){
			smallest(head,x);
		}
		else if (q[0]=='Q')return 0;
	}
	return 0;
}
