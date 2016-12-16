#include<stdio.h>
int main()
{
	int n,i,j,k,st=0;
	scanf("%d",&n);
	int pre[100001];
	int in[100001];
	for(i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(j=0;j<n;j++)
		scanf("%d",&in[j]);
	int t,l;
	int p1,p2;
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		int ans=n+1;
		int a,b;
		int c[100001];
		scanf("%d%d",&a,&b);
		st=0;
		for(i=0;i<n;i++)
		{
			if(in[i]==a)
				p1=i;
			if(in[i]==b)
				p2=i;
		}
		
		if(a==b)
		{
			printf("%d\n",a);
			continue;
		}
		if(a==pre[0] || b==pre[0])
		{
			printf("%d\n",pre[0]);
			continue;
		}	
		if(p2 > p1)
		{
			i=0;
			for(j=p1;j<=p2;j++)
			{
				c[i]=in[j];
				i=i+1;
			}
			l=0;
			for(j=0;j<n;j++)
			{
				for(l=0;l<i;l++)
				
				{
					if(pre[j]==c[l])
					{
						ans=j;
					st=1;
					break;
					}
					}
				if(st==1)
					break;
			}
		}
		else if(p1 > p2)
		{
			i=0;
			for(j=p2;j<=p1;j++)
			{
				c[i]=in[j];
				i=i+1;
			}
			l=0;
			for(j=0;j<n;j++)
			{
				for(l=0;l<i;l++)
				{
					if(pre[j]==c[l])
				{
					ans=j;
					st=1;
					
					break;
				}
				}
				if(st==1)
					break;
			}
		}
		printf("%d\n",pre[ans]);
	}
	return 0;
}
