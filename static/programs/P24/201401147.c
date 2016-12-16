#include<stdio.h>//Using code from DS LAB
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int v;
	struct node *right;
	struct node *left;
	int height;
	int count;
	int lessthan;
}node;
int height(node *x){
	return (x==NULL)?0:x->height;
}
int count(node *x){
	return (x==NULL)?0:x->count;
}
int bal(node *x){
	return height(x->left)-height(x->right);
}
int less(node *x){
	return (x==NULL)?0:x->lessthan;
}
node * clock(node *root){
	//printf("Into the clock function\n");
	node *temp2=root->left;
	node *temp1=temp2->right; // storing 
	temp2->right=root;
	root->left=temp1;
	root->height=fmax(height(root->left),height(root->right))+1;
	temp2->height=fmax(height(temp2->left),height(temp2->right))+1;
	root->count=count(root->right)+count(root->left)+1;
	temp2->count=count(temp2->right)+count(temp2->left)+1;
	//temp2->lessthan=less(temp2->left)+1;
	//root->lessthan=less(root->left)+1;
	return temp2;
}
node * anticlock(node *root){
	//printf("Into the anticlock function\n");
	node *temp2=root->right;
	node *temp1=temp2->left;
	temp2->left=root;
	root->right=temp1;
	root->height=fmax(height(root->right),height(root->left))+1;
	temp2->height=fmax(height(temp2->right),height(temp2->left))+1;
	//count change starts here
	//printf("everthing NORmal\n");
	root->count=count(root->right)+count(root->left)+1;
	temp2->count=count(temp2->right)+count(temp2->left)+1;
	//root->lessthan=less(root->right)-1;
	//temp2->lessthan=less(temp2->right)-1;
	return temp2;
}
node * process(node * root){
	//printf("Into the process function\n");
	//printf("%d\t%d\n",left,right);
	if(bal(root)> 1 && bal(root->left)>=1){//left-left
		root=clock(root);
	}
	else if(bal(root) >1 && bal(root->left)<=-1){//left-right
		root->left=anticlock(root->left);
		root=clock(root);
	}
	else if(bal(root)< -1 && bal(root->right)<=-1){//right-right
		root=anticlock(root);
	}
	else if(bal(root)< -1 && bal(root->right)>=1){//right-left
		root->right=clock(root->right);
		root=anticlock(root);
	}
	return root;
}
void preorder(node *root){
	if(root==NULL)
		return;
	printf("%d\t%d\t%d\t%d\n",root->v,root->height,root->count,root->lessthan);
	preorder(root->left);
	preorder(root->right);
	return ;
}
//node *mainhead;
node *insert(int v,node *root){
	//printf("Into the insert function\n");
	node * p=NULL;
	p=malloc(sizeof(node));
	if(root==NULL){
		p->v=v;
		p->height=1;
		p->count=1;
		//p->lessthan=0;
		return p;
	}
	else if(root->v < v){
		root->right=insert(v,root->right);
		//root->right->lessthan=root->lessthan+1;
		//printf("Here the root is %d\n",root->v);
	}
	else{
		root->left=insert(v,root->left);
		//root->lessthan+=1;
		//root->left->lessthan=(root->lessthan)-1;
		//printf("Here the root is %d\n",root->v);
	}
	root->height=fmax(height(root->left),height(root->right))+1;
	//preorder(mainhead);
	root->count+=1;	
	root=process(root);
	return root;
}
int total=0;
int blag=0;
int rottencount=0;
int rotten(node *head,int v){
	if(head==NULL)
		return 0;
	if(head->v <v){
		return count(head->left)+1+rotten(head->right,v);
	}
	else if(head->v==v){
		return count(head->left);
	}
	else{
		return rotten(head->left,v);
	}
}
/*void rotten(node *root,int v,int child,int pc){//modified  inorder function
  if(root==NULL){
  return;
  }
  rotten(root->left,v,0,count(root));
  if(blag)
  return;
  if(root->v>=v){  //printf("%d\t%d\n",root->v,root->height);
  blag=1;
  if(child==1)//right child
  printf("%d\n",pc-count(root));
  else //left child
  printf("%d\n",count(root->left));
  return ;
  }
  if(blag)
  return;
  rotten(root->right,v,1,count(root));
  return ;
  }*/
void kmin(node *head,int k){
	//printf("head is %d and k is %d\n",head->v,k);
	if(count(head) < k){
		printf("NONE\n");
		return ;
	}
	else{
		if(k==count(head->left)+1){
			//printf("SHow time\n");
			printf("%d\n",head->v);
			return ;
		}
		else if(count(head->left)>= k){
			//printf("Going to the left\n");
			kmin(head->left,k);
			return;
		}
		else{
			//printf("Going to the right\n");
			kmin(head->right,k-count(head->left)-1);
			return ;
		}
	}
}
void find(node *root,int v){
	//printf("Hello\n");
	if(root==NULL){
		printf("NO\n");
		return ;
	}
	else if(root->v==v){
		printf("YES\n");
	}
	else if(v>root->v){
		find(root->right,v);
	}
	else{
		find(root->left,v);
	}
	return ;
}
int main(){
	node * head=NULL;
	char s[15];
	int i,v,ch,sd;
	while(1){
		scanf("%s",s);
		if(strcmp(s,"SetHealthy")==0){
			scanf("%d",&v);
			//mainhead=head;
			head=insert(v,head);
			total=count(head);
		}
		else if(strcmp(s,"CheckHealthy")==0){
			scanf("%d",&v);
			find(head,v);
		}
		else if(strcmp(s,"RottenBefore")==0){
			blag=0;
			scanf("%d",&v);
			printf("%d\n",rotten(head,v));
			//if(!blag)
			//printf("%d\n",total);
		}
		else if(strcmp(s,"Healthy")==0){
			scanf("%d",&v);
			kmin(head,v);
		}
		else if(strcmp(s,"Quit")==0){
			break;
		}
		else if(strcmp(s,"pre")==0){
			printf(" Value\tHeight\tcount\tlessthan\n");
			preorder(head);

		}
	}
	return 0;
}
