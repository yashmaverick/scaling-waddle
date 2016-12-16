#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
int max,visited[1000010];
node* a[1000010];
void insert(int x,int y)
{
	node* temp=NULL;
	node* new1=malloc(sizeof(node));
	new1->val=y;
	new1->next=NULL;
	if(a[x]==NULL)
		a[x]=new1;
	else
	{
		temp=a[x]->next;
		new1->next=temp;
		a[x]->next=new1;
	}
	node* new2=malloc(sizeof(node));
	new2->val=x;
	new2->next=NULL;
	if(a[y]==NULL)
		a[y]=new2;
	else
	{
		temp=a[y]->next;
		new2->next=temp;
		a[y]->next=new2;
	}

}
int pq,max,flag;
void dfs(int u,int d)
{
	visited[u]=1;
	node* temp=a[u];
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
		{
			dfs(temp->val,d+1);
		}
		if(d>max)
		{
			pq=u;
			max=d;
		}
		temp=temp->next;
	}
	return;
}
int main()
{
	int t,n,i,u,v;
	node* temp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			a[i]=NULL;
		for(i=1;i<=n;i++)
			visited[i]=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&u,&v);
			insert(u,v);
		}

		max=0;
		dfs(1,0);
		max=0;
		for(i=1;i<=n;i++)
			visited[i]=0;
		//		printf("pq=%d\n",pq);
		dfs(pq,0);
		printf("%d\n",max+1);
	}
	return 0;
}


