#include<stdio.h>
#include<stdlib.h>
int pre[100100],in[100100],lol[100100],news[100100];
typedef struct node node;
struct node{
	int val;
	struct node* l;
	struct node* r;
};
int off=0;
node* maketree(int st,int end)
{
	if(st>end)
	{
		return NULL;
	}
	int i,j;
//	printf("Inserting %d\n",pre[off]);
	node* tmp=(node*)malloc(sizeof(node));
	tmp->val=pre[off++];
	tmp->l=NULL;
	tmp->r=NULL;
	if(st==end)
	{
		return tmp;
	}
	//	printf("Left From %d to  %d\n",st,lol[tmp->val]-1);
	//	tmp->l=maketree(st+1,st+lol[pre[st]]-off-1);
	tmp->l=maketree(st,lol[tmp->val]-1);
	//	printf("Right From %d to %d\n",lol[tmp->val]+1,end);
	tmp->r=maketree(lol[tmp->val]+1,end);
	//	off=lol[pre[st]];
	//	tmp->r=maketree(lol[pre[st]]+1+st,end);
	return tmp;
}
node* search(node* root,int n1,int n2)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->val==n1||root->val==n2)
	{
		return root;
	}
	node* left=search(root->l,n1,n2);
	node* right=search(root->r,n1,n2);
	if(left!=NULL&&right!=NULL)
	{
		return root;
	}
	if(left!=NULL)
	{
		return left;
	}
	else
	{
		return right;
	}
}
int main()
{
	int n,i,j,n1,n2;
	node* root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		lol[i]=0;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	/*	for(i=0;i<n;i++)
		{
		printf("%d ",lol[i]);
		} */
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		lol[in[i]]=i;
	}
	int tes,st=0;
	root=maketree(0,n-1);
	scanf("%d",&tes);
	while(tes--)
	{
		scanf("%d%d",&n1,&n2);
		node* tmp=search(root,n1,n2);
		printf("%d\n",tmp->val);
	//	search(root,n2);
	}
	return 0;
}
