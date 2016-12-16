#include<stdio.h>
long long stack[1000000];
long long a[1000000];
int main()
{
	stack[0]=0;
	a[0]=1000000000;
	while(1)
	{
		long long n,i,top=0,ans=0;
		scanf("%lld",&n);
		if(n==0)
			return 0;
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(i=1;i<=n;i++)
		{
			long long curpop=i,j;
//			if(i==n)
//				for(j=0;j<=top;j++)
//					printf("%d ",stack[j]);
			while(a[stack[top]]<=a[i])
			{
				ans=ans+(curpop-stack[top]-1);
				curpop=stack[top];
				top--;
			}
			ans=ans+(curpop-stack[top]-1);
			if(top!=0)
				ans=ans+stack[top]-1;
			top++;
			stack[top]=i;
			//printf("%d %d\n",i,ans);
		}
//		printf("%d\n",ans);
		top=0;
		for(i=1;i<=n;i++)
		{
			long long curpop=i,j;
//			for(j=0;j<=top;j++)
//				printf("%d ",stack[j]);
//			printf("\n");
			long long count=1;
			while(a[stack[top]]<a[i])
			{
				if(a[stack[top]]==a[curpop])
					count++;
				else
				{
					ans=ans-(count*(count-1))/2;
					count=1;
				}
				curpop=stack[top];
				top--;
			}
			ans=ans-(count*(count-1))/2;
			top++;
			stack[top]=i;
		}
		top++;
		stack[top]=0;
//		printf("%d\n",top);
		long long count=1;
		for(i=2;i<=top;i++)
		{
			if(a[stack[i]]==a[stack[i-1]])
				count++;
			else
			{
				if(count>=2)
					ans=ans-((count-1)*(count-2))/2;
				count=1;
			}
		}
//		ans=ans-(count*(count-1))/2;
		printf("%lld\n",ans);
	}
	return 0;
}
