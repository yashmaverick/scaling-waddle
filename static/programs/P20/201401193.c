#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node* next;
};
typedef struct node node;
int dr,ans;
node* makenode(int n)
{
	node* t;
	t=malloc(sizeof(node));
	t->val=n;
	t->next=NULL;
	return t;
}
void insert(int x,int y,node* head[])
{
	node* t;
	t=makenode(x);
	t->next=head[y];
	head[y]=t;
	t=makenode(y);
	t->next=head[x];
	head[x]=t;
	return;
}
void deep(int k,int dep,node* head[],int p)
{
	node* t=head[k];
	if(dep>ans)
	{
		ans=dep;
		dr=k;
	}
	while(t!=NULL)
	{
		if(t->val!=p)
			deep(t->val,dep+1,head,k);
		t=t->next;
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		int n,i,x,y,max=0;
		node* head[1000000]={NULL};
		scanf("%d",&n);
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&x,&y);
			x--;
			y--;
			insert(x,y,head);
		}
		deep(0,1,head,n);
		ans=0;
		deep(dr,1,head,n);
		printf("%d\n",ans);
	}
	return 0;
}
