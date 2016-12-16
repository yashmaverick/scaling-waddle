#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}node;
int f,x,y,z,b[1000002],max_z;
void dfs(struct node* a[1000002],int k)
{
	int h;
	if(max_z<z)
	{
		max_z=z;															
		x=k;
	}
	struct node *head;
	struct node *temp;
	head=a[k];
	b[k]=1;
	if(head!=NULL)
	{
		z=z+1;
		h=z;
		while(head!=NULL)
		{
			z=h;
			y=head->data;
			if(b[y]==0)
			{
				f=y;
				dfs(a,y);
			}
			head=head->next;
		}
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n,k,j,p,q;
		scanf("%d",&n);
		struct node *a[1000002];
		int c[n+1];
		struct node *head;
		for(j=1;j<n+1;j++)
		{
			c[j]=0;
			a[j]=(struct node *)malloc(sizeof(struct node));
			a[j]->next=NULL;
		}
		for(j=1;j<=n-1;j++)
		{
			scanf("%d%d",&p,&q);
			head=(struct node *)malloc(sizeof(struct node));
			head->next=NULL;
			if(c[p]!=0)
			{
				head->data=a[p]->data;
				head->next=a[p]->next;
				a[p]->next=head;
				a[p]->data=q;
			}
			else
			{
				a[p]->data=q;
				c[p]++;
			}
			if(c[q]!=0)
			{
				head->data=a[q]->data;
				head->next=a[q]->next;
				a[q]->next=head;
				a[q]->data=p;
			}
			else
			{
				a[q]->data=p;
				c[q]++;
			}
		}
		for(j=1;j<=1000002;j++)
			b[j]=0;
		max_z=z=0;
		dfs(a,1);
		for(j=1;j<=1000002;j++)
			b[j]=0;
		max_z=z=0;
		dfs(a,x);
		printf("%d\n",max_z+1);
	}
	return 0;
}
