#include<stdio.h>
#include<stdlib.h>
typedef struct node node;
struct node{
	int val;
	struct node* next;
};
node* adj[1010];
node* rev[1010];
int vis[1010];
int kin,count=0;
node* insert(node* head,int v)
{
	node* tmp=(node*)malloc(sizeof(node));
	tmp->val=v;
	tmp->next=head;
	return tmp;
}
void do_dfs(int v)
{
	vis[v]=1;
	node* t;
	for(t=adj[v];t!=NULL;t=t->next)
	{
		if(!vis[t->val])
		{
			count++;
			do_dfs(t->val);
		}
	}
	return;
}
void rev_dfs(int);
void clear()
{
	int i;
	for(i=0;i<kin;i++)
	{
		vis[i]=0;
	}
}
int main()
{
	int test;
	scanf("%d",&test);
	while(test--)
	{
		int i,j,k,s;
		scanf("%d",&kin);
		for(i=0;i<kin;i++)
		{
			vis[i]=0;
			adj[i]=NULL;
			rev[i]=NULL;
		}
		for(i=0;i<kin;i++)
		{
			scanf("%d",&j);
			while(j--)
			{
				scanf("%d",&k);
				k--;
				adj[k]=insert(adj[k],i);
				rev[i]=insert(rev[i],k);
			}
		}
		count=0;
		for(i=0;i<kin;i++)
		{
			clear();
			count=0;
			do_dfs(i);
//			printf("%d-->%d\n",i,count);
			if(count==kin-1)
			{
				s=i;
				break;
			}
		}
		count=0;
		clear();
//		printf("s is:%d\n",s);
		if(i!=kin)
		{
			count++;
			rev_dfs(s);
		}
		printf("%d\n",count);
	}
	return 0;
}
void rev_dfs(int v)
{
	vis[v]=1;
	node* t;
	for(t=rev[v];t!=NULL;t=t->next)
	{
		if(!vis[t->val])
		{
			count++;
			rev_dfs(t->val);
		}
	}
	return;
}
