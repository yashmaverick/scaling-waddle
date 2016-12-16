#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>
#define ll long long int
#define sint(n); scanf("%d",&n);
#define pint(n); printf ("%d\n",n);
#define sll(n); scanf("%lld",&n);
#define pll(n); printf("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define TEST scanf("%lld",&test);while(test--)
#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<=n;i++)

ll n,height[100002],indexstack[100002],maxarea[100002],top;
void left()
{
	ll i,temp;
	top=-1;
	f0(i,n)
	{
		while(top>-1)
		{
			if (height[indexstack[top]]>=height[i])
				top--;
			else if (height[indexstack[top]]<height[i])
				break;
		}
		if (top==-1)
			temp=-1;
		else
			temp=indexstack[top];
		maxarea[i]+=(height[i]*(i-temp-1));
		indexstack[++top]=i;
	}
	return;
}
void right()
{
	top=-1;
	ll i,temp;
	for(i=n-1;i>=0;i--)
	{
		while(top>-1)
		{
			if (height[indexstack[top]]>=height[i])
				top--;
			else if (height[indexstack[top]]<height[i])
				break;
		}
		if (top==-1)
			temp=n;
		else
			temp=indexstack[top];
		maxarea[i]+=(height[i]*(temp-i-1));
		indexstack[++top]=i;
	}
	return;
}
ll findmax()
{
	ll i,max=INT_MIN;
	f0(i,n){maxarea[i]+=height[i];if(maxarea[i]>max)max=maxarea[i];}
	return max;
}
int main()
{
	ll i;
	while(1)
	{
		sll(n);
		if (n==0)break;
		top=-1;
		f0(i,n){sll(height[i]);	maxarea[i]=0;}
		left();		right();
		pll(findmax());
	}
	return 0;
}
