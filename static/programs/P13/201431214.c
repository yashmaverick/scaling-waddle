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
	int t,j;
	scanf("%d",&t);
	for(j=0;j<t;j++)
	{
		int b1[100001],p,l,ans=0,max=0,o,n,perm[100001],r=0;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&perm[i]);
			b1[i]=0;
		}
		stack1=createstack(stack1);
		p=0;
		push(n-1,stack1);
		for(i=n-2;i>=0;i--)
		{
			if(stack1->top!=-1 && perm[i]>=perm[stack1->a[stack1->top]])
			{
				b1[i]=b1[stack1->a[stack1->top]]+1;
				push(i,stack1);
			//	r=n-i-1;
			//	b1[n-i-1]=p+1;
			}
			else
			{        
				while(stack1->top!=-1 &&r>=0 && perm[i]<perm[stack1->a[stack1->top]] )
				{
					l=b1[stack1->a[stack1->top]];
					pop(stack1);
				}
			//	printf("value of l %d\n",l);
				push(i,stack1);
			//	r=n-i-1;
				b1[i]=l+1;
			}
		//	p=b1[n-i-1];
		}
		while(stack1->top!=-1)
		{
			stack1->top=stack1->top-1;
		}
		for(o=0;o<n;o++)
		{
		//	printf("value of b1[] %d\n",b1[o]);
			if(max<b1[o])
			{
				ans=o;
				max=b1[o];
			}
			else if(max==b1[o])
			{
				if(perm[ans]>perm[o])
				{
					ans=o;
					max=b1[o];
				}
				else
				{
				//	ans=ans;
					max=b1[o];
				}
			}
		//	printf("last for\n");
		}
		printf("%d %d\n",perm[ans],max);
	}
	return 0;
}
