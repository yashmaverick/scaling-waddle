#include<stdio.h>
#include<stdlib.h>

struct tree{
	int data;
	int height;
	int count;
	struct tree* left;
	struct tree* right;
}e;

int he,ind,fl;
typedef struct tree tree;
tree *root;
tree* insert(tree *a,int val);
tree* balance(tree *a);
void post_order(tree *a);
void in_order(tree *a);
int Healthy(tree *a,int x);
tree* find_k_min(tree *a,int k);
tree* newNode(int key);
tree *rightRotate(tree *y);
tree *leftRotate(tree *x);
int getBalance(tree *N);
int rot(tree *a,int x);
void dfs(tree *a);
void Check_Healthy(tree *a,int x);
int max(int p,int q);
int height(tree *a);
int count(tree *a);
int main(){
	int t,i,ans;
	char s[25];
	while(1){
		scanf("%s",s);
		if(s[0]=='S'){
			scanf("%d",&i);
			root=insert(root,i);
		}
		else if(s[0]=='C'){
			scanf("%d",&i);
			fl=0;
			Check_Healthy(root,i);
			if(fl==1)
				printf("YES\n");
			else
				printf("NO\n");
		}
		else if(s[0]=='H'){

			scanf("%d",&i);	
			//	count=0;
			//	fl=0;
			ans=Healthy(root,i);
			if(ans!=-1)
				printf("%d\n",ans);
			else
				printf("NONE\n");
		}

		else if(s[0]=='R'){
			scanf("%d",&i);	
			//	count=0;
			//	fl=0;
			ans=rot(root,i);
			printf("%d\n",ans);	
		}

		else if(s[0]=='Q')
			break;

		else if(s[0]=='P'){
			in_order(root);
			printf("\n");
		}
		/*else if(s[0]=='c'){
		  tree *temp=root;
		  while(temp){
		  printf("%d\n",count(temp));
		  temp=temp->right;
		  }
		  while(temp){
		  printf("%d\n",count(temp));
		  temp=temp->right;
		  }
		  }*/
	}
	//in_order(root);
	//printf("\n");
	return 0;
}
int height(tree *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}
int count(tree *N)
{
	if (N == NULL)
		return 0;
	return N->count;
}

int max(int a, int b)
{
	if(a > b)
		return a;
	else
		return b;
}

tree* newNode(int key)
{
	tree* node = (tree*)
		malloc(sizeof(tree));
	node->data   = key;
	node->left   = NULL;
	node->right  = NULL;
	node->height = 1;
	node->count  = 1; 
	return(node);
}
tree *rightRotate(tree *y)
{
	tree *x = y->left;
	tree *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left), height(y->right))+1;
	x->height = max(height(x->left), height(x->right))+1;

	y->count = count(y->left)+count(y->right)+1;
	x->count = count(x->left)+count(x->right)+1;
	return x;
}

tree *leftRotate(tree *x)
{
	tree *y = x->right;
	tree *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left), height(x->right))+1;
	x->count = count(x->left)+count(x->right)+1;
	y->height = max(height(y->left), height(y->right))+1;
	y->count = count(y->left)+count(y->right)+1;

	return y;
}

int getBalance(tree *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}

tree* insert(tree* node, int key)
{
	tree *par;
	int parc;
	if (node == NULL)
		return(newNode(key));
	if (key < node->data){

		node->left  = insert(node->left, key);
	}
	else{
		node->right = insert(node->right, key);

	}
	node->height = max(height(node->left), height(node->right)) + 1;
	node->count = count(node->left)+count(node->right)+ 1;
	int balance = getBalance(node);

	if (balance > 1 && key < node->left->data)
		return rightRotate(node);

	if (balance < -1 && key > node->right->data)
		return leftRotate(node);

	if (balance > 1 && key > node->left->data)
	{
		node->left =  leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void post_order(tree *a){
	if(a==NULL)
		return;
	else{
		post_order(a->left);
		post_order(a->right);
		printf("%d ",a->data);
	}
}
void in_order(tree *a){
	if(a==NULL)
		return;
	else{
		in_order(a->left);
		printf("val:%d count:%d\n",a->data,count(a));
		in_order(a->right);
	}

}

int Healthy(tree *a,int x){
	//tree *temp;
	/*	if(a==NULL)
		return;
		else if(fl!=1){
		Healthy(a->left,x);
		if(count == x-1){
		fl=1;
		he = a->data;
		}
		else if(fl!=1)
		count++;
		Healthy(a->right,x);
		}

	 */
	/*temp=find_k_min(root,x);
	  if(temp)
	  printf("%d\n",temp->data);
	  else
	  printf("NONE\n");
	 */

	if(x > count(a))
		return -1;
	if(count(a)==1)
		return a->data;
	if(x < (count(a->left)+1))
		return Healthy(a->left,x);
	else if(x == (count(a->left) + 1))
		return a->data;
	else
		return Healthy(a->right,x-(count(a->left)+1));
}
int rot(tree *a,int x){
	/*	if(a==NULL)
		return;
		else if(fl!=1){
		rot(a->left,x);
		if(a->data>=x)
		fl=1;
		else if(fl!=1)
		count++;
		rot(a->right,x);
		}
	 */
	/*tree *temp;
	  int y;
	  temp=find_k_min(root,x);
	  y=count(temp);
	  printf("%d\n",y-1);
	 */

	if(a==NULL)
		return 0;
	if(a->data>=x)
		return rot(a->left,x);
	else if(a->data<x)
		return (1+count(a->left)+rot(a->right,x));
}
void Check_Healthy(tree *a,int x){
	if(a==NULL)
		return;
	if(a!=NULL&&x==a->data)
		fl=1;
	else if(fl!=1){
		if( x < a->data)
			Check_Healthy(a->left,x);

		else if(x > a->data)
			Check_Healthy(a->right,x);

	}

	/*	tree* temp;
		temp=find_k_min(root,x);
		if(temp)
		printf("YES\n");
		else
		printf("NO\n");*/

}

/*tree* find_k_min(tree *a,int k){

  if(a==NULL)
  return a;
  if(a!=NULL&&k==count(a)+1)
  return a;
  else if(a!=NULL&&k > count(a->left)){
  k = k-(count(a->left+1));
  a=a->right;
  }
  else if(a!=NULL)
  a=a->left;

  int ans=-1;
  tree *temp=NULL;
  if(root){
  temp=root;
  while(temp){
  if(1+count(temp)==k)
  {
  ans = temp->data;
  break;
  }
  else if(k > count(temp))
  {
  k = k-(count(temp) + 1);
  temp=temp->right;
  }
  else
  temp=temp->left;
  }
  }
  return temp;
  }*/
