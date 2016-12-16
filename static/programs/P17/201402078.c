#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
}node;
int in[1000001],pr[1000000],p,sp=0,n,visited[1000000]={0},stack[1000000],a,b,ans1[1000000],ans2[1000000];
node* tree(int start,int end)
{
	if (start>end)
		return NULL;
	node *temp=malloc(sizeof(node));
	temp->val=pr[p];
	temp->right=NULL;
	temp->left=NULL;
	if (start==end)
	{
		p++;
		return temp;
	}
	int k;
	for(k=start;k<=end;k++)
		if(in[k]==pr[p])
			break;
	p++;
	if(k!=start)
		temp->left=tree(start,k-1);
	if(k!=end)
		temp->right=tree(k+1,end);
	return temp;
}
void dfs(node *root)
{
	int i;
	if(root==NULL)
		return;
	stack[sp]=root->val;
	sp++;
	if(root->val==a)
		for(i=0;i<sp;i++)
			ans1[i]=stack[i];
	if(root->val==b)
		for(i=0;i<sp;i++)
			ans2[i]=stack[i];
	if(root->left!=NULL)
		dfs(root->left);
	if(root->right!=NULL)
		dfs(root->right);
	sp--;
}
int main()
{
	int i,t;
	node *root;
	p=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&pr[i]);
	for(i=0;i<n;i++)
		scanf("%d",&in[i]);
	root=tree(0,n-1);
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<n;i++)
		{
			ans1[i]=0;
			ans2[i]=0;
			stack[i]=0;
		}
		sp=0;
		scanf("%d%d",&a,&b);
		/*for(i=0;i<n;i++)
		  printf("%d ",ans1[i]);
		  printf("\n");
		  for(i=0;i<n;i++)
		  printf("%d ",ans2[i]);
		  printf("\n");*/
		if (a==b)
			printf("%d\n",a);
		else
		{
			dfs(root);
			for(i=0;i<n;i++)
			{
				if(ans1[i]!=ans2[i])
				{
					printf("%d\n",ans2[i-1]);
					break;
				}
			}
		}
	}
	return 0;
}
