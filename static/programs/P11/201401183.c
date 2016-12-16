#include<stdio.h>
long long int a[100009],top=-1,st[100009],width[100009];
void push(int val)
{
	st[++top]=val;
}
void pop()
{
	if(top==-1)
		printf("-1\n");
	else
		--top;
}
void peek()
{
	printf("%lld\n",st[top]);
}
void print()
{
	long long int i;
	if(top>-1)
	{
		for(i=0;i<=top;i++)
			printf("%lld  ",st[i]);
	printf("\n");
	}
}
int left(int ai,int i)
{
	long long int x;
	while(top!=-1)
	{
		if(ai<=a[st[top]])
			pop();
		else break;
	}
	if(top==-1)
		x=i;
	else x=i-st[top]-1;
	return x;
}
int right(int ai,int i,int n)
{
	long long int y;
	while(top!=-1)
	{
		if(ai<=a[st[top]])
			pop();
		else break;
	}
	if(top==-1)
		y=n-i-1;
	else y=st[top]-i-1;
	return y;
}
int main()
{
	long long int n,i,j,area,max;
	while(1)
	{
		top=-1;
		max=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			width[i]=left(a[i],i);
		//	printf("%d  ",width[i]);
			push(i);
		}
		//printf("\n");
		while(top!=-1)
		{
			pop();
		}
		for(i=n-1;i>=0;i--)
		{
			j=right(a[i],i,n);
		//	printf("%d  ",j);
			width[i]=width[i]+j;
			push(i);
			//printf("%d  ",width[i]);
		}
		//printf("\n");
		for(i=0;i<n;i++)
		{
		//	printf("%d ",width[i]+1);
			area=(width[i]+1)*a[i];
			if(area>max)
				max=area;
		}
		printf("%lld\n",max);
	}
	return 0;
}
		
