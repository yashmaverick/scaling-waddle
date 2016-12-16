#include<stdio.h>
#include<stdlib.h>
#define X 1000000007
typedef struct node
{
	int data;
	int index;
	struct node *next;
	struct node *prev;
}node;
int top=0,b[10011];
node *head=NULL;
node *currentnode=NULL;
int top_element()
{
	return head->data;
}
void insert(int x,int i)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=x;
	temp->index=i;
	temp->prev=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
		currentnode=temp;
	}
	else
	{
		currentnode->next=temp;
		temp->prev=currentnode;
		currentnode=currentnode->next;
		node *p=currentnode;
		node *temp1;
		while(p->prev!=NULL && p->prev->data > p->data)
		{
			temp1=p->prev;
			if(temp1->prev==NULL)
			{
				head=p;
				head->prev=NULL;
			}
			else
			{
				temp1->prev->next=p;
				p->prev=temp1->prev;
			}
			free(temp1);
		}
	}
}
void pop()
{
    node *p=head;
    free(p);
	head=head->next;
	if(head!=NULL)
		head->prev=NULL;
}
int top_index()
{
	return head->index;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,n,k,x;
		scanf("%d%d",&n,&k);
		top=0;
		head=NULL;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			insert(x,i);
			if(i>=k)
			{
				b[top++]=top_element();
				if(i-top_index()>=k-1)
					pop();
			}
        }
		for(i=0;i<top-1;i++)
			printf("%d ",b[i]);
		printf("%d\n",b[i]);
	}
	return 0;
}
