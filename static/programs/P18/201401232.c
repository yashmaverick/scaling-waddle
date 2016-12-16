#include<stdio.h>
int a[1001][1001],b[1001][1001];
int vis[1001];
int tmp;
void dfs(int k,int bb,int *vis)
{
	int i,j;
	vis[k]=1;
	//	printf("%d ",k);
	for(i=1;i<=bb;i++)
	{
		if(a[k][i]==1 && vis[i]!=1)
		{
			tmp++;
			dfs(i,bb,vis);
		}
	}
}
void dfs1(int k,int bb,int *vis)
{
	int i,j;
	vis[k]=1;
	//	printf("%d ",k);
	for(i=1;i<=bb;i++)
	{
		if(b[k][i]==1 && vis[i]!=1)
		{
			tmp++;
			dfs1(i,bb,vis);
		}
	}
}
int main()
{
	int aa,bb,cc,dd,ee,ff,gg,hh,jj,kk,ll,mm,nn,ans;
	scanf("%d",&aa);
	while(aa--)
	{
		scanf("%d",&bb);
		for(cc=1;cc<=bb;cc++)
		{
			for(dd=1;dd<=bb;dd++)
			{
				a[cc][dd]=0;
				b[cc][dd]=0;
			}
		}
		for(cc=1;cc<=bb;cc++)
		{
			scanf("%d",&ee);
			for(dd=0;dd<ee;dd++)
			{
				scanf("%d",&ff);
				a[ff][cc]=1;
				b[cc][ff]=1;
			}
		}
		ans=0;
		for(cc=1;cc<=bb;cc++)
		{
			for(ee=1;ee<=bb;ee++)
				vis[ee]=0;
			tmp=1;
			//	if(count[cc]==bb-1)
			//		cc++;
			//	else if(count[cc]==0)
			//	{
			//		ans++;
			//		cc++;
			//	}
			//	printf("ss");
			dfs(cc,bb,vis);
			if(tmp==bb)
			{
				nn=cc;
				ans++;
				break;
			}
		}
		for(ee=1;ee<=bb;ee++)
		{
			vis[ee]=0;
		}
		tmp=0;
		if(cc!=bb+1)
		{
			dfs1(nn,bb,vis);
			tmp=tmp+1;
		}
		printf("%d\n",tmp);
	}
	return 0;
}
