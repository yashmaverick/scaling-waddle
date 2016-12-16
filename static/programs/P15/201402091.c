#include<stdio.h>
#include<stdlib.h>
long long int k;
typedef struct Stack
{
	long long int top;
	long long int* array;
	long long int maximum;
}Stack;
struct Stack* createstack(long long int maximum)
{
	Stack* stack=(Stack*)malloc(sizeof(Stack));
	stack->maximum=maximum;
	stack->top=-1;
	stack->array=(long long int*)malloc((stack->maximum+1)*sizeof(long long int));
	return stack;
}
long long int isMT(Stack* stack)
{
	return stack->top==k;
}
void push(Stack* stack,long long int item)
{
	stack->array[++stack->top]=item;
}
long long int pop(Stack* stack)
{
	if(isMT(stack))
		return k;
	return stack->array[stack->top--];
}
long long int topmem(Stack* stack)
{
	if(isMT(stack))
		return k;
	return stack->array[stack->top];
}
int main()
{	long long int x,i,j,t,n,w,a[10007];
	scanf("%lld",&t);
	for(i=0;i<t;i++)
	{
		scanf("%lld %lld",&n,&w);
		for(j=0;j<n;j++)
			scanf("%lld",&a[j]);
		k=-1;
		Stack *stack=createstack(n);
		for(j=0;j<n;j++)
		{
			if(isMT(stack) || a[j]>=topmem(stack))
				push(stack,a[j]);
			else if(a[j]<topmem(stack))
			{
				while(a[j]<topmem(stack) && !isMT(stack))
					x=pop(stack);
				push(stack,a[j]);
			}
			if(j>(w-1) && stack->array[k+1]==a[j-w])
				k++;			
			if(j>=(w-1) && j!=(n-1))
		printf("%lld ",stack->array[k+1]);
			else if(j==(n-1))
		printf("%lld\n",stack->array[k+1]);
		}
	}
	return 0;	
}
