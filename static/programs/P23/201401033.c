#include<stdio.h>
#include<stdlib.h>
#define MAX 500009
typedef struct node
{
	int val;
	struct node* next;
}node;
node* A[MAX];
int check[MAX]={0},array[MAX];
node* insert(node* head,int val)
{
	node* temp=malloc(sizeof(node));
	temp->val=val;
	temp->next=head;
	return temp;
}
int size=0;
void dfs(int x)
{
	node* temp=A[x];
	check[x]=1;
	while(temp!=NULL)
	{
		if(check[temp->val]==0)
		{
			dfs(temp->val);
			array[size++]=temp->val;
		}
		temp=temp->next;
	}
	array[size++]=x;
}
int main()
{
	int n,m,i,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		A[x]=insert(A[x],y);
	}
	for(i=n;i>=1;i--)
	{
		if(check[i]==0)
			dfs(i);
	}
	for(i=size-1;i>0;i--)
	{
		if(array[i]!=array[i-1])
		printf("%d ",array[i]);
	}
	printf("%d\n",array[0]);
	return 0;
}
