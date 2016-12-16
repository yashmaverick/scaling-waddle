#include<stdio.h>
#include<stdlib.h>
typedef struct adj{
	int val;
	struct adj *next;
}adj;
int visited[1000000]={0},count=0,max=0,s;
adj *A[1000000];
void insert(int i,int a)
{
	adj *temp;
	temp=(adj*)malloc(sizeof(adj));
	temp->val=a;
	temp->next=A[i];
	A[i]=temp;
}
void dfs(int src)
{
	if(visited[src]==1)
		return ;
	visited[src]=1;
	adj *temp=A[src];
	if(temp==NULL)
		return ;
	//printf("src=%d ",src);
	if(count>max)
	{
		max=count;
		s=src;
	}
	while(temp!=NULL)
	{
		if(visited[temp->val]!=1)
		{
			count++;
			dfs(temp->val);
			count--;
		}
		temp=temp->next;
	}
}
int main()
{
	int n,t,i,j,k,B[10000],ans=0,m,v,u;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d",&n);
		if(n==0)
			printf("0\n");
		else
		{
			for(i=1;i<=n-1;i++)
			{
				scanf("%d%d",&u,&v);
				insert(u,v);
				insert(v,u);
			}
			dfs(1);
			max=0;
			count=0;
			for(i=1;i<=n;i++)
				visited[i]=0;
			//printf("\n");
			dfs(s);
			ans=ans+max;
			printf("%d\n",ans+1);
			max=0;
			count=0;
			ans=0;
			for(i=1;i<=n;i++)
				visited[i]=0;
			for(i=1;i<=n;i++)
				A[i]=NULL;
		}

	}
	return 0;
}
