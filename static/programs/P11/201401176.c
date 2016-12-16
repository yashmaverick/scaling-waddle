#include<stdio.h>
long long int sz=0;
void push(long long int b[],long long int v)
{
	b[sz]=v;
	sz++;
}
void pop(long long int b[])
{
	if(sz==0)
		return ;
	sz--;
}
int main()
{
	long long int i,j,b[100005],n,x,p,ans;
	long long int a[100005];
	while(1)
	{
		ans=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(i=0;i<n;i++)
		{
			if(sz==0||a[b[sz-1]]<a[i])
				push(b,i);
			else if(a[b[sz-1]]>=a[i])
			{
				while(sz!=0&&a[i]<=a[b[sz-1]])
				{
					p=b[sz-1];
					pop(b);
				if(sz==0)
					x=i*a[p];
				else
					x=(i-b[sz-1]-1)*a[p];
				if(ans<x)
					ans=x;
				}
				push(b,i);
			}
		}
		while(sz!=0)
		{
			p=b[sz-1];
			pop(b);
			x=(sz==0)?a[p]*n:(n-b[sz-1]-1)*a[p];
			if(ans<x)
				ans=x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
