#include<stdio.h>
#define maxn 100001

typedef long long ll;

typedef struct node
{
	ll index,data;
}node;

node s[maxn];
ll p;

ll top()
{
	return s[p].data;
}

ll isempty()
{
	return top()==-1?1:0;
}

ll pop()
{
	ll n=s[p].index; p--;
	return n;
}

void push(ll n,ll i)
{
	s[++p].data=n;
	s[p].index=i;
	return;
}

ll main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		ll i,k,j,n; s[0].data=-1;
		p=0;
		ll max=-1,min=100001;
		scanf("%lld",&n);
		if(n)
		{
			ll a[n];
			for(i=0;i<n;i++) scanf("%lld",&a[i]);
			for(i=n-1,k=0;i>=0;i--)
			{
				if(isempty() || a[i] > top())
					push( a[i],k );
				else
				{
					while(p > -1 && a[i]<top())
						k=pop()+1;
					push( a[i],k );
				}
				if(max < k)
				{
					max=k;
					min=a[i];
				}
				else if(max == k && min > a[i])
					min = a[i]; k++;
			}
			printf("%lld %lld\n",min,max);
		}
		
	}
	return 0;
}
