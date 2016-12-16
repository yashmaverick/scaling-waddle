#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int val;
	struct node *next;
}node;
node *v[1000010];
int vis[1000010];
int len =-1,ans;
void dfs(int i,int p)
{
//	printf("%d ",i);
	vis[i]=1;
	if(p>len)
	{
		len=p;
		ans=i;
	}
	node *temp=v[i];
	while(temp!=NULL)
	{
		if(vis[temp->val]==0)
			dfs(temp->val,p+1);
		temp=temp->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			v[i]=NULL;
		for(i=1;i<n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			node *newptr=(node *)malloc(sizeof(node));
			newptr->val=y;
			newptr->next=v[x];
			v[x]=newptr;
			newptr=(node *)malloc(sizeof(node));
			newptr->val=x;
			newptr->next=v[y];
			v[y]=newptr;
		}
		len=-1;
		for(i=1;i<=n;i++)
			vis[i]=0;
		dfs(1,1);
//		printf("%d %d\n",len,ans);
		len=-1;
		for(i=1;i<=n;i++)
			vis[i]=0;
//		printf("%d",vis[6]);
		dfs(ans,1);
		printf("%d\n",len);
	}
	return 0;
}
