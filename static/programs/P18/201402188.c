#include <stdio.h>
int count=0,count1=0,flag[1010]={0},n,flag2[1010]={0};
int a[1010][1010]={0};
void dfs(int m)
{
	int i;
	count++;
	flag[m]=1;
	for(i=1;i<=n;i++)
	{
		if(a[m][i]==1 && flag[i]==0)
		{
			dfs(i);
		}
	}
}

void dfs2(int m)
{
	int i;
	count1++;
	//printf("w:%d\n",m);
	flag2[m]=1;
	for(i=1;i<=n;i++)
	{
		if(a[i][m]==1 && flag2[i]==0)
		{
			dfs2(i);
		}
	}
}

void blank()
{
	int i,j;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			a[i][j]=0;
		}
	}
}


void flagg()
{
	int i;
	for(i=0;i<=n;i++)
	{
		flag[i]=0;
	}

}

void flagg2()
{
	int i;
	for(i=0;i<=n;i++)
	{
		flag2[i]=0;
	}
}




int main()
{
	int jaa,test;
	scanf("%d",&test);
	for(jaa=0;jaa<test;jaa++)
	{
		int w,q;
		int i;
		count1=0;count=0;
		
		int j,r,t;
		scanf("%d",&n);
		blank();
		for(i=0;i<=n;i++)
		{
			flag[i]=0;
			flag2[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&t);
			for(j=1;j<=t;j++)
			{
				scanf("%d",&r);
				a[r][i]=1;
			}
		}
		int fl=0;
		for(i=1;i<=n;i++)
		{
			dfs(i);
			if(count==n)
			{
				fl=1;
				break;
			}
			else
			{
				count=0;
				flagg();
			}		
		}
		if(fl==1)
		{
			dfs2(i);
			printf("%d\n",count1 );
		}
		else
			printf("0\n");
	}
	return 0;
}
