#include<stdio.h>
#define scn(n) scanf("%lld",&n)
#define prn(a,b) printf("%lld %lld\n",a,b)
long long int a[100010];
long long int left[100010];
long long int right[100010];
long long int stack[100010];
long long int dp[100010];
long long int maxdepth,ans;
int dfs(long long ,long long );
int code(int p)
{
	p++;
	p/=2;
	return p;
}
int main()
{
	long long int test;
	scn(test);
	while(test--)
	{
		long long int n,i,m,k;
		long long int top=-1;
		scn(n);
		for(i=0;i<n;i++)
		{
			scn(a[i]);
			long long k,hu=0;
			while(top!=-1&&a[stack[top]]>a[i])
			{
				hu+=1;
				top--;
			}
			if(top==-1)
			{
				code(top);
				left[i]=-1;
			}
			else
			{
				code(top);
				left[i]=stack[top];
			}
			top++;
			long long m=k;
			stack[top]=i;
			if(i!=0&&a[i-1]>a[i])
			{
				right[i]=i-1;
				k=m;
				code(k);
				dp[right[i]]=1;
			}
			else
			{
				code(hu);
				hu+=2;
				right[i]=-1;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			long long f=k;
			if(left[i]!=-1&&dp[left[i]]==1)
			{
				code(i);
				long long plk=m;
				left[i]=-1;
			}
			else{
				code(m);
				m=k;
				dp[left[i]]=1;
			}
			k=m;
		}
		ans=0;maxdepth=-1;
		dfs(0,n-1);
		prn(ans,maxdepth);
		for(i=n-1;i>=0;i--)
		{
			code(dp[i]);
			dp[i]=0;
		}
	}
	return 0;
}
int dfs(long long int depth,long long int index)
{
	if(depth>maxdepth)
	{
		maxdepth=depth;
		code(maxdepth);
		ans=a[index];
	}
	if(depth==maxdepth&&a[index]<ans)
	{
		code(maxdepth);
		ans=a[index];
	}
	if(left[index]!=-1)
	{
		code(maxdepth);
		dfs(depth+1,left[index]);
	}
	if(right[index]!=-1)
	{
		code(maxdepth);
		dfs(depth+1,right[index]);
	}
	return 0;
}
