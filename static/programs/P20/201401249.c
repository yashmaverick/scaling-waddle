#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node *next;
}node;
node *head[1000001];
int vis[1000001];
int str,ans;
void create(int l,int m)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->val=m;
	if(head[l]!=NULL)
	{
		temp->next=NULL;
		temp->next=head[l];
		head[l]=temp;
		return ;
	}
	head[l]=temp;
	return;
}
void dfs(int k,int cont)
{
	if(head==NULL || vis[k]==1)
		return ;
	if(cont>ans)
		ans=cont;
	vis[k]=1;
	str=k;
	node *temp=head[k];
	while(temp!=NULL)
	{
		if(vis[temp->val]!=1)
			dfs(temp->val,cont+1);
		temp=temp->next;
	}
	return ;
}
int main()
{
	int i,j,k,l,m,n,e,v;
	scanf("%d",&e);
	while(e--)
	{
		scanf("%d",&v);
		v++;
		j=1;
		while(j!=v)
		{
			head[j]=NULL;
			j++;
		}
		v=v-2;
		j=0;
		while(j!=v)
		{
			scanf("%d %d",&l,&m);
			create(l,m);
			create(m,l);
			j++;
		}
		node *temp;
		v++;
		str=0;
		ans=0;
		for(i=1;i<=v;i++)
		{
			vis[i]=0;
		}
		dfs(1,0);
		for(i=1;i<=v;i++)
		{
			vis[i]=0;
		}
		ans=0;
		dfs(str,1);
		printf("%d",ans);
		printf("\n");
	}
	return 0;
}








































































































































































