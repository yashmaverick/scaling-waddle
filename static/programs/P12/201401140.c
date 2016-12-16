#include<stdio.h>
#define max 1000900
long long int a[max],b[max],end=0,count;
void push(long long int v)
{
	b[end]=v;
	end++;
}
void pop()
{
	if(end!=0)
		end--;
}
long long int top()
{
	if(end==0)
		return -1;
	return b[end-1];
}
long long int recur(long long int n)
{
	long long int i,j,g;
	for(i=0;i<n;i++)
	{
		g=top();
		if(a[i]<=a[g]||g==-1)
			push(i);
		else
		{
			while(a[i]>a[g] && g!=-1)
			{
				count+=n-i-1;
				pop();
				g=top();
			}
			push(i);
		}
		if(end>2)
		{
			g=top();
			j=end-2;
			while(a[g]>=a[b[j]] && j>=0)
			{
				j--;
			}
			if(j>=0)
				count+=j;

		}
	}
}
int main()
{
	long long int n,i;
	scanf("%lld",&n);
	while(n!=0)
	{
		long long int maxa=0;
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		end=0;
		count=0;
		recur(n);
		printf("%lld\n",count);
		scanf("%lld",&n);
	}
	return 0;
}
