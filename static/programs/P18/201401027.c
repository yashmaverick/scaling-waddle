#include<stdio.h>
#include<stdlib.h>
int vis[1003];
typedef struct graph
{
	int opp;
	struct graph *next;
}graph;
graph *head[1003],*tail[1003];
void dfs(int a)
{
	graph *k;
	if(!vis[a])
	{
		vis[a]=1;
		for(k=head[a];k!=NULL;k=k->next)
			dfs(k->opp);
	}
	return;
}
void revdfs(int a)
{
	graph *k;
	if(!vis[a])
	{
		vis[a]=1;
		for(k=tail[a];k!=NULL;k=k->next)
			revdfs(k->opp);
	}
	return;
}
int main()
{
	int tc,i,teams,j,nopp,k,opp,win,ans,state;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		ans=0;
		state=0;
		scanf("%d",&teams);
		for(j=1;j<=teams;j++)
		{
			head[j]=NULL;
			tail[j]=NULL;
		}
		for(j=1;j<=teams;j++)
		{
			scanf("%d",&nopp);
			for(k=0;k<nopp;k++)
			{
				scanf("%d",&opp);
				graph *node=(graph*)malloc(sizeof(graph));
				node->opp=j;
				node->next=head[opp];
				head[opp]=node;
				graph *node2=(graph*)malloc(sizeof(graph));
				node2->opp=opp;
				node2->next=tail[j];
				tail[j]=node2;
			}
		}
		win=0;
		while(!state && win<teams)
		{
			win++;
			for(j=1;j<=teams;j++)
				vis[j]=0;
			dfs(win);
			for(j=1;j<=teams && vis[j]==1;j++);
			if(j==teams+1)
				state=1;
		}
		if(state==0)
			printf("0\n");
		else
		{
			for(j=1;j<=teams;j++)
				vis[j]=0;
			revdfs(win);
			for(j=1;j<=teams;j++)
				if(vis[j])
					ans++;
			printf("%d\n",ans);
		}
	}
	return 0;
}
