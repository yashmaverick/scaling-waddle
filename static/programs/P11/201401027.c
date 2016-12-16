#include<stdio.h>
#include<stdlib.h>
long long int n,arr[3][300000];
typedef struct stack
{
	long long int data;
	struct stack *next;
}stack;
stack *head;
void push(long long int val)
{
	stack* node=(stack*)malloc(sizeof(stack));
	node->data=val;
	node->next=head;
	head=node;
	return;
}
void pop()
{
	stack *node=head;
	head=head->next;
	free(node);
	return;
}
int main()
{
	long long int i,max,t;
	scanf("%lld",&n);
	while(n)
	{
		arr[0][0]=arr[1][0]=0;
		arr[2][n+1]=n+1;
		for(i=1;i<=n;i++)
			scanf("%lld",&arr[0][i]);
		push(0);
		for(i=1;i<=n;i++)
		{
			while(head!=NULL && arr[0][i]<=arr[0][head->data])
				pop();
			if(head==NULL)
				push(0);
			push(i);
			if(head->next==NULL)
				arr[1][i]=0;
			else
				arr[1][i]=(head->next)->data;
		}
		while(head!=NULL)
			pop();
		for(i=n;i>0;i--)
		{
			while(head!=NULL && arr[0][i]<=arr[0][head->data])
				pop();
			if(head==NULL)
				push(n+1);
			push(i);
			if(head->next==NULL)
				arr[2][i]=n+1;
			else
				arr[2][i]=(head->next)->data;
		}
		while(head!=NULL)
			pop();
		max=0;
		for(i=1;i<=n;i++)
		{
			t=(arr[0][i])*(arr[2][i]-arr[1][i]-1);
			if(t>max)
				max=t;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
