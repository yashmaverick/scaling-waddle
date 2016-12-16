#include<stdio.h>
int a[1001][1001]={0},c[1001][1001]={0},d[1001]={0};
int ans,find=0;
int count,n;

void dfs(int node)
{
	int i;
	d[node]=1;
//	printf("%d\n",node);
	for(i=0;i<n;i++)
	{
		if(a[node][i]==1)
		{
			if(d[i]==0)
			{
				count++;
				dfs(i);
			}
		}
	}
	if(count==n-1)
		find=1;
}

int dfs1(int node)
{
	int i;
	d[node]=1;
	for(i=0;i<n;i++)
	{
		if(c[node][i]==1)
		{
			if(d[i]==0)
			{
				ans++;
				dfs1(i);
			}
		}
	}
}

int main()
{
	int t,h;
	scanf("%d",&t);
	for(h=0;h<t;h++)
	{
		count=0;
		ans=1;
		find=0;
		int t,j,tem,i,flag=0;
		scanf("%d",&n);
		int b;
		for(i=0;i<n;i++)
		{
			scanf("%d",&b);
			for(j=0;j<b;j++)
			{
				scanf("%d",&tem);
				c[i][tem-1]=1;
				a[tem-1][i]=1;
			}
		}
//		for(i=0;i<n;i++)
//		{
//			for(j=0;j<n;j++)
//				printf("%d ",c[i][j]);
//			printf("\n");
//		}
		for(i=0;i<n;i++)
		{
			count=0;
			dfs(i);
			if(find==1)
				break;
			if(i==n-1)
			{
				printf("0\n");
				flag=1;
				break;
			}
			count=0;
			for(j=0;j<n;j++)
				d[j]=0;
		}
		if(flag==1)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					c[i][j]=0;
					a[i][j]=0;
				}
			}
		}	
		int k;
		for(k=0;k<n;k++)
			d[k]=0;
		if(flag==1)
			continue;
		ans=1;
//		printf("%d\n",i);
		dfs1(i);
		printf("%d\n",ans);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				c[i][j]=0;
				a[i][j]=0;
			}
			d[i]=0;
		}
	}
	return 0;
}
