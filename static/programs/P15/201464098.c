#include<stdio.h>
int main()
{
	long long int test;
	scanf("%lld",&test);
	long long int i,g,n,k;
	for(g=0;g<test;g++)
	{
		long long int top=-1;
		scanf("%lld %lld",&n,&k);
		long long int a[n],stack[n];
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
		top++;
		stack[top]=0;
		for(i=1;i<k;i++)
		{
			if(a[i]>a[stack[top]])
			{
				top++;
				stack[top]=i;
			}
			else
			{
				while(top!=-1 && a[i]<a[stack[top]])
				{
					top--;
				}
				top++;
				stack[top]=i;
			}
		}
		long long int ans[n];
		long long int ss=0;
		ans[ss]=a[stack[0]];
		ss++;
		for(i=k;i<n;i++)
		{
			long long int j=0;
			if(a[stack[top]] < a[i])
			{
				top++;
				stack[top]=i;
			}
			else
			{
				while(top!=-1 && a[stack[top]] > a[i])
				{
					top--;
				}
				top++;
				stack[top]=i;
			}
			while(stack[j] < ss)
			{
				j++;
			}
			ans[ss]=a[stack[j]];
			ss++;
		}
		for(i=0;i<ss-1;i++)
			printf("%lld ",ans[i]);
		//printf("\b\n");
		printf("%lld\n",ans[ss-1]);
	}
	return 0;
}