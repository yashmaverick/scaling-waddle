#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int vis[100004];
struct node{
	int data;
	struct node *next;
};
struct node *arr[100004];
struct node *rev[100004];
struct node *insert(int v,struct node *root)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=v;
	temp->next=root;
	return temp;
}
void dfs(int str)
{
	vis[str]=1;
	//dist[str]=val;
	//printf("%d ",str);
	struct node *itr=arr[str];
	//printf("%d ",itr->data);
	while(itr!=NULL)
	{
		if(vis[itr->data]==0)
		{
			dfs(itr->data);
		}
		itr=itr->next;
	}
}
void dfs2(int str)
{
	vis[str]=1;
	//printf("%d ",str);
	struct node *t2=rev[str];
	while(t2!=NULL)
	{
		if(vis[t2->data]==0)
		{
			dfs2(t2->data);
		}
		t2=t2->next;
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int c2,k,n,m,i,u,v,j,c;
		for(i=0;i<100004;i++)
		{
			arr[i]=NULL;
			rev[i]=NULL;
			vis[i]=0;
		}
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v);
				arr[v]=insert(i,arr[v]);
				rev[i]=insert(v,rev[i]);
			}
		}
		
		/*scanf("%d %d",&n,&m);
		for(i=0;i<m;i++)
		{
			scanf("%d %d",&u,&v);
			arr[u]=insert(v,arr[u]);
			rev[v]=insert(u,arr[v]);
		}*/
		/*for(i=1;i<=n;i++)
		  {
		  printf("%d:",i);
		  print(arr[i]);
		  }*/
		c=0;
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			dfs(i);
	//		printf("\n");
			c=0;
			for(j=1;j<=n;j++)
			{
	//			printf("%d--",vis[j]);
				if(vis[j]==1)
				{
					c++;
				}
				
			}
	//		printf("\n");
			if(c==n){
				k=i;
				break;
			}

		}
		//printf("%d",k);
	//	printf("\n");
		memset(vis,0,sizeof(vis));
		dfs2(k);
		c2=0;
		for(i=1;i<=n;i++)
		{
			if(vis[i]==1)
				c2++;
		}
		if(n==1)
			printf("1\n");
		else
		printf("%d\n",c2);
	}

	return 0;
}


