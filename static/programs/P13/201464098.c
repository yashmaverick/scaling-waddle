#include<stdio.h>
long long int top;
int main()
{
	long long int test,g;
	scanf("%lld",&test);
	for(g=0;g<test;g++)
	{
		long long int n,i;
		scanf("%lld",&n);
		long long int s[n],a[n];
		long long int j=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&s[i]);
			a[n-1-i]=s[i];
		}
		long long int stack[n],ans[n];
		stack[0]=0;
		ans[0]=0;
		long long int top=0;
		for(i=1;i<n;i++)
		{
			long long int count=0;
			if(a[i]>a[stack[top]])
			{
				top++;
				stack[top]=i;
				ans[i]=ans[i-1]+1;
			}
			else
			{
				while(top!=-1 && a[i]<a[stack[top]])
				{
					count=ans[stack[top]]+1;
					top--;

				}
				ans[i]=count;
				top++;
				stack[top]=i;
			}
		}
		long long int max=0,love=999999;
		for(i=0;i<n;i++)
		{
			if(ans[i]>max)
			{	
				max=ans[i];
				love=a[i];
			}
			else if(ans[i]==max)
				{
					if(love > a[i])
						love=a[i];
				}
		}
		printf("%lld %lld\n",love,max);
	}
	return 0;
}