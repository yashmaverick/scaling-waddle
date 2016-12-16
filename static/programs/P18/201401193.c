#include<stdio.h>
#include<string.h>
int n,c[1005],a[1005][1005],co,vi[1005],ch[1005];
void func(int k)
{
	int i;
	for(i=0;i<c[k-1];i++)
	{
		if(co==n-1)
			return;
		if(vi[a[k-1][i]-1]==0)
		{
			if(ch[a[k-1][i]-1]==1)
				co=n-2;
			co++;
			if(co==n-1)
				return;
			vi[a[k-1][i]-1]=1;
			func(a[k-1][i]);
		}
	}
	return;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int i,j,ans=0,x,y;
		scanf("%d",&n);
		memset(c,0,n*sizeof(c[0]));
		memset(ch,0,n*sizeof(ch[0]));
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			while(x--)
			{
				scanf("%d",&y);
				a[y-1][c[y-1]]=i+1;
				c[y-1]++;
			}
		}
		for(i=0;i<n;i++)
		{
			co=0;
			memset(vi,0,n*sizeof(vi[0]));
			vi[i]=1;
			func(i+1);
			if(co==n-1)
			{
				ans++;
				ch[i]=1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
