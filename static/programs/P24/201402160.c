#include<stdio.h>
#include<stdlib.h>
#define cin(n) scanf("%d", &n)
#define cout(n) printf("%d ", n);
#define endl printf("\n")
#define forn(i, n) for(i=0; i<n; i++)
#define for1(i, n) for(i=1; i<=n; i++)
#include<string.h>
#define N 1000234
typedef struct n node;

struct n{
	int data;
	int height, no;
	node *left, *right;
};
int height(node* head){
	if(head==NULL)return 0;
	return head->height;
}
int bal(node* head){
	if(head==NULL)return 0;
	return height(head->left)-height(head->right);
}
int max(int a, int b){
	if(a>b)return a;
	return b;
}
int number(node *head){
	if(head==NULL)return 0;
	return head->no;
}
node* right_rotate(node* head){
	//if(!head->left || !head->left->right)return head;
	node* temp = head->left;
	head->left = temp->right;
	temp->right=head;
	head->no = number(head->left)+number(head->right)+1;
	temp->no = number(temp->left)+number(temp->right)+1;
	head->height = max(height(head->left), height(head->right))+1;
	temp->height = max(height(temp->left), height(temp->right))+1;
	return temp;
}
node* left_rotate(node* head){
	//if(!head->right || !head->right->left)return head;
	node* temp = head->right;
	head->right = temp->left;
	temp->left = head;
	head->no = number(head->left)+number(head->right)+1;
	temp->no = number(temp->left)+number(temp->right)+1;
	head->height = max(height(head->left), height(head->right))+1;
	temp->height = max(height(temp->left), height(temp->right))+1;
	return temp;
}
node* newt(int data){
	node* temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->height = 1;
	temp->no = 1;
	temp->left = temp->right = NULL;
	return temp;
}
node* add(int data, node *head){
	if(head==NULL)return newt(data);
	
	if(data>head->data){
		if(head->right!=NULL)head->right=add(data, head->right);
		else head->right = newt(data);
	}
	else{
		if(head->left!=NULL)head->left=add(data, head->left);
		else head->left = newt(data);
	}
	return head;
}
node* insert(int data, node *head){
	//printf("%d ", data);	
	if(head==NULL)return newt(data);
	if(data>head->data)head->right=insert(data, head->right);
	else head->left=insert(data, head->left);
	
	head->height=max(height(head->left), height(head->right))+1;
	head->no = number(head->left)+number(head->right)+1;
	int balance = height(head->left)-height(head->right);
	//cout<<head->data<<">"<<balance<<" ";
	//printf("%d %d\n", head->data, balance);
	if(balance>1 && data<head->left->data) return right_rotate(head);
	else if(balance>1 && data>head->left->data){ head->left=left_rotate(head->left); return right_rotate(head); }
	else if(balance<-1 && data>head->right->data) return left_rotate(head);
	else if(balance<-1 && data<head->right->data){ head->right=right_rotate(head->right); return left_rotate(head); }
	
	return head;
}
int search(int data, node* head){
	if(head==NULL)return 0;
	if(head->data == data)return 1;
	else if(head->data < data)return search(data, head->right);
	else return search(data, head->left);
	//if(search(data, head->left))return 1;
	//if(search(data, head->right))return 1;
	return 0;
}
void show(node* head){
	if(head==NULL)return;
	printf("%d-%d ", head->data, number(head));
	show(head->left);
	show(head->right);
}

int xth(node* head, int x){
	//if(x==0)return head->data;
	if(x>number(head))return -1;
	if(number(head)==1)return head->data;
	if(number(head->left)>x-1)return xth(head->left, x);
	else if(number(head->left)==x-1)return head->data;
	else return xth(head->right, x-number(head->left)-1);
}

int rtbf(node* head, int x){
	if(head==NULL)return 0;
	if(head->data<x)return number(head->left)+1+rtbf(head->right, x);
	else if(head->data>=x)return rtbf(head->left, x);
}

int main(){
	node *head = NULL;
	int data;
	char a[100];
	while(1){
		//cin(data);
		//head = insert(data, head);
		//show(head); endl;
		//cout(rtbf(head, 4)); endl;
		scanf("%s", a);
		if(strcmp(a, "Quit")==0)break;
		//printf("%d", strcmp(a, "Quit")==0);
		scanf("%d", &data);
		//scanf("%s %d", a, &data);
		if(strcmp(a, "SetHealthy")==0){
			//if(data%1000==0)printf("%d\n", data);
			head = insert(data, head);
		}
		if(strcmp(a, "CheckHealthy")==0){
			if(search(data, head))printf("YES\n");
			else printf("NO\n");
		}
		if(strcmp(a, "Healthy")==0){
			int k = xth(head, data);
			if(k==-1)printf("NONE\n");
			else printf("%d\n", k);
		}
		if(strcmp(a, "RottenBefore")==0)printf("%d\n", rtbf(head, data));
		if(strcmp(a, "Quit")==0)break;
	}
	return 0;
}

