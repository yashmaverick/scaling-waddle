#include<stdio.h>
long long int a[500000]={0},h[500000];
int i,max=500000;
void push();
int pop();
int top();
void print();
int main()
{
	int n,j,flag,k,d,l;
	long long int c;
	while(1)
	{
		i=-1;
		c=0;
		k=0;
		scanf("%d",&n);
		if(n==0)
			break;
		else
		{
			for(j=0;j<n;j++)
				scanf("%lld",&h[j]);
			j=0;
			while(j<n)
			{
				if(i==-1||h[j]<=a[i])
				{
					push(h[j]);
					l=i;
					while(l>=0&&a[l]==a[i])
					{
						l--;

					}
					if(l>0)
					c=c+l;
					j++;
				}
				else
				{
					pop();
					c=c+n-j-1;
				}
			}
		}
		printf("%lld\n",c);
	}			
	return 0;
}
void push(long long int v)
{
	if(i==max-1)
	{
		return;
	}
	i=i+1;
	a[i]=v;
	//	printf("%d %d\n",i,a[i]);
	return;
}
int pop()
{
	if(i==-1)
	{
		return 0;
	}
	i=i-1;
	return a[i+1];
}
int top()
{
	if(i==-1)
		return -1;
	return a[i];
}
void print()
{
	int j;
	if(i==-1)
	{
		printf("-1");
		return;
	}
	for(j=i;j>=0;j--)
		printf("%lld ",a[j]);
	return;
}





