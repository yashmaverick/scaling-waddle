#include<stdio.h>
#include<stdlib.h>
typedef struct link{
	int a;
	struct link*next;
}node;
node*arr[1000003];
node*point[1000003];
int vis[1000003];
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
int count=0;
int temp;
int maxheight=0;
int var;
void dfs(int x,int height)
{
	vis[x]=1;
	//printf("%d ",x);
	node*temp;
	temp=arr[x];
	if(height>=maxheight)
	{
		maxheight=height;
		var=x;
	}
	while(temp!=NULL)
	{
		if(vis[temp->a]!=1)
		{
			dfs(temp->a,height+1);
		}
		temp=temp->next;
	}
}
int main()
{
	int test,i,j,k,n,p,q;
	scanf("%d",&test);
	while(test--)
	{
		maxheight=0;
		scanf("%d",&n);
		k=n-1;
		while(k--)
		{
			scanf("%d%d",&p,&q);
			insert(p,q);
			insert(q,p);
		}
		dfs(1,1);//returns the deepest node
		maxheight=0;
		for(i=0;i<1000003;i++)
			vis[i]=0;
		dfs(var,1);
		printf("%d\n",maxheight);
		for(i=0;i<1000003;i++)
		{
			vis[i]=0;
			arr[i]=NULL;
			point[i]=NULL;
		}
	}
	return 0;
}


