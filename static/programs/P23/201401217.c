#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node* next;
}node;
node* insert(node* root,int value)
{
	node* temp;
	temp=(node*)malloc(sizeof(node));
	temp->val=value;
	temp->next=NULL;
	return temp;
}
int array[100001];
int stac[100001];
node*arr[100001];
int top,count;
void dfs(int i)
{
	if(array[i]==1)
	{
		return;
	}
	node*p;
	if(array[i]!=1)
	{
		count++;
		array[i]=1;
		p=arr[i]->next;
		while(p!=NULL)
		{
			dfs(p->val);
			p=p->next;
		}
		stac[top++]=i;
	}
}
int main()
{
	int n,m,i,j,x,y;
	scanf("%d%d",&n,&m);
	node*p;
	for(i=0;i<=n;i++)
	{
		arr[i]=(node*)malloc(sizeof(node));
		arr[i]->next=NULL;
		arr[i]->val=0;
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		p=insert(arr[x]->next,y);
		p->next=arr[x]->next;
		arr[x]->next=p;

	}
	/*
	   for(i=n;i>0;i--)
	   {
	   p=arr[i]->next;
	   while(p!=NULL)
	   {
	   if(array[p->val]!=1)
	   {
	   stac[top++]=p->val;
	   array[p->val]=1;
	   }
	   p=p->next;
	   }
	   array[i]=1;
	   stac[top++]=i;
	   }*/
	for(i=n;i>0;i--)
	{
		dfs(i);
	}
	for(i=(n-1);i>0;i--)
		printf("%d ",stac[i]);
	printf("%d\n",stac[0]);
	return 0;
}
