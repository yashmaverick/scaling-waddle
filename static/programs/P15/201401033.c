#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long int val;
	struct node* next;
}node;
node* head=NULL;

void push(long long int x)
{
	node *temp=malloc(sizeof(node));
	temp->val=x;
	temp->next=NULL;
	if(head==NULL)
		head=temp;
	else
	{
		node* p=head;
		while(p->next!=NULL)
			p=p->next;
		p->next=temp;
	}
	return;
}

void pop()
{
	if(head!=NULL)
		head=head->next;
	return;
}

long long int top()
{
	if(head!=NULL)
		return head->val;
	return -1;
}
/*void del()
{
	struct node *temp =head;
	struct node *t;
	while(temp->next != NULL)
	{
		t=temp;
		temp=temp->next;
	}
	//free(t->next);
	t->next=NULL; 
}  */
void del()
{
	struct node *temp =head;
	struct node *t;
	if(head->next==NULL)
	{
		free(head);
		head=NULL;
	}
	else
	{
		while(temp->next != NULL)
		{
			t=temp;
			temp=temp->next;
		}
		free(t->next);
		t->next=NULL; 
	}    
}
long long int end()
{
	node* temp=head;
	if(head==NULL)
		return -1;
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		return temp->val;
	}
}

int main()
{
	long long int tc,n,i,x,k;
	scanf("%lld",&tc);
	while(tc--)
	{
		scanf("%lld%lld",&n,&k);
		long long int A[n];
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		//	for(i=0;i<n;i++)
		//		printf("%lld ",A[i]);
		//	printf("\n");
		for(i=0;i<n;i++)
		{
			x=end();
			if(x==-1 || A[i]>=x)
				push(A[i]);
			else
			{
				while(x!=-1 && A[i]<x)
				{
					del();
					x=end();
				}
				push(A[i]);
			}
			if(i>=k && top()==A[i-k])
			{
				pop();
			}
			if(i!=n-1 && i>=k-1)
			{
				printf("%lld ",top());
			}
			if(i==n-1)
				printf("%lld",top());

		}
		printf("\n");
		while(head!=NULL)
			pop();
	}
	return 0;
}
