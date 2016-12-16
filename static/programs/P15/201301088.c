#include<stdio.h>

#define ll long long int

ll s[10001],tp,p;

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

int main()
{
	long long int i,n,k,j,min,t;
	scanf("%lld",&t);
	while(t--)
	{
		s[0] = -1; p=0; min=1e9;
		scanf("%lld%lld",&n,&k);
		long long int a[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<=n-k;i++)
		{
			if(i==0 || a[i-1] == min) { for(j=i,min=1e9;j<i+k;j++) if(min > a[j]) min=a[j]; printf("%lld",min); }
			else printf("%lld",min=(min < a[i+k-1] ? min : a[i+k-1]));
			if(i!=n-k) printf(" ");
		} puts("");
/*		for(i=0;i<=n-k;i++)
		{
			if(a[i-1] == top() || i==0)
			{
				for(j=i,p=0;j<i+k;j++)
				{
					if(isempty()) push(a[j]);
					else if(a[j] < top())
					{
						while( a[j] < top() && !isempty() ) pop();
						push(a[j]);
					}
				}
				printf("%lld ",top());
			}
			else
				printf("%lld ",top());
		}
		puts("");
*/	}
	return 0;
}
