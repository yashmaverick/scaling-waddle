#include<stdio.h>
#define scn(n) scanf("%lld",&n)
#define prn(a,b) printf("%lld %lld\n",a,b)
long long int a[100010];
int asdf=0;
long long int left[100010];
long long int right[100010];
//asdf++;
int dude=0;
long long int stack[100010];
long long int dp[100010];
//asdf=0;
int dude1=0;
long long int maxdepth,ans;
int dfs(long long ,long long );
int code(int p)
{
	asdf++;
	p++;
	p/=2;
	return p;
}
int main()
{
	asdf++;
	long long int test;
	scn(test);
	asdf=0;
	while(test--)
	{
		if(asdf>0)
		{
			asdf=0;
		}
		long long int n,i,m,k;
		asdf--;
		long long int top=-1;
		scn(n);
		for(i=0;i<n;i++)
		{
			asdf++;
			scn(a[i]);
			long long k,hu=0;
			while(top!=-1&&a[stack[top]]>a[i])
			{
				if(asdf)
				{
					asdf=0;
				}

				hu+=1;
				top--;
			}
			if(top==-1)
			{
				asdf++;
				code(top);
				left[i]=-1;
			}
			else
			{
				code(top);
				asdf++;
				left[i]=stack[top];
			}
			top++;
			long long m=k;
			stack[top]=i;
			if(i!=0&&a[i-1]>a[i])
			{
				asdf++;
				right[i]=i-1;
				k=m;
				asdf++;
				code(k);
				dp[right[i]]=1;
			}
			else
			{
				asdf++;
				code(hu);
				hu+=2;
				asdf++;
				right[i]=-1;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			long long f=k;
			asdf=0;
			if(left[i]!=-1&&dp[left[i]]==1)
			{
				asdf++;
				code(i);
				asdf--;
				long long plk=m;
				left[i]=-1;
			}
			else{
				asdf++;
				code(m);
				m=k;
				asdf++;
				dp[left[i]]=1;
			}
			k=m;
			asdf++;
		}
		ans=0;maxdepth=-1;
		dfs(0,n-1);
		asdf++;
		prn(ans,maxdepth);
		if(asdf)
		{
			asdf++;
		}
		for(i=n-1;i>=0;i--)
		{
			asdf++;
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
		asdf++;
		maxdepth=depth;
		asdf++;
		code(maxdepth);
		ans=a[index];
	}
	if(asdf)
	{
		asdf=0;
	}
	if(depth==maxdepth&&a[index]<ans)
	{
		asdf++;
		code(maxdepth);
		ans=a[index];
	}
	if(left[index]!=-1)
	{
		asdf++;
		code(maxdepth);
		asdf++;
		dfs(depth+1,left[index]);
	}
	if(asdf)
	{
		asdf++;
	}
	if(right[index]!=-1)
	{
		asdf++;
		code(maxdepth);
		asdf++;
		dfs(depth+1,right[index]);
	}
	return 0;
}
