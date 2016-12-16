#include<stdio.h>
#include<stdlib.h>
#define max 100000
long long int l[max],r[max],a[max],b[max],end=0;
void push(long long int v)
{
	b[end]=v;
	end++;
}
void pop()
{
	if(end!=0)
		end--;
}
long long int top()
{
	if(end==0)
		return -1;
	return b[end-1];
}
void left(long long int n)
{
	long long int i,g;
	push(0);
	l[0]=-1;
	for(i=1;i<n;i++)
	{
		g=top();
		if(a[i]>a[g])
		{
			push(i);
			l[i]=g;
		}
		else
		{
			while(a[i]<=a[g] && g>=0)
			{
				if(end!=0)
				{
					pop();
					//if(end!=0)
					g=top();

				}
				else
					break ;
			}
			l[i]=g;
			push(i);
		}
	}
}
void right(long long int n)
{
	long long int i,g;
	push(n-1);
	r[n-1]=n;
	for(i=n-2;i>=0;i--)
	{
		g=top();
		if(a[i]>a[g])
		{
			push(i);
			r[i]=g;
		}
		else
		{
			while(a[i]<=a[g])
			{
				if(end!=0)
				{
					pop();
					g=top();
				}
				else
					break ;
			}
			if(g==-1)
				g=n;
			r[i]=g;
			push(i);
		}
	}
}
int main()
{
	long long int n,i;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int c,maxa=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		end=0;
		left(n);
		end=0;
		right(n);
		maxa=0;
//		for(i=0;i<n;i++)
		for(i=0;i<n;i++)
		{
			c=((r[i]-l[i]-1)*a[i]);
			if(c>maxa)
				maxa=c;
		}
		printf("%lld\n",maxa);
		scanf("%lld",&n);
	}
	return 0;
}
