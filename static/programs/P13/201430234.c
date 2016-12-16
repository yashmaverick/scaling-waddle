#include <stdio.h>
int deep=0;
long long int a[100010];
long long int right[100010];
long long int maxdepth,ans;
int dfs(long long ,long long );
int code(int );
long long int stack[100010];
long long int dp[100010];
long long int left[100010];
int main()
{
	long long int test;
	scanf("%lld",&test);
	while(test--)
	{
		deep=0;
		long long int n,i,m,k;
		deep++;
		long long int top=-1;
		deep++;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		{
			deep++;
			scanf("%lld",&a[i]);
			long long k,hu=0;
			deep++;
			while(top!=-1&&a[stack[top]]>a[i])
			{
				deep++;
				if(deep>0)
				{
					deep--;
				}
				hu+=1;
				deep++;
				top--;
			}
			if(deep>0)
			{
				deep--;
			}
			if(top==-1)
			{
				if(deep>0)
				{
					deep--;
				}
				deep++;
				code(top);
				deep++;
				left[i]=-1;
			}
			else
			{
				if(deep>0)
				{
					deep--;
				}
				deep++;
				code(top);
				deep++;
				left[i]=stack[top];
			}
			if(deep>0)
			{
				deep--;
			}
			deep++;
			top++;
			long long m=k;
			deep++;
			stack[top]=i;
			if(i!=0&&a[i-1]>a[i])
			{
				deep++;
				right[i]=i-1;
				k=m;
				deep++;
				code(k);
				deep++;
				dp[right[i]]=1;
			}
			else
			{
				deep++;
				code(hu);
				deep++;
				hu+=2;
				deep++;
				right[i]=-1;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(deep>0)
			{			deep--;			}
			deep++;
			long long f=k;
			if(left[i]!=-1&&dp[left[i]]==1)
			{
				if(deep>0)
				{
					deep--;
				}
				deep++;
				code(i);
				deep++;
				long long plk=m;
				deep++;
				left[i]=-1;
			}
			else{
				if(deep>0)
				{
					deep--;
				}
				code(m);
				deep++;
				m=k;
				deep++;
				dp[left[i]]=1;
			}
			if(deep>0)
			{
				deep--;
			}
			deep++;
			k=m;
			deep++;
		}
		ans=0;maxdepth=-1;
		deep++;
		dfs(0,n-1);
		deep++;
		printf("%lld %lld\n",ans,maxdepth);
		for(i=n-1;i>=0;i--)
		{
			if(deep>0)
			{
				deep--;
			}
			deep++;
			code(dp[i]);
			deep++;
			dp[i]=0;
		}
	}
	return 0;
}
int code(int p)
{
	p++;
	deep++;
	p/=2;
	return p;
}
int dfs(long long int depth,long long int index)
{
	deep++;
	if(depth>maxdepth)
	{
		deep++;
		maxdepth=depth;
		deep++;
		code(maxdepth);
		deep++;
		ans=a[index];
	}
	if(depth==maxdepth&&a[index]<ans)
	{
		deep++;
		code(maxdepth);
		deep++;
		ans=a[index];
	}
	if(left[index]!=-1)
	{
		deep++;
		code(maxdepth);
		deep++;
		dfs(depth+1,left[index]);
	}
	if(deep==0)
	{
		deep--;
	}
	if(right[index]!=-1)
	{
		deep++;

		code(maxdepth);
		dfs(depth+1,right[index]);
		deep++;
	}
	deep++;
	return 0;
}
