#include<stdio.h>
#include<stdlib.h>
struct node
{
	int val;
	struct node* next;
};
int max=0,vis[1000000],printed,n,stak[1000000],start=0;
typedef struct node node;
node *tree[1000000];
void dfs(int x)
{
	node *tempo;
	tempo=tree[x];
	while(tempo!=NULL)
	{
		if(vis[tempo->val]==0)
		{
			vis[tempo->val]=1;
			dfs(tempo->val);
		}
		tempo=tempo->next;
	}
	stak[start++]=x;
	return;
}
int main()
{
	int m,i,j,k,count,temp,temp1;
	node *trash,*trash1;	
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		tree[i]=NULL;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&temp,&temp1);
		trash=malloc(sizeof(node));
		trash->val=temp1;
		trash->next=tree[temp];
		tree[temp]=trash;
		/*trash1=malloc(sizeof(node));
		  trash1->val=temp;
		  trash1->next=tree[temp1];
		  tree[temp1]=trash1;*/
	}
	for(i=0;i<=n;i++)
	{
		vis[i]=0;
	}
	max=0;
	for(i=n;i>0;i--){
		if(vis[i]==0){
			vis[i]=1;
			dfs(i);
		}
	}
	start--;
	while(start>=0){
		printf("%d",stak[start--]);
		if(start<0)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}
