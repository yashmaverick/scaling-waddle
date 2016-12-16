#include<stdio.h>
long long int a[100005],b[100005],c[100005],len=0,stk[100005];
void push(long long int x)
{
	stk[len++]=x;
	return ;
}
void pop()
{
	len--;
}
int isempty()
{
	if(len==0)
		return 1;
	else
		return 0;
}
long long int top()
{
	return stk[len-1];
}
int main()
{
	long long int n,i,ans=0;
	while(1)
	{
		len=0;
		ans=0;
		scanf("%lld",&n);
		if(n==0)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		b[0]=-1;
		push(0);
		for(i=1;i<n;i++)
		{
			while(!isempty() && a[top()]>=a[i])
				pop();
			if(isempty())
				b[i]=-1;
			else
				b[i]=top();
			push(i);
		}
		len=0;
		push(n-1);
		c[n-1]=n;
		for(i=n-2;i>=0;i--)
		{
			while(!isempty() && a[top()]>=a[i])
				pop();
			if(isempty())
				c[i]=n;
			else
				c[i]=top();
			push(i);
		}
		//	for(i=0;i<n;i++)
		//	{
		//		printf("%lld %lld\n",b[i],c[i]);
		//	}
		for(i=0;i<n;i++)
		{
			if(((c[i]-b[i]-1)*a[i])>ans)
				ans=((c[i]-b[i]-1)*a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
