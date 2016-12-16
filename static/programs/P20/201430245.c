#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
int max=0,vis[1000001];
typedef struct node node;
node *tree[1000001];
int found;
void dfs(node *x,int count,int val)
{
	node *tempo;
	tempo=x;
	if(count>max)
	{
		max=count;
		found=val;
	}
	while(tempo!=NULL)
	{
		if(vis[tempo->val]==0)
		{
			vis[tempo->val]=1;
			dfs(tree[tempo->val],1+count,tempo->val);
		}
		tempo=tempo->next;
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j,k,count,temp,temp1;
		node *trash,*trash1;	
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			tree[i]=NULL;
		}
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&temp,&temp1);
			trash=malloc(sizeof(node));
			trash->val=temp1;
			trash->next=NULL;
			if(tree[temp]==NULL)
			{
				tree[temp]=trash;
			}
			else
			{
				trash->next=tree[temp];
				tree[temp]=trash;
			}
			trash1=malloc(sizeof(node));
			trash1->val=temp;
			trash1->next=NULL;
			if(tree[temp1]==NULL)
			{
				tree[temp1]=trash1;
			}
			else
			{
				trash1->next=tree[temp1];
				tree[temp1]=trash1;
			}
		}
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		max=-1;
		vis[1]=1;
		dfs(tree[1],0,1);
		max=-1;
		for(i=1;i<=n;i++)
		{
			vis[i]=0;
		}
		vis[found]=1;
		dfs(tree[found],0,found);
		printf("%d\n",max+1);
	}
	return 0;
}
