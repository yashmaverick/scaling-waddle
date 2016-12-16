#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int v;
	struct node* next;
}node;
node* A[10000];
node* Arev[10000];
void insert(int x, int y,node* B[])
{
	node* new=(node*)malloc(sizeof(node));
	new->v=y;
	if(B[x]==NULL)
	{
		new->next=NULL;
		B[x]=new;
	}
	else
	{
		new->next=B[x];
		B[x]=new;
	}
}
int visit[10000],dvisit[10000],flag,count;
void dfs(int i,int n,node* B[])
{
	visit[i]=1;
	dvisit[i]=1;
	count++;
	if(count==n)
		flag=1;
	node* p=B[i];
	while(p!=NULL)
	{
		if(dvisit[p->v]==0)
			dfs(p->v,n,B);
		p=p->next;
	}
}	
int main()
{
	int t,n,m,x,y,i,j,sv;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);count=0;flag=0;
		memset(visit,0,sizeof(int)*1001);
		for(i=0;i<=n;i++)
		{
			A[i]=NULL;
			Arev[i]=NULL;
		}	
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{	
				scanf("%d",&x);
				insert(x,i,A);
				insert(i,x,Arev);
			}
		}
		for(i=1;i<=n;i++)
		{
			if(visit[i]==0)
			{	
				memset(dvisit,0,sizeof(int)*1001);
				count=0;//printf("inside\n");
				flag=0;
				dfs(i,n,A);
			}	
			if(flag==1)
			{	
				sv=i;
				break;
			}	
		}
		//printf("sv=%d\n",sv);
		count=0;
		if(sv>0)
		{
			memset(dvisit,0,sizeof(int)*1001);
			dfs(sv,n,Arev);
		}	
		printf("%d\n",count);
	}
	return 0;
}	

