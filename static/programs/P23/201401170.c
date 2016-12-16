#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int val;
	struct node*next;
}node;
node*a[1000009];
long long int stack[1000009],visited[1000009],top=-1;
node*insert(node*head,long long int data)
{
	node*temp=(node*)malloc(sizeof(node));
	temp->val=data;
	temp->next=head->next;
	head->next=temp;
	return head;
}
void dfs(long long int x)
{
	node*temp=a[x];
	visited[x]=1;
	if(temp!=NULL)
		temp=temp->next;
	while(temp!=NULL)
	{
		if(!visited[temp->val])
		{
			dfs(temp->val);
		}
		temp=temp->next;
	}
	stack[++top]=x;
	return;
}
int main()
{
	long long int n,m,i,j,x,y;
	scanf("%lld%lld",&n,&m);
	j=m;
	for(i=1;i<=n;i++)
	{
		a[i]=(node*)malloc(sizeof(node));
		a[i]->val=i;
		a[i]->next=NULL;
		visited[i]=0;
	}
	while(j--)
	{
		scanf("%lld%lld",&x,&y);
		a[x]=insert(a[x],y);
	}
	for(i=n;i>=1;i--)
	{
		if(visited[i]==0)
			dfs(i);
	}
	while(top)
	{
		printf("%lld ",stack[top]);
		top--;
	}
	printf("%lld\n",stack[top]);
	return 0;
}
