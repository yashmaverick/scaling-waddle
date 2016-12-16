#include<stdio.h>
long long int st[1000000],end=0;
void push(long long int x)
{
	st[end++]=x;
	return;
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
	return st[end-1];
}

int main()
{
	long long int n,i,qw,x,y,s;
	while(1)
	{
		end=0;
		s=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&qw);
			x=top();
			if(x==-1 || qw<=x)
				push(qw);
			else
			{
				while(x!=-1 && qw>x)
				{
					pop();
					x=top();
					s+=(n-i-1);
				}
				push(qw);
			}
			if(end>2)
			{
				y=end-1;
				while(y!=0 && st[y]<=top())
				{
					y--;
				}
				s+=(y);
			}
		}
		printf("%lld\n",s);
	}
	return 0;
}
