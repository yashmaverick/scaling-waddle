#include<stdio.h>
#define scn(n) scanf("%lld",&n)
int depthoff=0;
#define prn(a,b) printf("%lld %lld\n",a,b)
long long int a[100010];
int height=0;
long long int left[100010];
int height3=0;
long long int right[100010];
int height1=0;
long long int stack[100010];
long long int dp[100010];
int height2=0;
long long int maxdepth,ans;
int code(int p)
{
	height++;
	p++;
	height2++;
	p/=2;
	return p;
}

int dfs(long long ,long long );
int main()
{
	height2++;
	long long int test;
	scn(test);
	if(height2==0)
	{
		height1=0;
		height++;
	}
	while(test--)
	{
		if(height==0)
		{
			height2=0;
		}
		long long int n,i,m,k;
		height2++;
		long long int top=-1;
		scn(n);
		height2++;
		for(i=0;i<n;i++)
		{
			height2++;
			scn(a[i]);
			height++;
			long long k,hu=0;
			while(top!=-1&&a[stack[top]]>a[i])
			{
				height2++;
				hu+=1;
				height++;
				top--;
			}
			if(top==-1)
			{
				height++;
				code(top);
				height1++;
				left[i]=-1;
			}
			else
			{
				height++;
				code(top);
				height2++;
				left[i]=stack[top];
			}
			height2++;
			top++;
			long long m=k;
			stack[top]=i;
			height2++;
			if(i!=0&&a[i-1]>a[i])
			{
				height++;
				right[i]=i-1;
				k=m;
				height2=0;
				code(k);
				dp[right[i]]=1;
			}
			else
			{
				height2++;
				code(hu);
				height=0;
				hu+=2;
				right[i]=-1;
			}
			height2++;
			height++;
		}
		for(i=n-1;i>=0;i--)
		{
			height++;
			long long f=k;
			if(left[i]!=-1&&dp[left[i]]==1)
			{
				height2++;
				code(i);
				long long plk=m;
				height2++;
				left[i]=-1;
			}
			else
			{
				//height++;
				code(m);
				m=k;
				height2++;
				dp[left[i]]=1;
			}
			height++;
			k=m;
		}
		height++;
		ans=0;maxdepth=-1;
		dfs(0,n-1);
		height2++;
		prn(ans,maxdepth);
		for(i=n-1;i>=0;i--)
		{
			height++;
			code(dp[i]);
			height1++;
			dp[i]=0;
		}
		height1=0;
	}
	return 0;
}
int dfs(long long int depth,long long int index)
{
	if(height==0)
	{
		height2++;
	}
	height1++;
	if(depth>maxdepth)
	{
		depthoff++;
		maxdepth=depth;
		code(maxdepth);
		depthoff=0;
		ans=a[index];
	}
	if(depth==maxdepth&&a[index]<ans)
	{
		depthoff++;
		code(maxdepth);
		depthoff=0;
		ans=a[index];
	}
	if(left[index]!=-1)
	{
		depthoff++;
		code(maxdepth);
		depthoff=0;
		dfs(depth+1,left[index]);
	}
	if(right[index]!=-1)
	{
		depthoff=0;
		code(maxdepth);
		depthoff++;
		dfs(depth+1,right[index]);
	}
	height++;
	return 0;
}
