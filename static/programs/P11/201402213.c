#include<stdio.h>
long long stack[1000001];
long long a[1000001];
long long area[1000001];
int main()
{
	while(1)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		long long int i,j,top=0;
		long long int ans=0;
		stack[0]=0;
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)
		{
			while(top!=0&&a[stack[top]]>=a[i])
				top--;
			area[i]=(i-1-stack[top])*a[i];
			top++;
			stack[top]=i;
		}
//		for(i=1;i<=n;i++)
//			printf("%lld ",area[i]);
		top=0;
		stack[0]=n+1;
		for(i=n;i>=1;i--)
		{
			while(top!=0&&a[stack[top]]>=a[i])
				top--;
			area[i]=area[i]+(stack[top]-1-i+1)*a[i];
			top++;
			stack[top]=i;
			if(area[i]>ans)
				ans=area[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
