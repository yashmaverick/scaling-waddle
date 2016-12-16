#include<stdio.h>
#include<stdlib.h>
typedef struct ll{
	int data;
	struct ll* nxt;
}link;
typedef link* list;
int max;int gp;
void adjins(list po[],int u,int v)
{
	list tenp,aga;
	tenp=(list)malloc(sizeof(link));
	tenp->data=v;
	tenp->nxt=po[u];
	po[u]=tenp;

	aga=(list)malloc(sizeof(link));
	aga->data=u;
	aga->nxt=po[v];
	po[v]=aga;
	return;
}
void dfs(list po[],int str,int cnt,int b[])
{
	list temp;
	temp=po[str];
	b[str]=1;
	//printf("count is %d and max is %d\n",cnt,max);
	if(cnt>=max)
	{
		max=cnt;gp=str;
	}
	if(po[str]==NULL)
	{
		return;
	}
	else
	{
		while(temp!=NULL)
		{
			if(b[temp->data]==0)
			{
		//		printf("calling for %d\n",temp->data);
		//	printf("count is %d\n",cnt);
				dfs(po,temp->data,cnt+1,b);
			}
			else
			{
				temp=temp->nxt;
			}
		}
	}
}
int main()
{
	int t,n,i,j,k,l,p,u,v;
	scanf("%d",&t);
	while(t>0)
	{
		max=0;gp=1;
		scanf("%d",&n);
		list po[n+1];int b[n+1];
		for(i=0;i<=n;i++)
		{
			b[i]=0;
			po[i]=NULL;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&u,&v);
			adjins(po,u,v);
		}
		dfs(po,1,0,b);
		//printf("pointer at %d\n",gp);
		//printf("max is %d\n",max);
		for(i=0;i<=n;i++)
		{
			b[i]=0;
		}
		max=0;
		dfs(po,gp,0,b);
		printf("%d\n",max+1);
		t--;
	}
	return 0;
}
