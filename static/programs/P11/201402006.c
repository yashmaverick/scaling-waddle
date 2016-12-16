#include<stdio.h>
#include<stdlib.h>
struct Stack
{
	int top;
	int capacity;
	int *value;
};
struct Stack *createStack(long long int capacity)
{
	struct Stack *stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->value = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}
long long int isEmpty(struct Stack *stack)
{
	return stack->top==-1;
}
long long int isFull(struct Stack *stack)
{
	return stack->top==stack->capacity-1;
}
void push(struct Stack *stack, long long int item)
{
	if(isFull(stack))
		return;
	stack->value[++stack->top] = item;
}
long long int pop(struct Stack *stack)
{
	if(isEmpty(stack))
		return -1;
	return stack->value[stack->top--];
}
long long int peek(struct Stack *stack)
{
	if(isEmpty(stack))
		return -1;
	return stack->value[stack->top];
}
int main()
{
	long long int n,t,i;
	long long int area,maxarea,x;
	long long int hist[100000];
	while(1)
	{	maxarea=0;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		struct Stack *stack;
		stack = createStack(n);
		for(i=0;i<n;i++)
			scanf("%lld",&hist[i]);
		for(i=0;i<n;i++)
		{//	printf("i= %d\n",i);
			//printf("stack empty output = %d",isEmpty(stack));
			if(isEmpty(stack) || (hist[i] >=hist[peek(stack)]))
			{
				push(stack,i);	
	//			printf("pushed %d\n,top= %d",hist[i],stack->top);
			}
			else/*(hist[i] < peek(stack))*/
			{//`;wq	printf("gaya kya??\n");
				while(hist[i]<=hist[peek(stack)])
				{
					if(stack->top==0)
					{		
						x=pop(stack);
	//					printf("Popped=%d\n",hist[x]);
						area=hist[x]*(i);
						if(area>maxarea)
							maxarea=area;
						break;
					}
					//top = peek(stack);
					x = pop(stack);
	//				printf("Popped=%d\n",hist[x]);
					area = ((i-peek(stack)-1)* hist[x]);  
					if(maxarea < area)
					{
						maxarea = area;
					}
				}
				push(stack,i);
			}
		}
		while(!isEmpty(stack))
		{
			if(stack->top==0)
			{		
				x=pop(stack);
	//			printf("Popped=%d\n",hist[x]);
				area=hist[x]*(i);
				if(area>maxarea)
					maxarea=area;
				break;
			}
			x = pop(stack);
	//		printf("Popped=%d\n",hist[x]);
			area = ((i-peek(stack)-1)* hist[x]);  
			if(maxarea < area)
			{
				maxarea = area;
			}
		}

		printf("%lld\n",maxarea);
	}
}
