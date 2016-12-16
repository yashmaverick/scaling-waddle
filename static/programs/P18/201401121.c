#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int vis[50001];
int ans=0;
typedef struct node
{
	int data;
	struct node *next;
}node;
node *a[50001];
node *b[50001];
void addedge1(int i,int j)
{
	node *temp=malloc(sizeof(node));
	temp->data=j;
	temp->next=a[i];
	a[i]=temp;
}
void addedge2(int i,int j)
{
	node *temp=malloc(sizeof(node));
	temp->data=j;
	temp->next=b[i];
	b[i]=temp;
}
void dfs(int i,int n)
{
	vis[i]=1;
	node *temp=a[i];
	while(temp!=NULL)
	{
		if(!vis[temp->data])
			dfs(temp->data,n);
		temp=temp->next;
	}
}
void dfs2(int i,int n)
{

	vis[i]=1;
	ans++;
	node *temp=b[i];
	while(temp!=NULL)
	{

		if(!vis[temp->data])
			dfs2(temp->data,n);
		temp=temp->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			int m;
			scanf("%d",&m);
			while(m--)
			{
				int in;
				scanf("%d",&in);
				addedge1(in,i+1);
				addedge2(i+1,in);
			}
			
		}
		i=1;
		ans=0;
		int win;
		int flag;
		while(i<=n)
		{
		
			win=i;
		
			dfs(i,n);
			flag=0;
			int j;
			for(j=1;j<=n;j++)
			{
				if(vis[j]==0)
				{
					flag=1;
					break;
				}
			}
			for(j=1;j<=n;j++)
				vis[j]=0;
			
			if(flag==0)
				break;
			i++;
		}
		if(flag==1)
			printf("0\n");
		else
		{
			dfs2(win,n);
			printf("%d\n",ans);
		}

		for(i=1;i<=n;i++)
			vis[i]=0;
		for(i=1;i<=n;i++)
		{
			a[i]=NULL;
			b[i]=NULL;
		}
	}
	return 0;
}



			

