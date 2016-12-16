#include<stdio.h>
#include<stdlib.h>
long long int i,size,precnt,sum;
long long int n,arr[500100];
typedef struct stack
{
	long long int data;
	struct stack *next;
}stack;
stack *head=NULL;
void push(long long int val)
{
	stack* node=(stack*)malloc(sizeof(stack));
	node->data=val;
	node->next=head;
	head=node;
	size++;
	return;
}
void pop()
{
	stack *node=head;
	head=head->next;
	free(node);
	size--;
	return;
}
int main()
{
	scanf("%lld",&n);
	while(n)
	{
		sum=0;size=-1;
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		push(0);
		for(i=1;i<n;i++)
		{
			precnt=1;	
			if(head!=NULL && arr[i]<=arr[head->data])
			{
				push(i);
			}
			else
			{	
				while( size>=0 && arr[head->data]<arr[i]) 
				{
					if(size>1 && arr[head->next->data]!=arr[head->data])
					{
						sum+=precnt*(size-1);
						precnt=1;
					}
					else
						precnt++;
					sum+=n-i-1;
					pop();
				}
				push(i);
			}
		}
		precnt=1;
		while(head!=NULL && head->next!=NULL)
		{
			if(arr[head->next->data]!=arr[head->data])
			{
				sum+=precnt*(size-1);
				precnt=1;
			}
			else precnt++;
			pop();
		}
		pop();
		printf("%lld\n",sum);
		scanf("%lld",&n);
	}
	return 0;
}
