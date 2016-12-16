#include <stdio.h>
typedef long long int ll;
ll stack[100005];
ll stack2[100005];
ll pop();
ll pop2();
void push2(ll x);
void push(ll x);
ll top=-1;
ll elements=0;
ll top2=-1;
ll elements2=0;
int main()
{
	ll h[100005];
	ll n,area=0,index;
    ll 	area2=0;
	ll j;
	while(1)
	{   area=0;
		area2=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		ll i=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&h[i]);
		}
		for(i=0;i<n;i++)
		{
			if(elements==0 || h[stack[top]]<h[i])
				push(i);
			else //if(h[stack[top]]>h[i])
			{
				if(h[stack[top]]==h[i])
					continue;
				index=0;
				while(elements!=0)
				{
					if(h[stack[top]]>h[i])
					{
						index=pop();
						ll tArea=h[index]*(i-index);
						if(tArea>area)
							area=tArea;
					}
					else
						if(h[stack[top]]<=h[i]);
					break;
				}
				if(h[stack[top]]<h[i] || top>-1)
					push(index);
			}
		}

			while(1)
			{   index=0;
				if(elements==0)
					break;
				index=pop();
				ll tArea=h[index]*(n-index);
				if(tArea>area)
					area=tArea;
			}
			j=0;
			for(;j<n;)
			{
				if(elements2==0 || h[stack2[top2]]<=h[j])
				{
					push2(j);
					j=j+1;
				}
				else
				{
					ll tArea;
					index=pop2();
				    if(top2==-1)
						tArea=h[index]*(j);
					else
					   tArea=h[index]*(j-stack2[top2]-1);
					if(area2<tArea)
						area2=tArea;
				}
			}
			while(1)
			{
				if(elements2==0)
					break;				
					ll tArea;
					index=pop2();
				    if(top2==-1)
						tArea=h[index]*(n);
					else
					   tArea=h[index]*(n-stack2[top2]-1);
					if(area2<tArea)
						area2=tArea;
			}

		printf("%lld\n",area2);

	}
	return 0;
}	
void push(ll x)
{
	if(elements==100005)
		return;
	else
	{stack[++top]=x;
		elements++;
	}
}
ll pop()
{
	if(elements==0)
		return -1;
	else
	{ ll x=stack[top--];
		elements--;
		return x;
	}
}
void push2(ll x)
{
	if(elements2==100005)
		return;
	else
	{stack2[++top2]=x;
		elements2++;
	}
}
ll pop2()
{
	if(elements2==0)
		return -1;
	else
	{ ll x=stack2[top2--];
		elements2--;
		return x;
	}
}
