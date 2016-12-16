#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int pos[1000001];
int prepos[1000001];
int pre[1000001];
int left[1000001];
int right[1000001];
int parents[1000001];
int dp[1000001];
int stack[1000001];
int main()
{
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
		prepos[pre[i]]=i;
	}
	parents[0]=-1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		pos[x]=i;
	}
	int top=-1;
	for(i=n-1;i>=0;i--)
	{
		while(top!=-1&&pos[pre[stack[top]]]<pos[pre[i]])
			top--;
		if(top==-1)
			right[i]=-1;
		else
		{
			right[i]=stack[top];
			parents[stack[top]]=i;
		}
		top++;
		stack[top]=i;
		if(i!=n-1&&pos[pre[i+1]]<pos[pre[i]])
		{
			left[i]=i+1;
			parents[i+1]=i;
			dp[left[i]]=1;
		}
		else
			left[i]=-1;
	}
	for(i=0;i<n;i++)
		if(right[i]!=-1&&dp[right[i]]==1)
			right[i]=-1;
		else
		{
			parents[right[i]]=i;
			dp[right[i]]=1;
		}
	int q;
	scanf("%d",&q);
	for(i=1;i<=n;i++)
		dp[i]=0;
	while(q--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		int p=prepos[l];
		while(p!=-1)
		{
			dp[p]=1;
			p=parents[p];
		}
		p=prepos[r];
		while(dp[p]!=1)
			p=parents[p];
		printf("%d\n",pre[p]);
		p=prepos[l];
		while(p!=-1)
		{
			dp[p]=0;
			p=parents[p];
		}
	}
	return 0;
}
