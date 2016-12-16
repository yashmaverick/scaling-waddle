#include<stdio.h>
#include<stdlib.h>
int n;
typedef struct link{
	int a;
	struct link*next;
}node;
node*arr2[100000];
node*point2[100000];
node*arr[100000];
node*point[100000];
int vis[100000];
int vis2[100000];
int vehla[100000];
void insert(int c,int b)
{

	node*obj=(node*)malloc(sizeof(node));
	obj->a=b;
	obj->next=NULL;
	if(arr[c]==NULL)
	{
		arr[c]=obj;
		point[c]=arr[c];
	}
	else
	{
		point[c]->next=obj;
		point[c]=point[c]->next;
	}
}
void insert2(int c,int b)
{

	node*obj=(node*)malloc(sizeof(node));
	obj->a=b;
	obj->next=NULL;
	if(arr2[c]==NULL)
	{
		arr2[c]=obj;
		point2[c]=arr2[c];
	}		      
	else
	{
		point2[c]->next=obj;
		point2[c]=point2[c]->next;
	}
}
int count=0;
void dfs(int x)
{
	vis[x]=1;
	//	printf("%d ",x);
	node*temp;
	temp=arr[x];
	while(temp!=NULL)
	{
		if(vis[temp->a]!=1)
		{
			count++;
			dfs(temp->a);
		}
		temp=temp->next;
	}
}
void dfs2(int x)
{
	vis2[x]=1;
	//      printf("%d ",x);
	node*temp;
	temp=arr2[x];
	while(temp!=NULL)
	{
		if(vis2[temp->a]!=1)
		{
			dfs2(temp->a);
		}
		temp=temp->next;
	}
}

int main()
{
	int test,num,t,fc=0,i,j,k;
	scanf("%d",&test);
	while(test--)
	{
		fc=0;
		for(i=0;i<100000;i++)
		{
			vis[i]=0;
			vis2[i]=0;
		}
		count=0;
		fc=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num);
			while(num--)	
			{
				scanf("%d",&t);
				insert(t,i);
				insert2(i,t);
			}

		}//adjacency list being made: no flaws :debbuged
		for(j=1;j<=n;j++)
		{
			for(k=0;k<=n;k++)
				vis[k]=0;
			count=0;
							
			dfs(j);
			if(count==n-1)
			{
				break;
			}
		}
		
		if(j<=n)
		{
			dfs2(j);
			for(i=0;i<100000;i++)
			{
				if(vis2[i]==1)
					fc++;
			}
		}
		printf("%d\n",fc);
		for(j=0;j<100000;j++)
		{
			arr[j]=NULL;
			arr2[j]=NULL;
			point[j]=NULL;
			point2[j]=NULL;
		}
	}
	return 0;
}


