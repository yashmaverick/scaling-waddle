#include<stdio.h>
#include<stdlib.h>
int flag;
int count;
int flaga;
int lim;
struct linked{
	int d;
	struct linked * next;
};

typedef struct linked ELEMENT;
ELEMENT * node[1200];
ELEMENT * node1[1200];

void dfs(int u,int v)
{
	ELEMENT *head;
	head=(ELEMENT *)(malloc(sizeof(ELEMENT)));
	head->d=v;
	head->next=node[u];
	node[u]=head;
	return;
}

void DFS(int u,int v)
{
	ELEMENT *head;
	head=(ELEMENT *)(malloc(sizeof(ELEMENT)));
	head->d=v;
	head->next=node1[u];
	node1[u]=head;
	return;
}

void find(int x,int vis[])
{
	ELEMENT *tail;
	tail=node[x];
	while(tail!=NULL)
	{      


		if(vis[tail->d]!=1)
		{
			vis[tail->d]=1;
			find(tail->d,vis);
		}

		tail=tail->next;

	}

	return;
}


void func(int a1,int vis[])
{

	ELEMENT *tail;
	tail=node1[a1];
	while(tail!=NULL)
	{
		if(vis[tail->d]!=1)
		{
			vis[tail->d]=1;
			func(tail->d,vis);
		}

		tail=tail->next;
	}
	return;
}


int main()
{

	int test,q;
	scanf("%d",&test);
	for(q=0;q<test;q++)
	{
		count=0;
		flaga=0;
		int ver,edges,strong;
		int u,v,n;
		scanf("%d",&edges);
		int i,j;
		for(i=1;i<=edges;i++)
		{
			node[i]=NULL;
			node1[i]=NULL;
		}



		for(i=1;i<=edges;i++)
		{

			scanf("%d",&n);
			for(j=0;j<n;j++)
			{
				scanf("%d",&v);
				dfs(v,i);
				DFS(i,v);
			}

		}

		for(i=1;i<=edges;i++)
		{
			flag=0;
			int count1=0;
			int vis[1200]={0};
			vis[i]=1;
//			if(node[i]==NULL)
//			{
			//	count=1;
				
			//	break;
//			}
//			else
			{
				find(i,vis);

				for(j=1;j<=edges;j++)
				{ 
					if(vis[j]==1)
						count1=count1+1;
				}

				if(count1==edges)
				{
					flaga=1;
					strong=i;

					break;
				}
			}
		}
		int vis[1200]={0};
		if(flaga==1)
		{
		
			vis[strong]=1;
			func(strong,vis);
		
		}
	        count=0;
		for(j=1;j<=edges;j++)
		{
			if(vis[j]==1)
				count=count+1;
		}
		printf("%d\n",count);
	}
	return 0;
}
