#include<stdio.h>

#define maxn 500001

long long int s[maxn];
long long int p;

long long int top()
{
	return s[p];
}

long long int isempty()
{
	return top()==-1?1:0;
}

long long int pop()
{
	long long int n=s[p]; p--;
	return n;
}

void push(long long int n)
{
	s[++p]=n;
	return;
}

long long int main()
{
	long long int tp,i,k,n,m,ans,cnt;
	scanf("%lld",&n);
	while(n)
	{
		ans=0; p=0; s[0]=-1;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(isempty())        // 4 3 5 2 2 5
				push(k);
			else if(top() >= k)
			{
				push(k);
				if(s[1] != k) ans++;
			}
			else
			{
				cnt=1;
				if(!isempty())
				{
					while(top() < k && !isempty())
					{
						tp = pop();
						if( top() == tp )
							cnt++;
						else
						{
							ans += cnt*(cnt-1)/2 + cnt;
							cnt=1;
						}
					}
				}
				else ans += cnt*(cnt-1)/2 + cnt;
				if( !isempty() && (s[1] != k) ) ans++;
				push(k);
			}
		}
		cnt=1;
		while(!isempty())
		{
			tp = pop();
			if(top() == tp)
				cnt++;
			else
			{
				ans += cnt*(cnt-1)/2;
				cnt=1;
			}
		}
		printf("%lld\n",n*(n-1)/2-ans);
		scanf("%lld",&n);
	}
	return 0;
}
