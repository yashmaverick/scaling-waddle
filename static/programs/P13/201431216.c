#include<stdio.h>
struct stack
{
	int top;
	int arr[100010];
}a;
void push(int index)
{
	a.top++;
	a.arr[a.top]=index;
}
int pop()
{
	if(a.top==-1)
		return;
	else
	{
		int y=a.arr[a.top];
		a.top--;
		return y;
	}
}
void tree(int pre[],int size)
{
	int j,depth=0,node=pre[0],tmp,height[100010];
	a.top=-1;
	push(size-1);
	height[size-1]=0;
	for(j=size-2;j>=0;j--)
	{
		if(pre[j]>pre[a.arr[a.top]])
		{
			push(j);
			height[j]=height[j+1]+1;
		}
		if(pre[j]<pre[a.arr[a.top]])
		{
			while(a.top>=0 && pre[a.arr[a.top]]>pre[j])
			{
				tmp=pop();
			}
			push(j);
			height[j]=height[tmp]+1;
		}
	}
	for(j=0;j<size;j++)
	{
		if(height[j]>depth)
		{
			depth=height[j];
			node=pre[j];
		}
		if(height[j]==depth)
		{
			if(pre[j]<node)
				node=pre[j];
		}
	}
	printf("%d %d\n",node,depth);
}
int main()
{
	int n,i,a[100010],test,m;
	scanf("%d",&test);
	for(m=0;m<test;m++)
	{
		//a.top=-1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		tree(a,n);
	}	
	return 0;
}
