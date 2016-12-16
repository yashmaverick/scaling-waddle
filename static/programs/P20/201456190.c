#include<stdio.h>
#include<stdlib.h>
#define MAX 1000005
int flag;

int queue[MAX];
int qcount[MAX];
int start;
int end;
int ind;
int ans;
struct linked{
	int d;
	struct linked * next;
};

typedef struct linked ELEMENT;
ELEMENT * node[MAX];


void dfs(int u,int v)
{
	ELEMENT *head;
	head=(ELEMENT *)(malloc(sizeof(ELEMENT)));
	head->d=v;
	head->next=node[u];
	node[u]=head;
	return;
}



void find(int a1,int vis[],int count)
{

	ELEMENT *tail;
	tail=node[a1];
	while(tail!=NULL)
	{

		if(vis[tail->d]!=1)
		{
			vis[tail->d]=1;
			queue[end]=tail->d;
			qcount[end]=count+1;
			end=end+1;	
		}
		tail=tail->next;
	}
	if(start==end)
	{
		ind=queue[start-1];
		ans=qcount[start-1];
		return;
	}
	int x,y;
	x=queue[start];
	y=qcount[start];
	start=start+1;
	find(x,vis,y);
	return;
}


int main()
{

	int test,q;
	scanf("%d",&test);
	for(q=0;q<test;q++)
	{
		int ver,edges;
		int u,v,n;
		scanf("%d",&edges);
		int i,j;
		
		for(i=1;i<=edges;i++)
		{
			node[i]=NULL;
		}
		for(j=1;j<=edges-1;j++)
		{

			scanf("%d %d",&u,&v);
			dfs(u,v);
			dfs(v,u);

		}

		int vis[MAX]={0};
		vis[1]=1;	
                start=0;
		end=0;
		ans=0;
		find(1,vis,0);
		for(j=1;j<=edges;j++)
			vis[j]=0;
		vis[ind]=1;
		start=0;
		end=0;
                ans=0;
		find(ind,vis,0);
		if(edges==0)
			printf("0\n");
		else
                printf("%d\n",ans+1);



	}
	return 0;
}
