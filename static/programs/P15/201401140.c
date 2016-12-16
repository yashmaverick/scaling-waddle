#include<stdio.h>
#define max 10090
long long int a[max],b[max],end=0,start=0;
void push(long long int v)
{
	b[end]=v;
	end++;
}
void pops()
{
	if(start<end)
		start++;
}
void popl()
{
	if(end!=0)
		end--;
}
long long int top()
{
	if(end==start)
		return -1;
	return b[end-1];
}
void func(long long int n,long long int k)
{
	long long int i,g;
	for(i=0;i<k;i++)
	{
		g=top();
		if(g==-1 || a[i]>=a[g])
			push(i);
		else
		{
			while(g!=-1 && a[i]<a[g])
			{
				popl();
				g=top();
			}
			push(i);
		}
	}
	if(n==1 || end==n  || n==k)
		printf("%lld",a[b[start]]);
	else
		printf("%lld ",a[b[start]]);
	for(i=0;i<n-k;i++)
	{
		while(b[start]<=i && start<end)
			pops();
		g=top();
		if(g==-1 || a[i+k]>=a[g])
			push(i+k);
		else
		{
			while(g!=-1 && a[i+k]<a[g])
			{
				popl();
				g=top();
			}
			push(i+k);
		}
		if(i!=n-k-1)
			printf("%lld ",a[b[start]]);
		else
			printf("%lld",a[b[start]]);
	}
}
int main()
{
	long long int t,j,i,n,k;
	scanf("%lld",&t);
	for(j=0;j<t;j++)
	{
		scanf("%lld %lld",&n,&k);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		end=0;
		start=0;
		func(n,k);
		printf("\n");
	}
	return 0;
}
