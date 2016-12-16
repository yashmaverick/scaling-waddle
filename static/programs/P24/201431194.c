#include<stdio.h>
#include<stdlib.h>
#define max(a,b) a>b?a:b
struct node{
	int data;
	int ht;
	int e;
	struct node* left;
	struct node* right;
};
struct node* leftrot(struct node* head){
	struct node* tmp = head;
	struct node* tmp1 = head->right;
	head = tmp1;
	tmp->right = head->left;
	head->left = tmp;
	int x = max(height(head->left->right),height(head->left->left));
	head->left->ht = x+1;
	head->left->e=ele(head->left->left)+ele(head->left->right)+1;
	int y = max(height(head->left),height(head->right));
	head->e=ele(head->left)+ele(head->right)+1;
	head->ht = y + 1;
	return head;
}
struct node* rightrot(struct node* head){
	struct node* tmp = head;
	struct node* tmp1 = head->left;
	head = tmp1;
	tmp->left = head->right;
	head->right = tmp;
	int x = max(height(head->right->right),height(head->right->left));
	head->right->e=ele(head->right->left)+ele(head->right->right)+1;
	head->right->ht = x+1;
	x = max(height(head->left),height(head->right));
	head->e=ele(head->left)+ele(head->right)+1;
	head->ht = x+1;
	return head;
}
int height(struct node* now){
	if(now==NULL)
		return 0;
	return now->ht;
}
int ele(struct node* head)
{
	if(head==NULL)
		return 0;
	return head->e;
}
struct node* insert(struct node* head,int x){
	if(head==NULL){
		struct node* t = (struct node*)malloc(sizeof(struct node));
		t->left = NULL;
		t->ht = 1;
		t->right = NULL;
		t->data = x;
		t->e=1;
		return t;
	}
	int hll,hlr,hrr,hrl;
	if(x < head->data)
		head->left = insert(head->left,x);
	else
		head->right = insert(head->right,x);
	int hl = height(head->left);
	int hr = height(head->right);
	if(head->left!=NULL){
		hll = height(head->left->left);
		hlr = height(head->left->right);
	}
	if(head->right!=NULL){
		hrr = height(head->right->right);
		hrl = height(head->right->left);
	}
	if(hl-hr>1 && hll > hlr)
		head = rightrot(head);
	else if(hl - hr>1 && hll < hlr){
		head->left = leftrot(head->left);
		head = rightrot(head);
	}
	else if((hl - hr)<-1 && hrr > hrl)
		head = leftrot(head);
	else if(hl - hr < -1 && hrr < hrl){
		head->right = rightrot(head->right);
		head = leftrot(head);
	}
	int u = height(head->left);
	int v = height(head->right);
	int aa=max(u,v);
	head->ht=aa+1;
	head->e=ele(head->left)+ele(head->right)+1;
	return head;
}
int check(struct node* head,int x){
	if(head==NULL)
		return -1;
	if(x > head->data)
		return check(head->right,x);
	if(x < head->data)
		return check(head->left,x);
	else
		return 1;
}
/*void print(struct node* head){
	if(head==NULL)
		return;
	print(head->left);
	printf("%d %d\n",head->data,head->ht);
	print(head->right);
	return ;
}*/
int func(struct node* head,int x){
	if(head==NULL)
		return -1;
	if(ele(head->left)+1==x)
		return head->data;
	else if(ele(head->left)>=x)
		return func(head->left,x);
	return func(head->right,x-ele(head->left)-1);
}
int rottn(struct node* head,int x){
	if(head==NULL)
		return 0;
	if(head->data==x)
		return ele(head->left);
	if(head->data>x)
		return rottn(head->left,x);
	return rottn(head->right,x)+ele(head->left)+1;
}
int main(){
	int i,j,k,l,n,m,x,root,z;
	struct node* head=NULL;
	char c[100];
	scanf(" %s",c);
	while(c[0]!='Q'){
		if(c[0]=='C'){
			scanf("%d",&x);
			if(check(head,x)==-1)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else if(c[0]=='S'){
			scanf("%d",&x);
			head = insert(head,x);
		}
		else if(c[0]=='H'){
			scanf("%d",&x);
			x=func(head,x);
			if(x==-1)
				printf("NONE\n");
			else
				printf("%d\n",x);
		}
		else if(c[0]=='R'){
			scanf("%d",&x);
			x=rottn(head,x);
			printf("%d\n",x);
		}
		scanf(" %s",c);
	}
	return 0;
}
