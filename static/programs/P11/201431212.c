#include<stdio.h>
#include<stdlib.h>
struct stack
{
	long long int data;
	struct stack *next;
};
typedef struct stack stack;
stack *top=NULL;
void push(long long int x)
{
	stack *new=malloc(sizeof(stack));
	new->data=x;
	new->next=top;
	top=new;
}
void pop()
{
	if(top==NULL)
	{
		printf("stack is empty\n");
		return ;
	}
	else
	{
		stack *t=top;
		top=top->next;
		free(t);
	}
}
long long int top1()
{
	if(top==NULL)
		return -1;
	else
		return top->data;
}
long long int area(long long int his[],long long int n)
{
	long long int max=0,i=0,ar_tp,tp;
	while(i<n)
	{
		if(top1()==-1 || his[top1()]<=his[i])
			push(i++);
		else
		{
			tp=top1();
			pop();
			if(top1()==-1)
				ar_tp=his[tp]*i;
			else
				ar_tp=his[tp]*(i-top1()-1);
			if(ar_tp > max)
				max=ar_tp;
		}
	}
	while(top1()!=-1)
	{
		tp=top1();
		pop();
		if(top1()==-1)
			ar_tp=his[tp]*i;
		else
			ar_tp=his[tp]*(i-top1()-1);
		if(ar_tp > max)
			max=ar_tp;
	}
	return max;
}
int main()
{
	long long int n,i;
	while(1)
	{
		scanf("%lld",&n);
		if(n==0)
			break;
		long long int his[n];
		for(i=0;i<n;i++)
			scanf("%lld",&his[i]);
		printf("%lld\n",area(his,n));
	}
	return 0;
}
