#include<stdio.h>
int main()
{
	int pre[100000],in[100000],t,n,i,j,l,start=0,flag=0,end=0,m,k,x,y,vv;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&pre[i]);
	}
	for(j=0;j<n;j++)
	{
		scanf("%d",&in[j]);
	}
	scanf("%d",&t);
	for(k=0;k<t;k++)
	{
		scanf("%d%d",&x,&y);
		start=0;
		end=n-1;
		for(l=0;l<n;l++)
		{
			if(in[l]==x)
			{
				start=l;
			}
			if(in[l]==y)
			{
				end=l;
			}
		}
		if(start>end)
		{
			int v;
			v=start;
			start=end;
			end=v;
		}
		for(m=0;m<n;m++)
		{
			int hhi,bye;
			int xx,yy;
			yy=m;
			hhi=start;
			bye=end;
			vv=0;
			while(hhi<=bye)
			{
				if(in[hhi]==pre[yy])
				{
					printf("%d\n",pre[m]);
					vv=1;
					break;
				}
				hhi++;
			}
			if(vv)
			{
				break;
			}
		}
	}
	return 0;
}
