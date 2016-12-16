#include<stdio.h>
#define MAX 1000000009
long long int st[100100],left[100100],h[100100];
long long int end=0,mh,min;
void push(long long int x)
{
	st[end++]=x;
	return;
}
void pop()
{
	if(end!=0)
		end--;
	return;
}
long long int top()
{
	if(end==0)
		return -1;
	return st[end-1];
}

void myfunc(long long int l,long long int r,long long int cnt)
{
	long long int val;
	if(l==r)
	{
		val=h[l];
		if(cnt>=mh)
		{
			if(val< min || cnt>mh)
			{
				min=val;
				mh=cnt;
			}
		}
	}
	else if(l<r)
	{
		myfunc(l,left[r],cnt+1);
		if(left[r]>=l)
			myfunc(left[r]+1,r-1,cnt+1);
		else
			myfunc(l,r-1,cnt+1);
	}
	return ;
}

int main()
{
	long long int tc,x,i,n;
	scanf("%lld",&tc);
	while(tc--)
	{
		end=0;
		scanf("%lld",&n);
		mh=-1,min=MAX;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
		}
		for(i=0;i<n;i++)
		{
			x=top();
			if(x==-1)
			{
				push(i);
				left[i]=x;
			}
			else
			{
				while(x!=-1 && h[x]>=h[i])
				{
					pop();
					x=top();
				}
				left[i]=x;
				push(i);
			}
		}
		myfunc(0,n-1,0);
		printf("%lld %lld\n",min,mh);
	}
	return 0;
}
