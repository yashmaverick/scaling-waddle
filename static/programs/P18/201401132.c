#include<stdio.h>
int a[1004][1004];
int b[1004]={0};
int c[1004][1004];
void dfs(int a1,int n)
{
	int i;
	b[a1]=1;
	for(i=1;i<=n;i++)
	{
		if(a[a1][i]==1)
		{
			if(b[i]==0)
			{
				dfs(i,n);
			}
		}
	}
	return;
}
void rdfs(int a1,int n)
{
	int i;
	b[a1]=1;
	for(i=1;i<=n;i++)
	{
		if(a[i][a1]==1)
		{
			if(b[i]==0)
			{
				rdfs(i,n);
			}
		}
	}
	return;
}
int main()
{
	int ng,nv,nav,v,av,i,j,n,g,flag,y;
	scanf("%d",&ng);
	while(ng--)
	{
		scanf("%d",&nv);
		n=nv;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]=0;
				c[i][j]=0;
				b[i]=0;
			}

		}
		v=0;
		while(nv--)
		{
			v++;
			scanf("%d",&nav);
			while(nav--)
			{
				scanf("%d",&av);
				a[av][v]=1;
				c[v][av]=1;
			}
		}
		//	for(i=1;i<=n;i++){
		//		for(j=1;j<=n;j++){
		//			printf("%d ",a[i][j]);
		//		}
		//		printf("\n");
		//	}
		int x=0,z;flag=0;
		for(j=1;j<=n;j++)
		{
			dfs(j,n);
			//	for(i=1;i<=n;i++){
			//		printf("%d ",b[i]);
			//	}
			//	printf("*\n");
			z=0;
			for(i=1;i<=n;i++)
			{
				if(b[i]==1)
				{
					z++;
				}
				if(z==n)
				{
					flag=1;
					y=j;
				}
			}
			for(i=1;i<=n;i++)
			{
				b[i]=0;
			}
			if(flag==1)
			{
				break;
			}

		}
		if(flag==1)
		{
			rdfs(y,n);
			for(i=1;i<=n;i++)
			{
				if(b[i]==1)
				{
					x++;
				}
			}
		}
		printf("%d\n",x);

	}
	return 0;
}














