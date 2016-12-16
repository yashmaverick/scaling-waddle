#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<math.h>
#define ll long long int

ll s[500005],a[500005],t,i,temp,n,ans;

inline void pop();
inline void push(ll val);
inline void clear();

int main()
{
	scanf("%lld",&n);
	while(n)
	{
		i=ans=t=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;)
		{
			if( a[i] <= a[s[t-1]])
				push(i++);
			else if(t==0)
				push(i++);
			else if (t==1)
			{		
				pop();ans++;
			}
			else
			{
				clear();ans++;
			}
		}
		while(t>0)
			clear();				

		printf("%lld\n",(n*(n-1))/2 - ans);
		scanf("%lld",&n);
	}
return 0;
}

void pop()
{
	t-=1;
}

void push(ll val)
{
	s[t]=val;
	t+=1;
}

void clear()
{
	temp=--t;
	while(temp>0 &&  a[s[t]] == a[s[temp-1]])
	{
		ans++; temp--;
	}
	if(temp>0)
		ans++;
}	
