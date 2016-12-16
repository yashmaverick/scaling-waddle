#include<stdio.h>

long long int A[100001],top=-1;

void push(long long int x)
{
	if(top==(100000-1))
		{
			return;
		}
	else
	{
		top++;
		A[top]=x;
	}
}

long long int pop()
{
	long long int x;
	if(top==-1)
	{
		return -1;
	}
	else
	{
	x=A[top];
	top--;
	return x;
	}
}

long long int top1()
{
	if(top==-1)
	{
		return -1;
	}
	else
	{
		return A[top];
	}
}

long long int a[100001],Top=-1;

void Push(long long int x)
{
	if(Top==(100000-1))
		{
			return;
		}
	else
	{
		Top++;
		a[Top]=x;
	}
}

long long int Pop()
{
	long long int x;
	if(Top==-1)
	{
		return -1;
	}
	else
	{
	x=a[Top];
	Top--;
	return x;
	}
}

long long int Top1()
{
	if(Top==-1)
	{
		return -1;
	}
	else
	{
		return a[Top];
	}
}

long long int flagl[100001];
long long int flagr[100001];

int main()
{
	long long int c[100001];
	long long int i,n;
	while(1)
	{
	scanf("%lld",&n);
	if(n==0)
	{
		break;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&c[i]);
	}
	for(i=0;i<n;i++)
	{
		while((c[i]<top1())&&(top!=-1))
		{
			flagl[Top1()]=i-1;
			pop();
			Pop();
		}
		push(c[i]);
		Push(i);
	}
	while(top!=-1)
	{
		flagl[Top1()]=n-1;
		pop();
		Pop();
	}
	for(i=n-1;i>=0;i--)
	{
		while((c[i]<top1())&&(top!=-1))
		{
			flagr[Top1()]=i+1;
			pop();
			Pop();
		}
		push(c[i]);
		Push(i);
	}
	while(top!=-1)
	{
		flagr[Top1()]=0;
		pop();
		Pop();
	}
	long long int max,area;
	max=0;

	for(i=0;i<n;i++)
	{
		{
			area=(flagl[i]-flagr[i]+1)*c[i];
			if(area>max)
			{
			max=area;
			}
		}
	}
	printf("%lld\n",max);
	}
	return 0;
}

