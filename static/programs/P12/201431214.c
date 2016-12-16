#include<stdio.h>
#include<stdlib.h>
long long int n;
typedef struct STACK
{
	long long int top;
	long long int cap;
	long long int *a;
}STACK;
STACK* createstack(STACK* stack)
{
	stack=(STACK*)malloc(sizeof(STACK));
	stack->a=(long long int*)malloc(n*sizeof(long long int));
	stack->cap=500001;
	stack->top=-1;
	return stack;
}
void push(long long int value,STACK* stack)
{
	if(stack->top==n-1)
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
	long long int temp;
	if(stack->top==-1)
	{
		return ;
	}
	else
	{
		stack->top=(stack->top)-1;
	}
}
long long int *height,i,*b2,ans,j,total,case1;
STACK* stack1;
int main()
{
	while(1)
	{     
		stack1=NULL;
		ans=0;
		scanf("%lld",&n);
		height = (long long int*) malloc(n*sizeof(long long int));
		b2= (long long int*) malloc(n*sizeof(long long int));
		//STACK.a=(long long int*)malloc(n*sizeof(long long int)); 
		total=n*(n-1)/2;
		if(n==0)
		{
			return 0;
		}
		else
		{
			stack1=createstack(stack1);
			for(i=0;i<n;i++)
			{
				scanf("%lld",&height[i]);
				b2[i]=0;
				//	count[i]=0;
			}
			push(0,stack1);
			for(i=1;i<n;i++)
			{
				if(stack1->top!=-1 && height[i]<=height[stack1->a[stack1->top]])
				{
					b2[i]=i;
					push(i,stack1);
				}
				else if(stack1->top!=-1 && height[i]>height[stack1->a[stack1->top]])
				{
					while((stack1->top!=-1)&&((height[stack1->a[stack1->top]])<(height[i])))
					{
						b2[stack1->a[stack1->top]]=i;
						pop(stack1);
					}
					push(i,stack1);
					b2[i]=i;
				}
			}
			for(i=0;i<n;i++)
			{
				if(b2[i]!=i)
				{
					ans++;

				}
				//				printf("value of b2 %lld\n",b2[i]);

			}
			//			printf("value of ans %lld\n",ans);
			while(stack1->top!=-1)
			{
				pop(stack1);
			}
			stack1=createstack(stack1);
			push(n-1,stack1);
			b2[n-1]=n-1;
			for(i=(n-2);i>=0;i--)
			{
				if(stack1->top!=-1 && height[i]<=height[stack1->a[stack1->top]])
				{
					b2[i]=i;
					push(i,stack1);
				}
				else
				{
					while(stack1->top!=-1 && (height[stack1->a[stack1->top]]<height[i]))
					{
						b2[stack1->a[stack1->top]]=i;
						pop(stack1);
					}
					push(i,stack1);
					b2[i]=i;
				}
			}

			for(i=n-1;i>=0;i--)
			{
				if(b2[i]!=i)
				{
					ans++;
				}
				b2[i]=0;
			}
			//	stack1=NULL;
			while(stack1->top!=-1)
			{
				pop(stack1);
			}
			stack1=createstack(stack1);
			push(height[0],stack1);
			b2[0]=1;
			for(i=1;i<n;i++)
			{
				if(height[i]==stack1->a[stack1->top])
				{
					b2[stack1->top]=b2[stack1->top]+1;
				}
				else if(height[i]<stack1->a[stack1->top])
				{
					push(height[i],stack1);
					b2[stack1->top]=b2[stack1->top]+1;
				}
				else
				{
					while(stack1->top!=-1 && stack1->a[stack1->top]<height[i])
					{
						ans=ans+((b2[stack1->top])*(b2[stack1->top]-1))/2;
						b2[stack1->top]=0;
						pop(stack1);
					}		
					if(height[i]==stack1->a[stack1->top])
					{
						b2[stack1->top]=b2[stack1->top]+1;
					}
					else
					{
						push(height[i],stack1);
						(b2[stack1->top])=b2[stack1->top]+1;
					}
				}

			}
			for(i=0;i<=stack1->top;i++)
			{
				if(b2[i]!=0)
				{
					ans=ans+b2[i]*(b2[i]-1)/2;
				}
			}
			while(stack1->top!=-1)
			{
				pop(stack1);
			}
		}
		//		printf("value of ans %lld\n",ans);
		case1=total-ans;
		printf("%lld\n",case1);
		stack1=NULL;
	}
	return 0;
}
