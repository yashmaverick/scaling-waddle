#include<stdio.h>
#define repf(i,l,n) for(i=l;i<n;i++)
#define repb(i,l,n) for(i=l;i>n;i--)
#define LL long long int
void in(LL *address)
{
	scanf("%lld",address);
}
void out(LL *pointer)
{
	printf("%lld\n",*pointer);
}
LL stack[500001],a[500001];
int main()
{
	LL n,i,j,start,ans,count;
	in(&n);
	while(n!=0)
	{
		ans=start=0;
		repf(i,0,n) in(&a[i]);
		stack[start]=0;
		repf(i,1,n)
		{
			count=1;
			if(a[i]<=a[stack[start]])
				stack[++start]=i;
			else
			{
				while(start>-1 && a[stack[start]]<a[i] )
				{
					if(start>1 && a[stack[start-1]]!=a[stack[start]])
					{
						ans+=count*(start-1);
						count=1;
					}
					else
						count++;
					ans+=(n-1);
					ans-=i;
					start--;
				}
				stack[++start]=i;
			}
		}
		count=1;
		repb(i,start,0)
		{
			if(a[stack[i-1]]!=a[stack[i]])
			{
				ans+=count*(i-1);
				count=1;
			}
			else
				count++;
		}
		out(&ans);
		in(&n);
	}
	return 0;
}
