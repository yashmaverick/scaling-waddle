#include<stdio.h>
#include<stdlib.h>
int a[100005];
int b[100005];
int ind[100005];
int level[100005];
int par[100005];
typedef struct node
{
	struct node *l;
	struct node *r;
	int data;

}node;
node *st[100005];
void preorder(node *head)
{
	if(head==NULL)
		return ;
	printf("%d ",head->data);
	preorder(head->l);
	preorder(head->r);
}
int main()
{
	int no;
	scanf("%d",&no);
	int i=0;
	for(i=0;i<no;i++)
		scanf("%d",&a[i]);
	for(i=0;i<no;i++)
	{
		scanf("%d",&b[i]);
		ind[b[i]]=i;
	}
	node *head;
	head=malloc(sizeof(node));
	head->data=a[0];
	level[head->data]=0;
	par[head->data]=-1;
	head->l=NULL;
	head->r=NULL;
	node *temp=head;
	int top=-1;
	for(i=1;i<no;i++)
	{
		if(ind[a[i]] <  ind[a[i-1]])
		{
			top++;
			st[top]=temp;
			temp->l=malloc(sizeof(node));
			temp->l->data=a[i];
			level[temp->l->data]=level[temp->data]+1;
			par[temp->l->data]=temp->data;
			temp->l->l=NULL;
			temp->l->r=NULL;
			temp=temp->l;
		}
		else
		{
			if(top==-1 || ind[st[top]->data] > ind[a[i]])
			{

				temp->r=malloc(sizeof(node));
				temp->r->data=a[i];
				temp->r->l=NULL;
				temp->r->r=NULL;
				level[temp->r->data]=level[temp->data]+1;
				par[temp->r->data]=temp->data;
				temp=temp->r;
			}
			else
			{

				while(ind[st[top]->data] < ind[a[i]] )
				{
					top--;
					if(top==-1)
						break;
				}
				st[top+1]->r=malloc(sizeof(node));
				st[top+1]->r->data=a[i];
				st[top+1]->r->r=NULL;
				st[top+1]->r->l=NULL;
				level[st[top+1]->r->data]=level[st[top+1]->data]+1;
				par[st[top+1]->r->data]=st[top+1]->data;
				temp=st[top+1]->r;
			}
		}
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		while(level[x]>level[y])
		{   
			x=par[x];
		}   
		while(level[x]<level[y])
		{   
			y=par[y];
		}   
		while(x!=y)
		{   
			x=par[x];
			y=par[y];
		}   
		printf("%d\n",x);
	}
	return 0;

}
































