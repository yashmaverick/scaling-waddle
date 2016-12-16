#include<stdio.h>

int A1[1020][1020]={0};
int A2[1020][1020]={0};
int vis[1020]={0};
int count=0;

int dfs(int x,int n,int a)
{
	int y;
	vis[x]=1;
	for(y=1;y<=n;y++)
	{
		if(a==1)
		{
			if(vis[y]!=1 && A1[x][y]==1)
			{
				count++;
				dfs(y,n,a);
			}
		}
		if(a==2)
		{
			if(vis[y]!=1 && A2[x][y]==2)
			{
				count++;
				dfs(y,n,a);
			}
		}
	}
	if(count==n-1)
	{
		return x;
	}
	else
	{
		return -1;
	}
}

int main()
{
	int i,j,n,x,d,a,z;
	scanf("%d",&x);
	while(x--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&d);
			while(d--)
			{
				scanf("%d",&a);
				A2[i][a]=2;
				A1[a][i]=1;
			}
		}
		for(j=1;j<=n;j++)
		{
			count=0;
			for(i=1;i<=n;i++)
			{
				vis[i]=0;
			}
			z=dfs(j,n,1);
			//	printf("z=%d j=%d\n",z,j);
			if(z!=-1)
			{
				break;
			}
		}
		count=0;
		if(z==-1)
		{
			printf("0\n");
		}
		else
		{
			for(i=1;i<=n;i++)
			{
				vis[i]=0;
			}
			z=dfs(z,n,2);
			printf("%d\n",count+1);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				A1[i][j]=0;
				A2[i][j]=0;
			}
		}
	}
	return 0;
}
