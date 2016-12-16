#include<stdio.h>
#include<stdlib.h>

struct stack
{
	long long int data;
	long long int count;
	struct stack *next;
};
typedef struct stack stack;

long long int top(stack *head)
{
	return head->data;
}


struct stack* push(stack *top,long long int k)
{
	stack *temp=(stack*)malloc(sizeof(stack));
	temp->data=k;
	temp->count=1;
	temp->next=top;

	return temp;
}
stack* pop(stack *top)
{
	top=top->next;
	return top;
}


int main()
{
	long long int n;
	scanf("%lld",&n);
	while(1)
	{
		long long int arr[n],i;
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		long long int big1=arr[0];
		long long int big2=arr[n-1];
		long long int fin=0;
		for(i=1;i<n;i++)
		{
			if(arr[i]>=big1)
				big1=arr[i];
			else
				fin++;
			if(arr[n-i-1]>=big2)
				big2=arr[n-i-1];
			else
				fin++;
		}
//		printf("ddd%dddd\n",fin);
		stack *head=NULL;
		long long int flag=0;
		head=push(head,arr[0]);
		for(i=1;i<n;i++)
		{
//			printf("###%d##\n",top(head));
			if(top(head)<arr[i])
			{
				while(top(head)<arr[i])
				{
					head=pop(head);
					if(head==NULL)
					{
						flag=1;
						head=push(head,arr[i]);
						break;
					}
				}
				if(top(head)==arr[i]&&flag==0)
				{
					fin=fin+head->count;
					head->count=(head->count)+1;

				}
				else
				{	
					if(flag==0)
						head=push(head,arr[i]);
				}
			}
			else if(top(head)==arr[i]&&flag!=1)
			{
//				printf("xx%dxx\n",fin);
				fin=fin+(head->count);
				head->count=head->count+1;
//				printf("**%d**\n",fin);
			}
			else
				if(flag==0)
					head=push(head,arr[i]);
			flag=0;
		}
		long long int val=(n*(n-1)/2);
		val=val-fin;
		printf("%lld\n",val);
		scanf("%lld",&n);
		if(n==0)
			break;
	}
	return 0;
}

