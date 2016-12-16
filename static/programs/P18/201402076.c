#include<stdio.h>
#include<stdlib.h>
int n,arru[1005]={0},arrd[1005]={0},vis[1005]={0};
struct node
{
	int val;
	struct node* next;
};
typedef struct node node;
struct edge
{
	int weight;
	int v1;
	int v2;
};
typedef struct edge edge;

node* insert(node* curr,int val)
{
	node* head=(node*)malloc(sizeof(node));
	head->val=val;
	head->next=curr;
	return head;
}

node* adju[1005]={NULL};
node* adjd[1005]={NULL};

void dfsd(int u)
{
	vis[u]=1;
	int i;
	node* temp=adjd[u];
	while(temp!=NULL)
	{
		if(!vis[temp->val])
			dfsd(temp->val);
		temp=temp->next;
	}
}
void dfsu(int u)
{
	vis[u]=1;
	int i;
	node* temp=adju[u];
	while(temp!=NULL)
	{
		if(!vis[temp->val])
			dfsu(temp->val);
		temp=temp->next;
	}
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int i;	
		for(i=0;i<n;i++)
		{
			vis[i]=0;
			arru[i]=0;
			arrd[i]=0;
			adju[i]=NULL;
			adjd[i]=NULL;
		}
		for(i=0;i<n;i++)
		{
			int m;
			int j;
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				int u;
				scanf("%d",&u);
				u--;
				adju[i]=insert(adju[i],u);
				arru[i]++;
				adjd[u]=insert(adjd[u],i);
				arrd[u]++;
			}
		}
		for(i=0;i<n;i++)
		{
			int j;
			for(j=0;j<n;j++)
				vis[j]=0;
			dfsd(i);
			int count=0;
			for(j=0;j<n;j++)
				if(vis[j])
					count++;
			if(count==n)
				break;			
		}
		int win=i;
		int j;
		for(j=0;j<n;j++)
			vis[j]=0;
		dfsu(i);
		int count=0;
		for(j=0;j<n;j++)
			if(vis[j])
				count++;
		printf("%d\n",count);
	}
	return 0;
}
