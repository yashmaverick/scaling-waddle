#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int val;
	struct node*left;
	struct node*right;
}node;
node *head;
node*q;
node* ances(node*w,int e,int r)
{
	if(w==NULL)
		return w;
	if(w->val==e||w->val==r)
		return w;
	node*lef=NULL;
	node*righ=NULL;
	lef=ances(w->left,e,r);
	righ=ances(w->right,e,r);
	if(lef&&righ)
		return w;
	return (lef!=NULL)? lef:righ;
}
void insert(int a,int *arr)
{
	node*p;
	p=head;
	int flag,i;
	while(1)
	{
		for(i=0;;i++)
		{
			if(arr[i]==p->val)
				break;
		}
		for(;i>=0;i--)
		{
			if(arr[i]==a)
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if(flag)
		{
			if(p->left==NULL)
			{
				q=(node*)malloc(sizeof(node));
				q->val=a;
				q->left=NULL;
				q->right=NULL;
				p->left=q;
				break;
			}
			p=p->left;
		}
		else
		{
			if(p->right==NULL)
			{
				q=(node*)malloc(sizeof(node));
				q->val=a;
				q->right=NULL;
				q->right=NULL;
				p->right=q;
				break;
			}
			p=p->right;
		}
	}
}
int main()
{
	int i,j,n,y,z;
	scanf("%d",&n);
	int in[n],pre[n];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
	}
	head=(node*)malloc(sizeof(node));
	head->val=pre[0];
	head->left=NULL;
	head->right=NULL;
	for(i=1;i<n;i++)
		insert(pre[i],in);
	node* x;
	int t;
	/*x=head;
	  inprint(head);
	  printf("\n");*/
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&y);
		scanf("%d",&z);
		x=ances(head,y,z);
		printf("%d\n",x->val);
	}
	return 0;
}
