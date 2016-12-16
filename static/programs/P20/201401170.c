#include<stdio.h>
#include<stdlib.h>
int visited[1000007],n,maxdepth,element;
typedef struct node
{
	int val;
	struct node*next;
}node;
node*a[1000008];
node*insert(node*head,int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->val=data;
	temp->next=NULL;
	node*x;
	x=head->next;
	head->next=temp;
	temp->next=x;
	return head;
}
void dfs(node*head,int depth)
{
	if(head==NULL)
		return;
	node*start=head;
	if(depth>maxdepth)
	{
		maxdepth=depth;
		element=head->val;
	}
	visited[head->val]=1;
	head=head->next;
	while(head!=NULL)
	{	
		if(!visited[head->val])
			dfs(a[head->val],depth+1);
		head=head->next;
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,depth;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			a[i]=(node*)malloc(sizeof(node));
			a[i]->val=i;
			a[i]->next==NULL;
		}
		for(i=0;i<n-1;i++)
		{
			int m,n;
			scanf("%d%d",&m,&n);
			a[m]=insert(a[m],n);
			a[n]=insert(a[n],m);
		}
		for(i=1;i<=n;i++)
		{
			visited[i]=0;
		}
		maxdepth=depth=0;
		element=1;
		dfs(a[1],depth);
		for(i=1;i<=n;i++)
			visited[i]=0;
		maxdepth=depth=0;
		dfs(a[element],depth);
		printf("%d\n",maxdepth+1);
	}
	return 0;
}
