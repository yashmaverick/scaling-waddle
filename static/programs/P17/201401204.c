#include<stdio.h>
#include<stdlib.h>
int presearch1[1000];
int presearch2[1000];
struct node{
	int d;
	struct node*left;
	struct node*right;
};
typedef struct node node;

node*maketree(int*in,int*pre,int n){
	if(n==0)
		return NULL;
	int rootnum=pre[0];
	int i;
	int rootindex; // in inorder array
	for(i=0;i<n;i++){
		if(in[i]==rootnum){
			rootindex=i;			// rootindex will be relative to the current passed arrays,not the whole array
			break;
		}
	}
	node*root=(node*)malloc(sizeof(node));
	root->d=rootnum;
	root->left=maketree(in,pre+1,rootindex);	// complete inorder array passed but will be used only upto in+rootindex
	root->right=maketree(in+rootindex+1,pre+rootindex+1,n-rootindex-1);	// inorder array after the current root is passed only
	return root;
}
int t1=0;
void postorder(node*root){
	if(root==NULL)
		return;
	printf("%d ",root->d);
	postorder(root->left);
	postorder(root->right);
	//	printf("\n");
}
int fl=0;
void print(){
	printf("pre array: ");
	int i;
	for(i=0;i<t1;i++)
		printf("%d ",presearch1[i]);
	return;
}
void presearch(node*root,int s){
	if(root==NULL){
		return;
	}
	presearch1[t1++]=root->d;
	if(root->d==s)
		print();
	else{
		presearch(root->left,s);
		presearch(root->right,s);
	}
}
int lca(node*root,int a1,int a2){
	if(root==NULL)
		return -1;
	if(root->d==a1 || root->d==a2){
		//	printf("m %d\n",root->d);
		return root->d;
	}

	int leftlca=lca(root->left,a1,a2);
	int rightlca=lca(root->right,a1,a2);

	if(rightlca!=-1 && leftlca!=-1){	//	i.e. we have found both numbers
		//	printf("b!=-1 %d\n",root->d);
		return root->d;			//	most important step. here, we change the ancestor
	}
	if(leftlca==-1 && rightlca==-1){
		//	printf("b-1 %d\n",-1);
		return -1;
	}
	if(leftlca==-1){
		//	printf("l-1 %d\n",rightlca);
		return rightlca;
	}
	if(rightlca==-1){
		//	printf("r-1 %d\n",leftlca);
		return leftlca;
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	int pre[100005],in[100005];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	node*root=NULL;
	root=maketree(in,pre,n);
	//postorder(root);
	//printf("\n\n");
	//printf("dfs 5: ");
	int e,f;
	int m;
	scanf("%d",&m);
	while(m--){
		scanf("%d",&e);
		scanf("%d",&f);
		/*
		   presearch(root,e);*/
		//printf("\n");
		/*presearch(root,2);
		  printf("\n");*/
		int p=lca(root,e,f);
		printf("%d\n",p);
	}
	return 0;
}
