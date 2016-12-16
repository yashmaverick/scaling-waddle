#include<stdio.h>
#define maxn 1000011

typedef long long int ll;

ll s[maxn],tp,p;

ll top()
{
	return s[p];
}

ll isempty()
{
	return top()==-1?1:0;
}

ll pop()
{
	ll n=s[p]; p--;
	return n;
}

void push(ll n)
{
	s[++p]=n;
	return;
}
ll main()
{
	ll n,i,j,k,l,sum,max;
	scanf("%lld",&n); s[0]=-1;
	while(n)
	{
		max=0;
		ll a[n];
		for(i=0;i<n;i++) scanf("%lld",&a[i]); i=0;
		while(i < n)
		{
			if(isempty() || a[top()] <= a[i])
				push(i++);
			else
			{
				tp = top();
				pop();
				j = a[tp]*(isempty() ? i : i - top() -1);
				if(max < j)
					max = j;
			}
		}
		while(isempty() == 0)
		{
			tp = top();
			pop();
			j = a[tp]*(isempty() ? i : i - top() -1);
			if(max < j)
				max = j;
		}
		printf("%lld\n",max);
		scanf("%lld",&n);
	}
	return 0;
}
