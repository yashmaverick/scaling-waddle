#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct tree
{
	int value;
	struct tree *next;
}tree;

typedef struct node
{
	int value;
	struct node* next;
}node;

node *head,*tail;

void queue_push(int val)
{
	node *x;
	x=(node *)malloc(sizeof(node));
	x->value=val;
	x->next=NULL;
	if(head==NULL && tail==NULL)
		head=tail=x;
	else
	{
		tail->next=x;
		tail=tail->next;
	}
}

int queue_pop()
{
	int z;
	if(head==NULL)
	{
		return 0;
	}
	if(head->next==NULL)
	{
		z=head->value;
		tail=head=NULL;
		return z;
	}
	node *temp;
	temp=head;
	head=head->next;
	z=temp->value;
	return z;
}
tree *D[1000001];

/*int end=0,front=0,c=0;
  int A[1000001];

  void queue_push(int a)
  {
  A[end]=a;
  if(end==1)
  {
  front=1;
  }
  end++;
  }

  int queue_pop()
  {
  if(front==end && front==0)
  {
  return 0;
  }
  int a=A[front];
  A[c++]=-1111111111;
  front++;
  return a;
  }*/

int s=1,vis[1000001],height[1000001],inside[1000001];
int nmax=0,nmaxi;

int bfs(int parenth)
{
	tree *temp;
	queue_push(parenth);
	height[parenth]=0;
	inside[parenth]=1;
	while(1)
	{
		int d=queue_pop();
		if(d==0)
			break;
		vis[d]=1;
		temp=D[d];
		while(temp!=NULL)
		{
			if(inside[temp->value]!=1 && vis[temp->value]==0)				
			{
				queue_push(temp->value);
				inside[temp->value]=1;
				vis[temp->value]=1;
				height[temp->value]=height[d]+1;
				if(height[temp->value]>nmax)
				{
					nmax=height[temp->value];
					nmaxi=temp->value;
				}
			}
			temp=temp->next;
		}
	}
	return nmaxi;
}

int main()
{
	int val,val1,x,n,i,a,b;
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			height[i]=0;
			D[i]=NULL;
			vis[i]=0;
			inside[i]=0;
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%d %d",&a,&b);
			tree *x=(tree *)malloc(sizeof(tree));
			tree *y=(tree *)malloc(sizeof(tree));
			x->value=b;
			x->next=D[a];
			D[a]=x;
			y->value=a;
			y->next=D[b];
			D[b]=y;
		}
		val=bfs(s);
		for(i=1;i<=n;i++)
		{
			height[i]=0;
			vis[i]=0;
			inside[i]=0;
		}
		head=tail=NULL;
		val1=bfs(val);
		printf("%d\n",nmax+1);
		nmax=0;
	}
	return 0;
}
