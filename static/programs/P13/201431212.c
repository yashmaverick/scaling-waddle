#include<stdio.h>
#include<stdlib.h>
int stack[100001];
int top=-1;
void push(int val)
{
	top++;
	stack[top]=val;
	return ;
}
int pop()
{
	int x,y;
	x=stack[top];
	y=top;
	top--;
	return x;
}
void insert(int a[],int b[],int cur,int n)
{
	int k,i;
	if(a[cur]>stack[top])
	{
		b[a[cur]]=b[stack[top]]+1;
		push(a[cur]);
		return ;
	}
	else
	{
		while(a[cur]<stack[top])
			k=pop();
		b[a[cur]]=b[k]+1;
		push(a[cur]);
		return ;
	}
}
void maximum(int a[],int b[],int n)
{
	int p,q;
	int max=b[0];
	q=0;
	for(p=1;p<100001;p++)
	{
		if(b[p]>max)
		{
			max=b[p];
			q=p;
		}
	}
	printf("%d %d\n",q,max);
}
int main()
{
	int t,i,j,m,n;
	int b[100001];
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		int a[n];
		for(j=0;j<100001;j++)
			b[j]=0;
		for(j=0;j<n;j++)
			scanf("%d",&a[j]);
		b[a[n-1]]=0;
		push(a[n-1]);
		for(j=n-2;j>=0;j--)
			insert(a,b,j,n);
		maximum(a,b,n);
	}
	return 0;
}
