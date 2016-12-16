#include<stdio.h>
#include<stdlib.h>
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
	return stack->top==-1;
}
void push(Stack* stack,long long int item)
{
	stack->array[++stack->top]=item;
}
long long int pop(Stack* stack)
{
	if(isMT(stack))
		return -1;
	return stack->array[stack->top--];
}
long long int topmem(Stack* stack)
{
	if(isMT(stack))
		return -1;
	return stack->array[stack->top];
}
int main()
{	
	long long int max,n,i,x,area;
	long long int* arr;
	while(1)
	{	
		max=0;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		Stack* stack=createstack(n);
		arr=(long long int*)malloc(n*sizeof(long long int));
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		for(i=0;i<n;i++)
		{	
			if(isMT(stack) || arr[i]>=(arr[topmem(stack)]))
			{
				push(stack,i);
			}
			else if(arr[i]<arr[topmem(stack)])
			{
				while(arr[i]<arr[topmem(stack)])
				{
					if(stack->top==0)
					{
						x=pop(stack);
						area=arr[x]*i;
						if(max<area)
							max=area;
					break;
					}
					else
					{
						x=pop(stack);
						area=(arr[x])*(i-topmem(stack)-1);
						if(max<area)
							max=area;
					}
				}
				push(stack,i);
			}
		}
		while(!isMT(stack))
		{	if(stack->top==0)
			{
				x=pop(stack);
				area=(arr[x])*(i);
				if(area>max)
					max=area;
			}
			else
			{
				x=pop(stack);
				area=(arr[x])*(i-topmem(stack)-1);
				if(area>max)
					max=area;
			}
		}
		printf("%lld\n",max);
	}
}







