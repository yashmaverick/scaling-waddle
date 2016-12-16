#include<stdio.h>
#include<stdlib.h>
typedef struct linklist
{
	int val;
	struct linklist *next;
}node;
node *ar[1000001];
int state[1000001];
int max=0,mnode=0;
void dfs(int a,int dist)
{
	if(dist>max)
	{
		max=dist;
		mnode=a;
	}
	state[a]=1;
	node *temp=ar[a];
	while(temp!=NULL)
	{
		if(state[temp->val]==0)
			dfs(temp->val,dist+1);
		temp=temp->next;
	}
	return;
}

int main()
{
	int n,m,i,a,b,j,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d",&a,&b);
			if(ar[a]==NULL)
			{
				ar[a]=(node *)malloc(sizeof(node));
				ar[a]->val=b;
				ar[a]->next=NULL;
			}
			else
			{
				node *temp=(node *)malloc(sizeof(node)),*t;
				temp->val=b;
				temp->next=ar[a];
				ar[a]=temp;
			}
			if(ar[b]==NULL)
			{
				ar[b]=(node *)malloc(sizeof(node));
				ar[b]->val=a;
				ar[b]->next=NULL;
			}
			else
			{
				node *temp2=(node *)malloc(sizeof(node));
				temp2->val=a;
				temp2->next=ar[b];
				ar[b]=temp2;
			}
		}
		state[n]=0;
		max=0;
		dfs(1,0);
		max=0;
		for(i=1;i<=n;i++)
			state[i]=0;
		dfs(mnode,0);
		printf("%d\n",max+1);
		for(i=1;i<n+1;i++)
		{
			state[i]=0;
			free(ar[i]);
			ar[i]=NULL;
		}
	}
	return 0;
}

