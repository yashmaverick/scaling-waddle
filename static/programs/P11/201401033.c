#include<stdio.h>
long long int st[100100];
long long int end=0;
void push(long long int i)
{
	st[end++]=i;
}
void pop()
{
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
	long long int n,x,i;
	long long int max=0,temp;
//	long long int h[100100];	
//	long long int left[100100],right[100100];
	while(1)
	{
		max=0;
		scanf("%lld",&n);
		long long int left[n],right[n],h[n];
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
			x=top();
			if(x==-1)
			{
				push(i);
				left[i]=x;
			}
			else
			{
				while(h[x]>=h[i])
				{
					pop();
					x=top();
					if(x==-1)
						break;
				}
				left[i]=x;
				push(i);
			}
		}
		end=0;
		for(i=n-1;i>=0;i--)
		{
			x=top();
			if(x==-1)
			{
				push(i);
				right[i]=n;
			}
			else
			{
				while(h[x]>=h[i])
				{
					pop();
					x=top();
					if(x==-1)
						break;
				}
				if(x==-1)
					right[i]=n;
				else
					right[i]=x;
				push(i);
			}
		}
		end=0;
		for(i=0;i<n;i++)
		{
			temp=((right[i]-left[i]-1)*h[i]);
			if(temp>max)
				max=temp;
		}
		printf("%lld\n",max);
	}
	return 0;
}
