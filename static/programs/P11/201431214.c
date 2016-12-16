#include<stdio.h>
#include<stdlib.h>
typedef struct STACK
{
	int top;
	int cap;
	int a[100001];
}STACK;
STACK* stack1;
STACK* stack2;
STACK* createstack(STACK* stack)
{
	stack=(STACK*)malloc(sizeof(STACK));
	stack->cap=100001;
	stack->top=-1;
	return stack;
}
void push(int value,STACK* stack)
{
	if(stack->top==100001)
	{
		return;
	}
	else
	{
		stack->top=(stack->top)+1;
		stack->a[(stack->top)]=value;
	}
}
void pop(STACK* stack)
{
	int temp;
	if(stack->top==-1)
	{
		return ;
	}
	else
	{
		stack->top=(stack->top)-1;
	}
}
int main()
{
	long long int n,height[100005],new1[100001],new2[100001],i,b1[100001],b2[100001],ans[100001];
	while(1)
	{
		long long int max=0;
		scanf("%lld",&n);
		if(n==0)
		{
			return 0;
		}
		else
		{
			stack1=createstack(stack1);
			stack2=createstack(stack2);
				scanf("%lld",&height[0]);
					push(0,stack1);
			b1[0]=0;
			for(i=1;i<n;i++)
			{
				scanf("%lld",&height[i]);
				if(stack1->top!=-1 && height[i]>=height[stack1->a[stack1->top]])
				{
					b1[i]=i;
					push(i,stack1);
				}
				else if(stack1->top!=-1 && height[i]<height[stack1->a[stack1->top]])
				{
					while(stack1->top!=-1 && ((height[stack1->a[stack1->top]])>(height[i])))
					{
						b1[stack1->a[stack1->top]]=i;
						pop(stack1);
					}
					push(i,stack1);
					b1[i]=i;
				}
			}

			for(i=n-1;i>=0;i--)
			{
				if(stack1->a[stack1->top]==i)
				{
					new1[i]=height[i]*(n-b1[i]);
					pop(stack1);
				}
				else
				{
					new1[i]=height[i]*(b1[i]-i);
				}
				b1[i]=0;
			}
			while(stack1->top!=-1)
			{
				stack1->top=stack1->top-1;
			}
			push(n-1,stack2);
			b2[n-1]=n-1;
			for(i=(n-2);i>=0;i--)
			{
				if(stack2->top!=-1 && height[i]>=height[stack2->a[stack2->top]])
				{
					b2[i]=i;
					push(i,stack2);
				}
				else
				{
					while(stack2->top!=-1 && height[stack2->a[stack2->top]]>height[i])
					{
						b2[stack2->a[stack2->top]]=i;
						pop(stack2);
					}
					push(i,stack2);
					b2[i]=i;
				}
			}
			for(i=0;i<n;i++)
			{
				if(stack2->a[stack2->top]==i)
				{
					new2[i]=height[i]*(b2[i]+1);
					pop(stack2);
				}
				else
				{
					new2[i]=height[i]*(i-b2[i]);
				}
				b2[i]=0;
				ans[i]=new1[i]+new2[i]-height[i];
				if(ans[i]>max)
				{
					max=ans[i];
				}
			}
			while(stack2->top!=-1)
			{
				stack2->top=stack2->top-1;
			}
			printf("%lld\n",max);
		}
	}
	return 0;
}
