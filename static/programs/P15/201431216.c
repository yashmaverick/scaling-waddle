#include<stdio.h>
struct stack
{
	long long int top;
	long long int rear;
	long long int arr[500010];
}a;
void push(long long int index)
{
	a.top++;
	a.arr[a.top]=index;
	return;
}
void pop()
{
	if(a.top==-1)
		return;
	else
	{
		a.top--;
	}
}
int main()
{
	long long int test,i,t,g,n,k,j,x[500010],alpha[500010];
	scanf("%lld",&test);
	for(i=0;i<test;i++)
	{
		g=0;
		a.top=-1;
		a.rear=0;
		scanf("%lld%lld",&n,&k);
		for(j=0;j<n;j++)
		{
			scanf("%lld",&x[j]);
		}

		for(j=0;j<n;j++)
		{
			if(j==0)
			{
				push(j);
			}
			if(j>0)
			{
				if(x[j]>=x[a.arr[a.top]])
					push(j);
				t=a.arr[a.top]-a.arr[a.rear];
				if(t>=k)
				{
					a.rear++;
				}
				if(x[j]<x[a.arr[a.top]])
				{
					while(a.top>=a.rear && x[a.arr[a.top]]>x[j])
					{
						pop();
					}
					push(j);

					t=a.arr[a.top]-a.arr[a.rear];
					if(t>=k)
					{
						a.rear++;
					}
				}
			}
			if(j>=(k-1))
			{
				alpha[g]=x[a.arr[a.rear]];
				g++;
			}
		}
		for(j=0;j<g-1;j++)
		{
			printf("%lld ",alpha[j]);
		}
		printf("%lld",alpha[g-1]);
		printf("\n");
	}
	return 0;
}







